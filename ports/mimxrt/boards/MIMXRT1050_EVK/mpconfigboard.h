#define MICROPY_HW_BOARD_NAME "i.MX RT1050 EVK"
#define MICROPY_HW_MCU_NAME   "MIMXRT1052DVL6B"

#define BOARD_FLASH_SIZE (64 * 1024 * 1024)

// MIMXRT1050_EVK has 1 user LED
#define MICROPY_HW_LED1_PIN (pin_GPIO_AD_B0_09)
#define MICROPY_HW_LED_ON(pin) (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin) (mp_hal_pin_high(pin))
#define BOARD_FLASH_CONFIG_HEADER_H "evkmimxrt1050_flexspi_nor_config.h"

#define MICROPY_HW_NUM_PIN_IRQS (4 * 32 + 3)

// Define mapping logical UART # to hardware UART #
// LPUART3 on D0/D1  -> 1
// LPUART2 on D7/D6  -> 2
// LPUART6 on D8/D9  -> 3
// LPUART8 on A1/A0  -> 4

#define MICROPY_HW_UART_NUM     (sizeof(uart_index_table) / sizeof(uart_index_table)[0])
#define MICROPY_HW_UART_INDEX   { 0, 3, 2, 6, 8 }

#define IOMUX_TABLE_UART \
    { 0 }, { 0 }, \
    { IOMUXC_GPIO_AD_B1_02_LPUART2_TX }, { IOMUXC_GPIO_AD_B1_03_LPUART2_RX }, \
    { IOMUXC_GPIO_AD_B1_06_LPUART3_TX }, { IOMUXC_GPIO_AD_B1_07_LPUART3_RX }, \
    { 0 }, { 0 }, \
    { 0 }, { 0 }, \
    { IOMUXC_GPIO_AD_B0_02_LPUART6_TX }, { IOMUXC_GPIO_AD_B0_03_LPUART6_RX }, \
    { 0 }, { 0 }, \
    { IOMUXC_GPIO_AD_B1_10_LPUART8_TX }, { IOMUXC_GPIO_AD_B1_11_LPUART8_RX },
