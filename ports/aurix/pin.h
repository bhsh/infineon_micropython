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
#ifndef MICROPY_INCLUDED_AURIX_PIN_H
#define MICROPY_INCLUDED_AURIX_PIN_H

// This file requires pin_defs_xxx.h (which has port specific enums and
// defines, so we include it here. It should never be included directly

#include MICROPY_PIN_DEFS_PORT_H
#include "py/obj.h"

#define GPIO_OUTPUT_TYPE    ((uint32_t)0x00000010)  // Indicates OD

#define GPIO_MODE_INPUT     ((uint32_t)0x00000000)
#define GPIO_MODE_OUTPUT_PP ((uint32_t)0x00000001)
#define GPIO_MODE_OUTPUT_OD ((uint32_t)0x00000011)
#define GPIO_MODE_AF_PP     ((uint32_t)0x00000002)
#define GPIO_MODE_AF_OD     ((uint32_t)0x00000012)
#define GPIO_MODE_ANALOG    ((uint32_t)0x00000003)
#define GPIO_MODE_IT_RISING ((uint32_t)1)
#define GPIO_MODE_IT_FALLING ((uint32_t)2)

#define GPIO_NOPULL         ((uint32_t)0)
#define GPIO_PULLUP         ((uint32_t)1)
#define GPIO_PULLDOWN       ((uint32_t)2)

#define GPIO_AF1_GTM1       1
#define GPIO_AF2_QSPI0      2
#define GPIO_AF2_QSPI2      2
#define GPIO_AF2_QSPI4      2
#define GPIO_AF3_QSPI1      3
#define GPIO_AF3_QSPI2      3
#define GPIO_AF7_CAN13      7

#define GPIO_SPEED_FREQ_LOW       ((uint32_t)0)
#define GPIO_SPEED_FREQ_MEDIUM    ((uint32_t)1)
#define GPIO_SPEED_FREQ_HIGH      ((uint32_t)2)
#define GPIO_SPEED_FREQ_VERY_HIGH ((uint32_t)3)

#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_MODE_INPUT) || \
    ((MODE) == GPIO_MODE_OUTPUT_PP) || \
    ((MODE) == GPIO_MODE_OUTPUT_OD) || \
    ((MODE) == GPIO_MODE_AF_PP) || \
    ((MODE) == GPIO_MODE_AF_OD) || \
    ((MODE) == GPIO_MODE_ANALOG))
    
#define IS_GPIO_PULL(PULL) (((PULL) == GPIO_NOPULL) || ((PULL) == GPIO_PULLUP) || \
    ((PULL) == GPIO_PULLDOWN))
    
#define IS_GPIO_AF(af)      ((af) >= 0 && (af) <= 7)

typedef struct {
    uint32_t Pin;
    uint32_t Mode;
    uint32_t Pull;
    uint32_t Speed;
    uint32_t Alternate;
} GPIO_InitTypeDef;

typedef struct {
    volatile uint32_t PDOR;         // Output register
    volatile uint32_t PSOR;         // Set output register
    volatile uint32_t PCOR;         // Clear output register
    volatile uint32_t PTOR;         // Toggle output register
    volatile uint32_t PDIR;         // Data Input register
    volatile uint32_t PDDR;         // Data Direction register
} GPIO_TypeDef;

typedef GPIO_TypeDef pin_gpio_t;

//For the aurix pin register
#define GPIOP33   ((GPIO_TypeDef *)0)
#define GPIOAN    ((GPIO_TypeDef *)0)

#define GTM1      ((GPIO_TypeDef *)0)
#define QSPI0     ((GPIO_TypeDef *)0)
#define QSPI1     ((GPIO_TypeDef *)0)
#define QSPI2     ((GPIO_TypeDef *)0)
#define QSPI4     ((GPIO_TypeDef *)0)
#define CAN13     ((GPIO_TypeDef *)0)
#define ADC1      ((GPIO_TypeDef *)0)

typedef struct {
    mp_obj_base_t base;
    qstr name;
    uint8_t idx;
    uint8_t fn;
    uint8_t unit;
    uint8_t type;
    void *reg; // The peripheral associated with this AF
} pin_af_obj_t;

typedef struct {
    mp_obj_base_t base;
    qstr name;
    uint32_t port   : 4;
    uint32_t pin    : 5;    // Some ARM processors use 32 bits/PORT
    uint32_t num_af : 4;
    uint32_t adc_channel : 5; // Some ARM processors use 32 bits/PORT
    uint32_t adc_num  : 3;  // 1 bit per ADC
    uint32_t pin_mask;
    pin_gpio_t *gpio;
    const pin_af_obj_t *af;
} pin_obj_t;

extern const mp_obj_type_t pin_type;
extern const mp_obj_type_t pin_af_type;

// Include all of the individual pin objects
//YP #include "genhdr/pins.h"

typedef struct {
    const char *name;
    const pin_obj_t *pin;
} pin_named_pin_t;

extern const pin_named_pin_t pin_board_pins[];
extern const pin_named_pin_t pin_cpu_pins[];

// extern pin_map_obj_t pin_map_obj;

typedef struct {
    mp_obj_base_t base;
    qstr name;
    const pin_named_pin_t *named_pins;
} pin_named_pins_obj_t;

extern const mp_obj_type_t pin_board_pins_obj_type;
extern const mp_obj_type_t pin_cpu_pins_obj_type;

extern const mp_obj_dict_t pin_cpu_pins_locals_dict;
extern const mp_obj_dict_t pin_board_pins_locals_dict;
extern const pin_obj_t * const pin_adc1[];

MP_DECLARE_CONST_FUN_OBJ_KW(pin_init_obj);

uint8_t py_tc397_get_pin_state(uint8_t idx);
void py_tc397_set_pin_low(uint8_t idx);
void py_tc397_set_pin_high(uint8_t idx);
uint8_t py_tc397_get_pin_mode(uint8_t idx );
void py_tc397_set_pin_mode(unsigned char idx ,unsigned char mode);
unsigned int py_tc397_get_adc_result(unsigned char idx);
float py_tc397_get_McuDieTemp_Float(void);

void pin_init0(void);
uint32_t pin_get_mode(const pin_obj_t *pin);
uint32_t pin_get_pull(const pin_obj_t *pin);
uint32_t pin_get_af(const pin_obj_t *pin);
const pin_obj_t *pin_find(mp_obj_t user_obj);
const pin_obj_t *pin_find_named_pin(const mp_obj_dict_t *named_pins, mp_obj_t name);
const pin_af_obj_t *pin_find_af(const pin_obj_t *pin, uint8_t fn, uint8_t unit);
const pin_af_obj_t *pin_find_af_by_index(const pin_obj_t *pin, mp_uint_t af_idx);
const pin_af_obj_t *pin_find_af_by_name(const pin_obj_t *pin, const char *name);

#endif // MICROPY_INCLUDED_AURIX_PIN_H
