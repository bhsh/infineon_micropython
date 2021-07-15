#define MICROPY_HW_BOARD_NAME       "TC3X7 TriBoard V2.01"
#define MICROPY_HW_MCU_NAME         "TC397 MCU"
#define MICROPY_HW_FLASH_FS_LABEL   "AURIXTC397"

#define MICOPY_SW_DEVID             0x0001
#define MICOPY_SW_REVID             0x0000         

#define MICROPY_HW_ENABLE_RNG       (1)

// The pyboard has 4 LEDs
#define MICROPY_HW_LED1             1 // red
#define MICROPY_HW_LED2             2 // green
#define MICROPY_HW_LED3             3 // yellow
#define MICROPY_HW_LED4             4 // blue

// FDCAN bus
#define MICROPY_HW_CAN1_NAME       "CAN1"
#define MICROPY_HW_CAN1_TX         (0)
#define MICROPY_HW_CAN1_RX         (0)

//#define MICROPY_HW_LED3_PWM         { TIM2, 2, TIM_CHANNEL_1, GPIO_AF1_TIM2 }
//#define MICROPY_HW_LED4_PWM         { TIM3, 3, TIM_CHANNEL_1, GPIO_AF2_TIM3 }
#define MICROPY_HW_LED_ON(pin)      (py_tc397_led_state(pin,0))
#define MICROPY_HW_LED_OFF(pin)     (py_tc397_led_state(pin,1))