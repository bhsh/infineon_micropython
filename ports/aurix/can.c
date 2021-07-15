/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014-2018 Damien P. George
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

#include "py/runtime.h"
#include "py/mperrno.h"
#include "py/mphal.h"
#include "can.h"
//YP #include "irq.h"

#if MICROPY_HW_ENABLE_CAN

void can_init0(void) {
#if 0
    for (uint i = 0; i < MP_ARRAY_SIZE(MP_STATE_PORT(pyb_can_obj_all)); i++) {
        MP_STATE_PORT(pyb_can_obj_all)[i] = NULL;
    }
#endif
}

void can_deinit_all(void) {
}

#if !MICROPY_HW_ENABLE_FDCAN

bool can_init(pyb_can_obj_t *can_obj, uint32_t mode, uint32_t prescaler, uint32_t sjw, uint32_t bs1, uint32_t bs2, bool auto_restart) {
   py_tc397_reset_can(can_obj->can_id);
}

void can_deinit(pyb_can_obj_t *self) {
   py_tc397_reset_can(self->can_id);
}

void can_clearfilter(pyb_can_obj_t *self, uint32_t f, uint8_t bank) {
#if 0
    CAN_FilterConfTypeDef filter;

    filter.FilterIdHigh = 0;
    filter.FilterIdLow = 0;
    filter.FilterMaskIdHigh = 0;
    filter.FilterMaskIdLow = 0;
    filter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    filter.FilterNumber = f;
    filter.FilterMode = CAN_FILTERMODE_IDMASK;
    filter.FilterScale = CAN_FILTERSCALE_16BIT;
    filter.FilterActivation = DISABLE;
    filter.BankNumber = bank;

    HAL_CAN_ConfigFilter(NULL, &filter);
#endif
}

int can_receive(CAN_HandleTypeDef can_id, int fifo, uint32_t *msg_id, uint8_t *data,uint8_t *len, uint32_t timeout_ms) {
    if(can_id == 1)
    {
	  py_tc397_get_can_rx_Msg(msg_id,data,len);
    }
    return 0; // success
}

// We have our own version of CAN transmit so we can handle Timeout=0 correctly.
HAL_StatusTypeDef CAN_Transmit(CAN_HandleTypeDef can_idx, uint32_t Timeout,uint32_t can_id,uint8_t* data,uint8_t len) {
  py_tc397_set_can_msg(can_idx,can_id,data,len);
  return 0;
 }

STATIC void can_rx_irq_handler(uint can_id, uint fifo_id) {
    mp_obj_t callback;
    pyb_can_obj_t *self;
    mp_obj_t irq_reason = MP_OBJ_NEW_SMALL_INT(0);
    byte *state;

    self = MP_STATE_PORT(pyb_can_obj_all)[can_id - 1];

    if (fifo_id == CAN_FIFO0) {
        callback = self->rxcallback0;
        state = &self->rx_state0;
    } else {
        callback = self->rxcallback1;
        state = &self->rx_state1;
    }
    #if 0
    switch (*state) {
        case RX_STATE_FIFO_EMPTY:
            __HAL_CAN_DISABLE_IT(&self->can,  (fifo_id == CAN_FIFO0) ? CAN_IT_FMP0 : CAN_IT_FMP1);
            irq_reason = MP_OBJ_NEW_SMALL_INT(0);
            *state = RX_STATE_MESSAGE_PENDING;
            break;
        case RX_STATE_MESSAGE_PENDING:
            __HAL_CAN_DISABLE_IT(&self->can, (fifo_id == CAN_FIFO0) ? CAN_IT_FF0 : CAN_IT_FF1);
            __HAL_CAN_CLEAR_FLAG(&self->can, (fifo_id == CAN_FIFO0) ? CAN_FLAG_FF0 : CAN_FLAG_FF1);
            irq_reason = MP_OBJ_NEW_SMALL_INT(1);
            *state = RX_STATE_FIFO_FULL;
            break;
        case RX_STATE_FIFO_FULL:
            __HAL_CAN_DISABLE_IT(&self->can, (fifo_id == CAN_FIFO0) ? CAN_IT_FOV0 : CAN_IT_FOV1);
            __HAL_CAN_CLEAR_FLAG(&self->can, (fifo_id == CAN_FIFO0) ? CAN_FLAG_FOV0 : CAN_FLAG_FOV1);
            irq_reason = MP_OBJ_NEW_SMALL_INT(2);
            *state = RX_STATE_FIFO_OVERFLOW;
            break;
        case RX_STATE_FIFO_OVERFLOW:
            // This should never happen
            break;
    }
    #endif
    pyb_can_handle_callback(self, fifo_id, callback, MP_OBJ_NEW_SMALL_INT(0));
}

STATIC void can_sce_irq_handler(uint can_id) {
#if 0
    pyb_can_obj_t *self = MP_STATE_PORT(pyb_can_obj_all)[can_id - 1];
    if (self) {
        self->can.Instance->MSR = CAN_MSR_ERRI;
        uint32_t esr = self->can.Instance->ESR;
        if (esr & CAN_ESR_BOFF) {
            ++self->num_bus_off;
        } else if (esr & CAN_ESR_EPVF) {
            ++self->num_error_passive;
        } else if (esr & CAN_ESR_EWGF) {
            ++self->num_error_warning;
        }
    }
#endif
}
void can_configure_filter(CAN_HandleTypeDef can_idx,uint32_t can_id)
{
   py_tc397_set_can_filter(can_idx,can_id);
}

#if defined(MICROPY_HW_CAN1_TX)
void CAN1_RX0_IRQHandler(void) {
    //YP IRQ_ENTER(CAN1_RX0_IRQn);
    can_rx_irq_handler(PYB_CAN_1, CAN_FIFO0);
    //YP IRQ_EXIT(CAN1_RX0_IRQn);
}

void CAN1_RX1_IRQHandler(void) {
#if 0
    IRQ_ENTER(CAN1_RX1_IRQn);
    can_rx_irq_handler(PYB_CAN_1, CAN_FIFO1);
    IRQ_EXIT(CAN1_RX1_IRQn);
#endif
}

void CAN1_SCE_IRQHandler(void) {
#if 0
    IRQ_ENTER(CAN1_SCE_IRQn);
    can_sce_irq_handler(PYB_CAN_1);
    IRQ_EXIT(CAN1_SCE_IRQn);
#endif
}
#endif

#endif // !MICROPY_HW_ENABLE_FDCAN

#endif // MICROPY_HW_ENABLE_CAN
