/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/mpconfig.h"
#include "py/misc.h"
#include "py/mphal.h"
#include "flash.h"

#if MICROPY_HW_STM32WB_FLASH_SYNCRONISATION
// See WB55 specific documentation in AN5289 Rev 3, and in particular, Figure 10.

//YP #include "rfcore.h"
//YP #include "stm32wbxx_ll_hsem.h"

// Protects all flash registers.
#define SEMID_FLASH_REGISTERS (2)
// Used by CPU1 to prevent CPU2 from writing/erasing data in flash memory.
#define SEMID_FLASH_CPU1 (6)
// Used by CPU2 to prevent CPU1 from writing/erasing data in flash memory.
#define SEMID_FLASH_CPU2 (7)

#endif

typedef struct {
    uint32_t base_address;
    uint32_t sector_size;
    uint32_t sector_count;
} flash_layout_t;

#if defined(STM32F0)

static const flash_layout_t flash_layout[] = {
    { FLASH_BASE, FLASH_PAGE_SIZE, (FLASH_BANK1_END + 1 - FLASH_BASE) / FLASH_PAGE_SIZE },
};

#elif defined(STM32F4)

static const flash_layout_t flash_layout[] = {
    { 0x08000000, 0x04000, 4 },
    { 0x08010000, 0x10000, 1 },
    { 0x08020000, 0x20000, 3 },
    #if defined(FLASH_SECTOR_8)
    { 0x08080000, 0x20000, 4 },
    #endif
    #if defined(FLASH_SECTOR_12)
    { 0x08100000, 0x04000, 4 },
    { 0x08110000, 0x10000, 1 },
    { 0x08120000, 0x20000, 7 },
    #endif
};

#elif defined(STM32F7)

// FLASH_FLAG_PGSERR (Programming Sequence Error) was renamed to
// FLASH_FLAG_ERSERR (Erasing Sequence Error) in STM32F7
#define FLASH_FLAG_PGSERR FLASH_FLAG_ERSERR

#if defined(STM32F722xx) || defined(STM32F723xx) || defined(STM32F732xx) || defined(STM32F733xx)
static const flash_layout_t flash_layout[] = {
    { 0x08000000, 0x04000, 4 },
    { 0x08010000, 0x10000, 1 },
    { 0x08020000, 0x20000, 3 },
};
#else
// This is for dual-bank mode disabled
static const flash_layout_t flash_layout[] = {
    { 0x08000000, 0x08000, 4 },
    { 0x08020000, 0x20000, 1 },
    #if FLASH_SECTOR_TOTAL == 8
    { 0x08040000, 0x40000, 3 },
    #else
    { 0x08040000, 0x40000, 7 },
    #endif
};
#endif

#elif defined(STM32L0) || defined(STM32L4) || defined(STM32WB)

static const flash_layout_t flash_layout[] = {
    { (uint32_t)FLASH_BASE, (uint32_t)FLASH_PAGE_SIZE, 512 },
};

#elif defined(STM32H7)

static const flash_layout_t flash_layout[] = {
    { 0x08000000, 0x20000, 16 },
};

#else
//YP #error Unsupported processor added for dummy
static const flash_layout_t flash_layout[] = {
    { 0xAF000000, 0x1000, 32},
};
#endif

#if (defined(STM32L4) && defined(SYSCFG_MEMRMP_FB_MODE)) || defined(STM32H7)

// get the bank of a given flash address
static uint32_t get_bank(uint32_t addr) {
    #if defined(STM32H7)
    if (READ_BIT(FLASH->OPTCR, FLASH_OPTCR_SWAP_BANK) == 0) {
    #else
    if (READ_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_FB_MODE) == 0) {
        #endif
        // no bank swap
        if (addr < (FLASH_BASE + FLASH_BANK_SIZE)) {
            return FLASH_BANK_1;
        } else {
            return FLASH_BANK_2;
        }
    } else {
        // bank swap
        if (addr < (FLASH_BASE + FLASH_BANK_SIZE)) {
            return FLASH_BANK_2;
        } else {
            return FLASH_BANK_1;
        }
    }
}

#if (defined(STM32L4) && defined(SYSCFG_MEMRMP_FB_MODE))
// get the page of a given flash address
static uint32_t get_page(uint32_t addr) {
    if (addr < (FLASH_BASE + FLASH_BANK_SIZE)) {
        // bank 1
        return (addr - FLASH_BASE) / FLASH_PAGE_SIZE;
    } else {
        // bank 2
        return (addr - (FLASH_BASE + FLASH_BANK_SIZE)) / FLASH_PAGE_SIZE;
    }
}
#endif

#else //yp #elif (defined(STM32L4) && !defined(SYSCFG_MEMRMP_FB_MODE)) || defined(STM32WB)

static uint32_t get_page(uint32_t addr) {
#if 0
    return (addr - FLASH_BASE) / FLASH_PAGE_SIZE;
#endif
}

#endif

bool flash_is_valid_addr(uint32_t addr) {
    uint8_t last = MP_ARRAY_SIZE(flash_layout) - 1;
    uint32_t end_of_flash = flash_layout[last].base_address +
        flash_layout[last].sector_count * flash_layout[last].sector_size;
    return flash_layout[0].base_address <= addr && addr < end_of_flash;
}

int32_t flash_get_sector_info(uint32_t addr, uint32_t *start_addr, uint32_t *size) {
    if (addr >= flash_layout[0].base_address) {
        uint32_t sector_index = 0;
        for (int i = 0; i < MP_ARRAY_SIZE(flash_layout); ++i) {
            for (int j = 0; j < flash_layout[i].sector_count; ++j) {
                uint32_t sector_start_next = flash_layout[i].base_address
                    + (j + 1) * flash_layout[i].sector_size;
                if (addr < sector_start_next) {
                    if (start_addr != NULL) {
                        *start_addr = flash_layout[i].base_address
                            + j * flash_layout[i].sector_size;
                    }
                    if (size != NULL) {
                        *size = flash_layout[i].sector_size;
                    }
                    return sector_index;
                }
                ++sector_index;
            }
        }
    }
    return -1;
}

int flash_erase(uint32_t flash_dest, uint32_t num_word32) {

    // check there is something to write
    if (num_word32 == 0) {
        return 0;
    }
	
   	uint32_t status = 0; //OK
	uint32_t Sector,NbSectors;

	Sector    = flash_get_sector_info(flash_dest, NULL, NULL);
    NbSectors = flash_get_sector_info(flash_dest + 4 * num_word32 - 1, NULL, NULL) - Sector + 1;

	//Call the erase function from the IFX iLLD
	py_tc397_erase_dflash(Sector,NbSectors);

    return 0;//YP mp_hal_status_to_neg_errno(status);
}

/*
// erase the sector using an interrupt
void flash_erase_it(uint32_t flash_dest, uint32_t num_word32) {
    // check there is something to write
    if (num_word32 == 0) {
        return;
    }

    // unlock
    HAL_FLASH_Unlock();

    // Clear pending flags (if any)
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                           FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);

    // erase the sector(s)
    FLASH_EraseInitTypeDef EraseInitStruct;
    EraseInitStruct.TypeErase = TYPEERASE_SECTORS;
    EraseInitStruct.VoltageRange = VOLTAGE_RANGE_3; // voltage range needs to be 2.7V to 3.6V
    EraseInitStruct.Sector = flash_get_sector_info(flash_dest, NULL, NULL);
    EraseInitStruct.NbSectors = flash_get_sector_info(flash_dest + 4 * num_word32 - 1, NULL, NULL) - EraseInitStruct.Sector + 1;
    if (HAL_FLASHEx_Erase_IT(&EraseInitStruct) != HAL_OK) {
        // error occurred during sector erase
        HAL_FLASH_Lock(); // lock the flash
        return;
    }
}
*/

int flash_write(uint32_t flash_dest, const uint32_t *src, uint32_t num_word32) {

    uint32_t sub_flash_dest = flash_dest;

    // program the flash uint64 by uint64
    for (int i = 0; i < num_word32 / 2; i++) 
	{
        uint32_t wordL = *src++;
		uint32_t wordU = *src++;
		py_tc397_programme_dflash(sub_flash_dest,wordL,wordU);

		sub_flash_dest += 8;
    }
    return 0;
}

/*
 use erase, then write
void flash_erase_and_write(uint32_t flash_dest, const uint32_t *src, uint32_t num_word32) {
    // check there is something to write
    if (num_word32 == 0) {
        return;
    }

    // unlock
    HAL_FLASH_Unlock();

    // Clear pending flags (if any)
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                           FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);

    // erase the sector(s)
    FLASH_EraseInitTypeDef EraseInitStruct;
    EraseInitStruct.TypeErase = TYPEERASE_SECTORS;
    EraseInitStruct.VoltageRange = VOLTAGE_RANGE_3; // voltage range needs to be 2.7V to 3.6V
    EraseInitStruct.Sector = flash_get_sector_info(flash_dest, NULL, NULL);
    EraseInitStruct.NbSectors = flash_get_sector_info(flash_dest + 4 * num_word32 - 1, NULL, NULL) - EraseInitStruct.Sector + 1;
    uint32_t SectorError = 0;
    if (HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError) != HAL_OK) {
        // error occurred during sector erase
        HAL_FLASH_Lock(); // lock the flash
        return;
    }

    // program the flash word by word
    for (int i = 0; i < num_word32; i++) {
        if (HAL_FLASH_Program(TYPEPROGRAM_WORD, flash_dest, *src) != HAL_OK) {
            // error occurred during flash write
            HAL_FLASH_Lock(); // lock the flash
            return;
        }
        flash_dest += 4;
        src += 1;
    }

    // lock the flash
    HAL_FLASH_Lock();
}
*/

//Test the flash API
unsigned char writearray[] = 
{
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,	
};

void dflash_test(void)
{
  flash_erase(0xAF000000, 0x20/4);
  flash_write(0xAF000000, writearray,0x20/4);
}

