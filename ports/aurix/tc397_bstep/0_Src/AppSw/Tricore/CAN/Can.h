/*
 * Can.h
 *
 *  Created on: 2018-10-17
 *      Author: zhangwei
 */

#ifndef CAN_H_
#define CAN_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Can_Cfg.h"
#include "Ifx_Types.h"
#include "Compilers.h"

#include "IfxCan_regdef.h"
#include "IfxCan_reg.h"


/* Data type used for Rx buffer Type */
typedef enum
{
	GPCAN_RX_FIFO0 = 1,
	GPCAN_RX_FIFO1 = 2
}GpCan_RxBufferType;

typedef struct _Can_Message
{
	uint32			CanId;
	uint8			XTD;
	uint8			FDF;
	uint16          RXTS;
	uint8			DLC;
	uint8			BRS;
	union
	{
		uint8		Byte[64];
		uint32		Word[16];
	}MessageData;

}Can_Message_t;

typedef enum
{
	CAN_RTN_NOK,
	CAN_RTN_OK
}Can_ReturnValue_t;

typedef enum _CanIf_RxPduIndex
{
	CANIF_CH0_RX_APPROUTING,
	CANIF_CH0_RX_DIAGROUTING,
	CANIF_CH1_RX_APPROUTING,
	CANIF_CH1_RX_DIAGROUTING,
	CANIF_CH2_RX_APPROUTING,
	CANIF_CH2_RX_DIAGROUTING,
	CANIF_CH3_RX_APPROUTING,
	CANIF_CH3_RX_DIAGROUTING,
	CANIF_CH4_RX_APPROUTING,
	CANIF_CH4_RX_DIAGROUTING,
	CANIF_CH5_RX_APPROUTING,
	CANIF_CH5_RX_DIAGROUTING,
	CANIF_CH6_RX_APPROUTING,
	CANIF_CH6_RX_DIAGROUTING,
	CANIF_CH7_RX_APPROUTING,
	CANIF_CH7_RX_DIAGROUTING,
}CanIf_RxPduIndex_t;


extern void Can_ChInit(uint8 Channel);
extern void Can_MainFunction_Write(void);
extern void Can_MainFunction_Read(void);
extern uint8 Can_CheckBusError(uint8 Channel);
extern void Can_ClearBusError(uint8 Channel);
extern Can_ReturnValue_t Can_TxFIFO_Write(uint8 Channel, Can_Message_t *TranMsgPtr);
extern Can_ReturnValue_t Can_TxQueue0_Write(uint8 Channel, Can_Message_t *TranMsgPtr);
extern Can_ReturnValue_t Can_TxQueue1_Write(uint8 Channel, Can_Message_t *TranMsgPtr);
extern Can_ReturnValue_t Can_TxDedicatedBuffer_Write(uint8 Channel, uint8 TxBufferIndex, Can_Message_t *TranMsgPtr);

#endif /* CAN_H_ */
