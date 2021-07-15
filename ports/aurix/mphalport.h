#include "pin.h"

#define mp_hal_pin_obj_t const pin_obj_t *

#define mp_hal_pin_high(p)      pin_set_high(p)
#define mp_hal_pin_low(p)       pin_set_low(p)
#define mp_hal_pin_read(p)      pin_read(p)
#define mp_hal_pin_write(p, v)  ((v) ? mp_hal_pin_high(p) : mp_hal_pin_low(p))

#define HAL_GPIO_Init(x,y)      pin_hal_gpio_init(x,y)    


void py_tc397_set_can_msg(unsigned char can_idx, uint32_t can_id,uint8_t* data,uint8_t len);
void py_tc397_reset_can(unsigned char can_idx);
void py_tc397_get_can_rx_Msg(unsigned int *msgid,unsigned char *data, unsigned char *len);
void py_tc397_set_can_filter(unsigned char can_idx,unsigned int id);

//YP static inline mp_uint_t mp_hal_ticks_ms(void) {
//YP    return 0;
//YP }
static inline void mp_hal_set_interrupt_char(char c) {}
