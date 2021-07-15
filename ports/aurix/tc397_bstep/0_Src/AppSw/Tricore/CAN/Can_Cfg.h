/*
 * Can_Cfg.h
 *
 *  Created on: 2018-10-17
 *      Author: zhangwei
 */

#ifndef CAN_CFG_H_
#define CAN_CFG_H_

#include "Ifx_Types.h"
#include "Compilers.h"

#include "IfxCan_regdef.h"
#include "IfxCan_reg.h"

/* Maximum number of CAN Controllers configured in a ConfigSet */
#define GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET			(10)

/* CAN0 interrupt Priority Setting */
#define GPCAN_IRQ_CAN0_SR0_PRIO							(122)
#define GPCAN_IRQ_CAN0_SR1_PRIO							(121)
#define GPCAN_IRQ_CAN0_SR2_PRIO							(110)
#define GPCAN_IRQ_CAN0_SR3_PRIO							(0)
#define GPCAN_IRQ_CAN0_SR4_PRIO							(120)
#define GPCAN_IRQ_CAN0_SR5_PRIO							(119)
#define GPCAN_IRQ_CAN0_SR6_PRIO							(109)
#define GPCAN_IRQ_CAN0_SR7_PRIO							(0)
#define GPCAN_IRQ_CAN0_SR8_PRIO							(118)
#define GPCAN_IRQ_CAN0_SR9_PRIO							(117)
#define GPCAN_IRQ_CAN0_SR10_PRIO						(108)
#define GPCAN_IRQ_CAN0_SR11_PRIO						(0)
#define GPCAN_IRQ_CAN0_SR12_PRIO						(105)
#define GPCAN_IRQ_CAN0_SR13_PRIO						(104)
#define GPCAN_IRQ_CAN0_SR14_PRIO						(103)
#define GPCAN_IRQ_CAN0_SR15_PRIO						(0)

/* CAN1 interrupt Priority Setting */
#define GPCAN_IRQ_CAN1_SR0_PRIO							(116)
#define GPCAN_IRQ_CAN1_SR1_PRIO							(115)
#define GPCAN_IRQ_CAN1_SR2_PRIO							(107)
#define GPCAN_IRQ_CAN1_SR3_PRIO							(0)
#define GPCAN_IRQ_CAN1_SR4_PRIO							(114)
#define GPCAN_IRQ_CAN1_SR5_PRIO							(113)
#define GPCAN_IRQ_CAN1_SR6_PRIO							(106)
#define GPCAN_IRQ_CAN1_SR7_PRIO							(0)
#define GPCAN_IRQ_CAN1_SR8_PRIO							(102)
#define GPCAN_IRQ_CAN1_SR9_PRIO							(101)
#define GPCAN_IRQ_CAN1_SR10_PRIO						(100)
#define GPCAN_IRQ_CAN1_SR11_PRIO						(0)
#define GPCAN_IRQ_CAN1_SR12_PRIO						(142)
#define GPCAN_IRQ_CAN1_SR13_PRIO						(141)
#define GPCAN_IRQ_CAN1_SR14_PRIO						(140)
#define GPCAN_IRQ_CAN1_SR15_PRIO						(0)

/* CAN2 interrupt Priority Setting */
#define GPCAN_IRQ_CAN2_SR0_PRIO							(0)
#define GPCAN_IRQ_CAN2_SR1_PRIO							(0)
#define GPCAN_IRQ_CAN2_SR2_PRIO							(0)
#define GPCAN_IRQ_CAN2_SR3_PRIO							(0)
#define GPCAN_IRQ_CAN2_SR4_PRIO							(126)
#define GPCAN_IRQ_CAN2_SR5_PRIO							(125)
#define GPCAN_IRQ_CAN2_SR6_PRIO							(112)
#define GPCAN_IRQ_CAN2_SR7_PRIO							(0)
#define GPCAN_IRQ_CAN2_SR8_PRIO							(124)
#define GPCAN_IRQ_CAN2_SR9_PRIO							(123)
#define GPCAN_IRQ_CAN2_SR10_PRIO						(111)
#define GPCAN_IRQ_CAN2_SR11_PRIO						(0)
#define GPCAN_IRQ_CAN2_SR12_PRIO						(0)
#define GPCAN_IRQ_CAN2_SR13_PRIO						(0)
#define GPCAN_IRQ_CAN2_SR14_PRIO						(0)
#define GPCAN_IRQ_CAN2_SR15_PRIO						(0)

#define GPCAN_IRQ_GROUP_MAX_PRIO						(15)

typedef enum
{
	CAN0_Controller0 = 0,
	CAN0_Controller1,
	CAN0_Controller2,
	CAN0_Controller3,
	CAN1_Controller0,
	CAN1_Controller1,
	CAN1_Controller2,
	CAN1_Controller3,
	CAN2_Controller0,
	CAN2_Controller1,
	CAN2_Controller2,
	CAN2_Controller3,
}GpCan_ControllerIdType;

typedef enum
{
	CANXX_RXSEL_RXDA = 0,
	CANXX_RXSEL_RXDB,
	CANXX_RXSEL_RXDC,
	CANXX_RXSEL_RXDD,
	CANXX_RXSEL_RXDE,
	CANXX_RXSEL_RXDF,
	CANXX_RXSEL_RXDG,
	CANXX_RXSEL_RXDH,
}GpCan_IORxSelType;

typedef enum
{
	MESSAGE_ID_TYPE_STANDARD = 0,
	MESSAGE_ID_TYPE_EXTENDED,
}GpCan_MessageIdType;

typedef enum
{
	CAN_EVENT_HANDLING_POLLING = 0,
	CAN_EVENT_HANDLING_INTERRUPT
}GpCan_EventHandlingType;

typedef struct
{
	GpCan_EventHandlingType				mRxEventHandle;
	GpCan_EventHandlingType				mTxEventHandle;
}GpCan_EventConfigType;

typedef struct
{
	uint32								mFdBaudrate;
	uint16								mFdSamplePoint;
	uint16								mFdSyncJumpWidth;
	uint8                               mFdTransDelayOffset;
}GpCan_FDBaudrateConfigType;

typedef struct
{
	float32                             mModuleFreq;
	uint32								mBaudrate;
	uint16								mSamplePoint;
	uint16								mSyncJumpWidth;
	boolean								mFdEnabled;
	GpCan_FDBaudrateConfigType          mFdBaudConfig;
}GpCan_BaudrateConfigType;


typedef struct
{
	uint8								mTxFifoSize;
	uint8								mTxQueue0Size;
	uint8								mTxQueue1Size;
	uint8								mDedicatedBufferSize;
}GpCan_TxMessageConfigType;

typedef struct
{
	uint32								mFilterMsgId;
	uint32								mFilterMask;
}GpCan_FilterConfigType;

typedef struct
{
	uint8								mRxFifoSize;
	GpCan_MessageIdType                 mRxMsgIdType;
	GpCan_FilterConfigType              mRxFifoFilter;
}GpCan_RxFifoConfigType;

typedef struct
{
	GpCan_RxFifoConfigType				mRxFifo0Config;
	GpCan_RxFifoConfigType				mRxFifo1Config;
}GpCan_RxMessageConfigType;

typedef struct
{
	GpCan_ControllerIdType				mNodeId;
	GpCan_IORxSelType					mRxSel;
	GpCan_EventConfigType               mEventHandle;
	GpCan_BaudrateConfigType			mNodeBaudrate;
	GpCan_TxMessageConfigType			mNodeTxMessage;
	GpCan_RxMessageConfigType			mNodeRxMessage;
}GpCan_ControllerConfigType;

extern GpCan_ControllerConfigType GpCan_ControllerConfigInfo[GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET];

#endif /* CAN_CFG_H_ */
