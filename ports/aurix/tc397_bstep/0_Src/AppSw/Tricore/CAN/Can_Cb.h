/*
 * Can_Cb.h
 *
 *  Created on: May 26, 2020
 *      Author: ZhangEdi
 */

#ifndef _CDDDRV_GP_CAN_C_CAN_CB_H_
#define _CDDDRV_GP_CAN_C_CAN_CB_H_

#include "can.h"

extern void Can_TxConfirmation (uint8 CanTxPduId, Ifx_CAN_TXEVENT* TxEvent);
extern void Can_RxIndication(uint8 RxHandle, Can_Message_t *RecMsgPtr);

#endif /* 02_CDDDRV_GP_CAN_C_CAN_CB_H_ */
