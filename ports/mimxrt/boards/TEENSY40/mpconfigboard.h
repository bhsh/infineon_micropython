#define MICROPY_HW_BOARD_NAME "Teensy 4.0"
#define MICROPY_HW_MCU_NAME   "MIMXRT1062DVJ6A"

#define BOARD_FLASH_SIZE (2 * 1024 * 1024)

// Teensy 4.0 has 1 board LED
#define MICROPY_HW_LED1_PIN (pin_GPIO_B0_03)
#define MICROPY_HW_LED_ON(pin) (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin) (mp_hal_pin_low(pin))
#define BOARD_FLASH_CONFIG_HEADER_H "teensy40_flexspi_nor_config.h"

#define MICROPY_HW_NUM_PIN_IRQS (4 * 32 + 3)

// UART config: 7 UARTs at the pins for Teensy 4.0
#define MICROPY_HW_UART_NUM     (sizeof(uart_index_table) / sizeof(uart_index_table)[0])
#define MICROPY_HW_UART_INDEX   { 0, 6, 4, 2, 3, 8, 1, 7 }

#define IOMUX_TABLE_UART \
    { IOMUXC_GPIO_AD_B0_12_LPUART1_TX }, { IOMUXC_GPIO_AD_B0_13_LPUART1_RX }, \
    { IOMUXC_GPIO_AD_B1_02_LPUART2_TX }, { IOMUXC_GPIO_AD_B1_03_LPUART2_RX }, \
    { IOMUXC_GPIO_AD_B1_06_LPUART3_TX }, { IOMUXC_GPIO_AD_B1_07_LPUART3_RX }, \
    { IOMUXC_GPIO_B1_00_LPUART4_TX }, { IOMUXC_GPIO_B1_01_LPUART4_RX }, \
    { 0 }, { 0 }, \
    { IOMUXC_GPIO_AD_B0_02_LPUART6_TX }, { IOMUXC_GPIO_AD_B0_03_LPUART6_RX }, \
    { IOMUXC_GPIO_EMC_31_LPUART7_TX }, { IOMUXC_GPIO_EMC_32_LPUART7_RX }, \
    { IOMUXC_GPIO_AD_B1_10_LPUART8_TX }, { IOMUXC_GPIO_AD_B1_11_LPUART8_RX },
