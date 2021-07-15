
// Whether to include the pyb module
#ifndef MICROPY_PY_PYB
#define MICROPY_PY_PYB (1)
#endif
// Whether to automatically mount (and boot from) the flash filesystem
#ifndef MICROPY_HW_FLASH_MOUNT_AT_BOOT
#define MICROPY_HW_FLASH_MOUNT_AT_BOOT (MICROPY_HW_ENABLE_STORAGE)
#endif

// The volume label used when creating the flash filesystem
#ifndef MICROPY_HW_FLASH_FS_LABEL
#define MICROPY_HW_FLASH_FS_LABEL "pybflash"
#endif

// Whether to enable the ADC peripheral, exposed as pyb.ADC and pyb.ADCAll
#ifndef MICROPY_HW_ENABLE_ADC
#define MICROPY_HW_ENABLE_ADC (1)
#endif

// Whether to enable storage on the internal flash of the MCU
#ifndef MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)
#endif

// Enable CAN if there are any peripherals defined
#if defined(MICROPY_HW_CAN1_TX)
#define MICROPY_HW_ENABLE_CAN (1)
#endif

#if MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE
// Provide block device macros if internal flash storage is enabled
#define MICROPY_HW_BDEV_IOCTL flash_bdev_ioctl
#define MICROPY_HW_BDEV_READBLOCK flash_bdev_readblock
#define MICROPY_HW_BDEV_WRITEBLOCK flash_bdev_writeblock
#endif

// Enable the storage sub-system if a block device is defined
#if defined(MICROPY_HW_BDEV_IOCTL)
#define MICROPY_HW_ENABLE_STORAGE (1)
#else
#define MICROPY_HW_ENABLE_STORAGE (0)
#endif

// Function to determine if the given can_id is reserved for system use or not.
#ifndef MICROPY_HW_CAN_IS_RESERVED
#define MICROPY_HW_CAN_IS_RESERVED(can_id) (false)
#endif

#if defined(MICROPY_HW_CAN3_TX)
#define MICROPY_HW_MAX_CAN (3)
#elif defined(MICROPY_HW_CAN2_TX)
#define MICROPY_HW_MAX_CAN (2)
#elif defined(MICROPY_HW_CAN1_TX)
#define MICROPY_HW_MAX_CAN (1)
#endif

// Pin definition header file
#define MICROPY_PIN_DEFS_PORT_H "pin_defs_aurix.h"

//Define the register address of the MCU chip ID
#define MP_HAL_UNIQUE_ID_ADDRESS (0xf0036140)
