// This file was automatically generated by make-pins.py
//
// --af boards/stm32f405_af.csv
// --board boards/PYBV10/pins.csv
// --prefix boards/stm32f4xx_prefix.c

// stm32f4xx_prefix.c becomes the initial portion of the generated pins file.

#include <stdio.h>

#include "py/obj.h"
#include "py/mphal.h"
#include "pin.h"

#define AF(af_idx, af_fn, af_unit, af_type, af_ptr) \
{ \
    { &pin_af_type }, \
    .name = MP_QSTR_AF ## af_idx ## _ ## af_fn ## af_unit, \
    .idx = (af_idx), \
    .fn = AF_FN_ ## af_fn, \
    .unit = (af_unit), \
    .type = AF_PIN_TYPE_ ## af_fn ## _ ## af_type, \
    .reg = (af_ptr) \
}

#define PIN(p_port, p_pin, p_af, p_adc_num, p_adc_channel) \
{ \
    { &pin_type }, \
    .name = MP_QSTR_ ## p_port ## P ## p_pin, \
    .port = PORT_ ## p_port, \
    .pin = (p_pin), \
    .num_af = (sizeof(p_af) / sizeof(pin_af_obj_t)), \
    .pin_mask = (1 << ((p_pin) & 0x0f)), \
    .gpio = GPIO ## p_port, \
    .af = p_af, \
    .adc_num = p_adc_num, \
    .adc_channel = p_adc_channel, \
}

//------------------------------------------------------------------------------------------
//GPIO 
//------------------------------------------------------------------------------------------
const pin_af_obj_t pin_P33P4_af[] = {
  AF( 1, GTM     ,  1, TOUT26       , GTM1    ), // GTM_TOUT26
  AF( 3, QSPI    ,  2, SLSO12       , QSPI2   ), // QSPI2_SLSO12
  AF( 7, CAN     , 13, TX           , CAN13   ), // CAN13_TX
};
const pin_obj_t pin_P33P4_obj = PIN(P33, 4, pin_P33P4_af, PIN_ADC1 | PIN_ADC2 | PIN_ADC3, 0);

const pin_af_obj_t pin_P33P5_af[] = {
  AF( 1, GTM	 ,	1, TOUT27		, GTM1	  ), // GTM_TOUT27
  AF( 2, QSPI    ,  0, SLSO7 	    , QSPI0	  ), // QSPI0_SLSO7
  AF( 3, QSPI    ,  1, SLSO7 	    , QSPI1	  ), // QSPI1_SLSO7
};
const pin_obj_t pin_P33P5_obj = PIN(P33, 5, pin_P33P5_af, PIN_ADC1 | PIN_ADC2 | PIN_ADC3, 0);

const pin_af_obj_t pin_P33P6_af[] = {
  AF( 1, GTM	 ,	1, TOUT28		, GTM1	  ), // GTM_TOUT28
  AF( 2, QSPI	 ,  2, SLSO11 	    , QSPI2	  ), // QSPI2_SLSO11
};
const pin_obj_t pin_P33P6_obj = PIN(P33, 6, pin_P33P6_af, PIN_ADC1 | PIN_ADC2 | PIN_ADC3, 0);

const pin_af_obj_t pin_P33P7_af[] = {
  AF( 1, GTM	 ,	1, TOUT29		, GTM1	  ), // GTM_TOUT29
  AF( 2, QSPI    ,  4, SLSO7   	    , QSPI4	  ), // QSPI4_SLSO7
};

const pin_obj_t pin_P33P7_obj = PIN(P33, 7, pin_P33P7_af, PIN_ADC1 | PIN_ADC2 | PIN_ADC3, 0);
//------------------------------------------------------------------------------------------
//ADC 
//------------------------------------------------------------------------------------------
const pin_af_obj_t pin_AN0_af[] = {
  AF( 1, ADC     ,  1, CH0       , ADC1    ), // ADC_GROUP0
};
const pin_obj_t pin_AN0_obj = PIN(AN, 0, pin_AN0_af, PIN_ADC1, 0);

const pin_af_obj_t pin_AN1_af[] = {
  AF( 1, ADC     ,  1, CH1       , ADC1    ), // ADC_GROUP0
};
const pin_obj_t pin_AN1_obj = PIN(AN, 1, pin_AN1_af, PIN_ADC1, 1);

const pin_af_obj_t pin_AN2_af[] = {
  AF( 1, ADC     ,  1, CH2       , ADC1    ), // ADC_GROUP0
};
const pin_obj_t pin_AN2_obj = PIN(AN, 2, pin_AN2_af, PIN_ADC1, 2);

const pin_af_obj_t pin_AN3_af[] = {
  AF( 1, ADC     ,  1, CH3       , ADC1    ), // ADC_GROUP0
};
const pin_obj_t pin_AN3_obj = PIN(AN, 3, pin_AN3_af, PIN_ADC1, 3);

const pin_af_obj_t pin_AN4_af[] = {
  AF( 1, ADC     ,  1, CH4       , ADC1    ), // ADC_GROUP0
};
const pin_obj_t pin_AN4_obj = PIN(AN, 4, pin_AN4_af, PIN_ADC1, 4);

const pin_af_obj_t pin_AN5_af[] = {
  AF( 1, ADC     ,  1, CH5       , ADC1    ), // ADC_GROUP0
};
const pin_obj_t pin_AN5_obj = PIN(AN, 5, pin_AN5_af, PIN_ADC1, 5);

const pin_af_obj_t pin_AN6_af[] = {
  AF( 1, ADC     ,  1, CH6       , ADC1    ), // ADC_GROUP0
};
const pin_obj_t pin_AN6_obj = PIN(AN, 6, pin_AN6_af, PIN_ADC1, 6);

const pin_af_obj_t pin_AN7_af[] = {
  AF( 1, ADC     ,  1, CH7       , ADC1    ), // ADC_GROUP0
};
const pin_obj_t pin_AN7_obj = PIN(AN, 7, pin_AN7_af, PIN_ADC1, 7);
//------------------------------------------------------------------------------------------
//Table 
//------------------------------------------------------------------------------------------
STATIC const mp_rom_map_elem_t pin_cpu_pins_locals_dict_table[] = {
  { MP_ROM_QSTR(MP_QSTR_P33P4), MP_ROM_PTR(&pin_P33P4_obj) },
  { MP_ROM_QSTR(MP_QSTR_P33P5), MP_ROM_PTR(&pin_P33P5_obj) },
  { MP_ROM_QSTR(MP_QSTR_P33P6), MP_ROM_PTR(&pin_P33P6_obj) },
  { MP_ROM_QSTR(MP_QSTR_P33P7), MP_ROM_PTR(&pin_P33P7_obj) },
  
  { MP_ROM_QSTR(MP_QSTR_ANP0),   MP_ROM_PTR(&pin_AN0_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ANP1),   MP_ROM_PTR(&pin_AN1_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ANP2),   MP_ROM_PTR(&pin_AN2_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ANP3),   MP_ROM_PTR(&pin_AN3_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ANP4),   MP_ROM_PTR(&pin_AN4_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ANP5),   MP_ROM_PTR(&pin_AN5_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ANP6),   MP_ROM_PTR(&pin_AN6_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ANP7),   MP_ROM_PTR(&pin_AN7_obj)   },
};
MP_DEFINE_CONST_DICT(pin_cpu_pins_locals_dict, pin_cpu_pins_locals_dict_table);

STATIC const mp_rom_map_elem_t pin_board_pins_locals_dict_table[] = {
  { MP_ROM_QSTR(MP_QSTR_L1),    MP_ROM_PTR(&pin_P33P4_obj) },
  { MP_ROM_QSTR(MP_QSTR_L2),    MP_ROM_PTR(&pin_P33P5_obj) },
  { MP_ROM_QSTR(MP_QSTR_L3),    MP_ROM_PTR(&pin_P33P6_obj) },
  { MP_ROM_QSTR(MP_QSTR_L4),    MP_ROM_PTR(&pin_P33P7_obj) },
  
  { MP_ROM_QSTR(MP_QSTR_ADC0),  MP_ROM_PTR(&pin_AN0_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ADC1),  MP_ROM_PTR(&pin_AN1_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ADC2),  MP_ROM_PTR(&pin_AN2_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ADC3),  MP_ROM_PTR(&pin_AN3_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ADC4),  MP_ROM_PTR(&pin_AN4_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ADC5),  MP_ROM_PTR(&pin_AN5_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ADC6),  MP_ROM_PTR(&pin_AN6_obj)   },
  { MP_ROM_QSTR(MP_QSTR_ADC7),  MP_ROM_PTR(&pin_AN7_obj)   },
};
MP_DEFINE_CONST_DICT(pin_board_pins_locals_dict, pin_board_pins_locals_dict_table);

const pin_obj_t * const pin_adc1[] = {
  &pin_AN0_obj, // 0
  &pin_AN1_obj, // 1
  &pin_AN2_obj, // 2
  &pin_AN3_obj, // 3
  &pin_AN4_obj, // 4
  &pin_AN5_obj, // 5
  &pin_AN6_obj, // 6
  &pin_AN7_obj, // 7
};
