/*
 * Can.c
 *
 *  Created on: 2018-10-17
 *      Author: zhangwei
 */


#include "Can.h"
#include "IfxSrc_reg.h"
#include "IfxCan_bf.h"
#include "Can_Cb.h"
#include "IfxCpu_reg.h"
#include "IfxScuWdt.h"

#define GPCAN_MODULE_NUMBER_MAX									(3u)
#define GPCAN_NODE_NUMBER_EACH_MODULE							(4u)
#define GPCAN_INTERRUPT_LINE_NUMBER_EACH_MODULE					(16u)

#define GPCAN_TX_BUFFER_ELEMENT_MAX								(32u)
#define GPCAN_TX_BUFFER_INDEX_FIFO								(255u)

#define GpCan_GetModuleIdFromControllerConfig(nodeId)			(((nodeId) & 0x0C) >> 2u)
#define GpCan_GetNodeIdFromControllerConfig(nodeId)				((nodeId) & 0x03)

/* Values for clear IR register */
#define GPCAN_CLEAR_ALL_INTERRUPTS                  			(uint32)(0x3FCFFFFFU)

/* Values for Set Global register for reject RTR and Non Match Frames */
#define GPCAN_GFC_REJT_RTR_NONMATCH                 			(uint32)(0x0000003FU)

/* Value for MASK the Message RAM Offset address */
#define GPCAN_RAM_ADDRESS_OFFSET_MASK               			(uint32) (0x0000FFFC)

/* Disable CAN clock */
#define GPCAN_CLK_DISABLE                						((uint32)0)

#define GPCAN_NODE_INIT_MODE                        			(0x00000001U)

#define GPCAN_MODULE_DISABLE_STATUS                 			(0x00000002U)

/* Value used for the CLK selection */
#define GPCAN_MCR_CLKSEL_SET                        			(uint32)(0x00000003U)

/* Value used for enable the CLK configuration change */
#define GPCAN_CLKSEL_WRITE_ENABLE                   			(0xC0000000U)

/* Shift operation values used by the CAN driver */
#define GPCAN_SHIFT_TWENTYFOUR                      			(uint8)24

/* Number of transmit hardware object buffers present */
#define GPCAN_NOOF_TX_HW_BUFF_AVAILABLE             			((uint32)32)

/* Set for identify the MsgID is extended */
#define GPCAN_SET_XTD_BIT_MASK                      			(0x80000000U)

/* Value used for set the FD status for upper-layer */
#define GPCAN_SET_FD_MASK                                       (0x40000000U)

/* Value used for Max FD length operation */
#define GPCAN_MAX_FD_LENGTH                                     (uint8)64

#define GPCAN_EXTENDED_ID_MASK                      			(uint32)(0x1FFFFFFFU)
#define GPCAN_STANDARD_ID_MASK                      			(uint32)(0x000007FFU)

/* Shift operation values used by the CAN driver */
#define GPCAN_SHIFT_EIGHTEEN                        			(uint8)18

/* Set CLRR to clear SRR bit and disable SRE bit */
#define GPCAN_IRQ_DISABLE_CLEAR_SRC     						(0x52000000U)

#define GPCAN_CLEAR_IR_RETRY_TIMES                               (10u)

/************************* interrupt Type of Service **************************/
#define GPCAN_IRQ_TOS_CPU0                						(0x0)

#define GPCAN_IRQ_CLEAR_MASK                					0xFFFFFFFFU

#define GPCAN_IRQ_SFR_MODIFY32(reg, clearmask ,setmask)  	    { ((reg)) &= clearmask; ((reg)) = (setmask);}

/* Clear TEFN (Tx Event FIFO New Entry) flag in IR register */
#define GPCAN_CLEAR_IE_TEFN_BIT                     			(uint32) (0x00001000U)
#define GPCAN_CLEAR_IE_RF0N_BIT									(uint32) (0x00000001U)
#define GPCAN_CLEAR_IE_RF1N_BIT									(uint32) (0x00000010U)

#define GPCAN_ABSF(X)                       					( ((X) < 0.0) ? -(X) : (X) )

#define GPCAN_MSGRAM_STDFILTER_ELEMENT_SIZE						(4u)
#define GPCAN_MSGRAM_XTDFILTER_ELEMENT_SIZE						(8u)
#define GPCAN_MSGRAM_RXFIFO_ELEMENT_SIZE						(16u)
#define GPCAN_MSGRAM_RXFDFIFO_ELEMENT_SIZE						(72u)/* Message RAM element size with FD support */
#define GPCAN_MSGRAM_TXEVENT_ELEMENT_SIZE						(8u)
#define GPCAN_MSGRAM_TXBUFFER_ELEMENT_SIZE						(16u)
#define GPCAN_MSGRAM_TXFDBUFFER_ELEMENT_SIZE					(72u)

#define GPCAN_CONTROLLER_CHANNEL_INVALID						(255)
#define GPCAN_CONTROLLER_CHANNEL_INIT							{GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID,	\
																 GPCAN_CONTROLLER_CHANNEL_INVALID}
typedef enum
{
	GpCan_DataFieldSize_8 = 0,      /**< \brief 8 byte data field  */
	GpCan_DataFieldSize_12,     	/**< \brief 12 byte data field  */
	GpCan_DataFieldSize_16,     	/**< \brief 16 byte data field  */
	GpCan_DataFieldSize_20,     	/**< \brief 20 byte data field  */
	GpCan_DataFieldSize_24,     	/**< \brief 24 byte data field  */
	GpCan_DataFieldSize_32,     	/**< \brief 32 byte data field  */
	GpCan_DataFieldSize_48,     	/**< \brief 48 byte data field  */
	GpCan_DataFieldSize_64      	/**< \brief 64 byte data field  */
} GpCan_DataFieldSize;

typedef struct
{
	uint32					mStdFilterStartAddr;
	uint32					mExtFilterStartAddr;
	uint32					mRxFifo0StartAddr;
	uint32					mRxFifo1StartAddr;
	uint32					mTxEventFifoStartAddr;
	uint32					mTxBufferStartAddr;

	uint8					mStdFilterSize;
	uint8					mExtFilterSize;
	uint8                   mTxEventFifoSize;
}GpCan_MsgRamSectionType;

typedef struct
{
	uint8					mTOS;		/*Type of Service Control*/
	uint8					mSRPN;		/*Service Request Priority Number*/
}GpCan_InterruptConfigType;

typedef enum
{
	GpCan_TxQueueState_Idle = 0,
	GpCan_TxQueueState_Pending,
}GpCan_TxQueueStateType;

typedef struct
{
	GpCan_TxQueueStateType	mQueueState[GPCAN_TX_BUFFER_ELEMENT_MAX];
}GpCan_TxQueueType;

static const GpCan_InterruptConfigType GpCan_InterruptSets[GPCAN_MODULE_NUMBER_MAX][GPCAN_INTERRUPT_LINE_NUMBER_EACH_MODULE] =
{
	{   /* CAN0 */
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR0_PRIO},  /* interrupt line 0*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR1_PRIO},  /* interrupt line 1*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR2_PRIO},  /* interrupt line 2*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR3_PRIO},  /* interrupt line 3*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR4_PRIO},  /* interrupt line 4*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR5_PRIO},  /* interrupt line 5*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR6_PRIO},  /* interrupt line 6*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR7_PRIO},  /* interrupt line 7*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR8_PRIO},  /* interrupt line 8*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR9_PRIO},  /* interrupt line 9*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR10_PRIO}, /* interrupt line 10*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR11_PRIO}, /* interrupt line 11*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR12_PRIO}, /* interrupt line 12*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR13_PRIO}, /* interrupt line 13*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR14_PRIO}, /* interrupt line 14*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN0_SR15_PRIO}  /* interrupt line 15*/
	},
	{	/* CAN1 */
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR0_PRIO},  /* interrupt line 0*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR1_PRIO},  /* interrupt line 1*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR2_PRIO},  /* interrupt line 2*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR3_PRIO},  /* interrupt line 3*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR4_PRIO},  /* interrupt line 4*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR5_PRIO},  /* interrupt line 5*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR6_PRIO},  /* interrupt line 6*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR7_PRIO},  /* interrupt line 7*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR8_PRIO},  /* interrupt line 8*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR9_PRIO},  /* interrupt line 9*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR10_PRIO}, /* interrupt line 10*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR11_PRIO}, /* interrupt line 11*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR12_PRIO}, /* interrupt line 12*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR13_PRIO}, /* interrupt line 13*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR14_PRIO}, /* interrupt line 14*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN1_SR15_PRIO}  /* interrupt line 15*/
	},
	{   /* CAN2 */
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR0_PRIO},  /* interrupt line 0*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR1_PRIO},  /* interrupt line 1*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR2_PRIO},  /* interrupt line 2*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR3_PRIO},  /* interrupt line 3*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR4_PRIO},  /* interrupt line 4*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR5_PRIO},  /* interrupt line 5*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR6_PRIO},  /* interrupt line 6*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR7_PRIO},  /* interrupt line 7*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR8_PRIO},  /* interrupt line 8*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR9_PRIO},  /* interrupt line 9*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR10_PRIO}, /* interrupt line 10*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR11_PRIO}, /* interrupt line 11*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR12_PRIO}, /* interrupt line 12*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR13_PRIO}, /* interrupt line 13*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR14_PRIO}, /* interrupt line 14*/
		{GPCAN_IRQ_TOS_CPU0,	GPCAN_IRQ_CAN2_SR15_PRIO}  /* interrupt line 15*/
	},
};

static const uint32 GpCan_ModuleBaseAddress[GPCAN_MODULE_NUMBER_MAX] = {0xF0200000u, 0xF0210000u, 0xF0220000u};
static const uint32 GpCan_NodeRegAddress[GPCAN_MODULE_NUMBER_MAX][GPCAN_NODE_NUMBER_EACH_MODULE] =
{
	{0xF0208100u, 0xF0208500u, 0xF0208900u, 0xF0208D00u},
	{0xF0218100u, 0xF0218500u, 0xF0218900u, 0xF0218D00u},
	{0xF0228100u, 0xF0228500u, 0xF0228900u, 0xF0228D00u}
};

static const uint8 GpCan_DlcConvDataByte[16u] = {0,1,2,3,4,5,6,7,8,12,16,20,24,32,48,64};

static uint8 GpCan_ControllerChannel[GPCAN_MODULE_NUMBER_MAX * GPCAN_NODE_NUMBER_EACH_MODULE] = GPCAN_CONTROLLER_CHANNEL_INIT;

static GpCan_MsgRamSectionType GpCan_MsgRamSectionInfo[GPCAN_MODULE_NUMBER_MAX * GPCAN_NODE_NUMBER_EACH_MODULE];
static uint32				   GpCan_RamBufferCurrentAddr[GPCAN_MODULE_NUMBER_MAX] = {0xF0200000u, 0xF0210000u, 0xF0220000u};

static boolean				   GpCan_ModuleIsInited[GPCAN_MODULE_NUMBER_MAX] = {FALSE, FALSE, FALSE};
static GpCan_TxQueueType       GpCan_TxQueueStatus[GPCAN_MODULE_NUMBER_MAX][GPCAN_NODE_NUMBER_EACH_MODULE];
static boolean GpCan_RamSectionInitState[GPCAN_MODULE_NUMBER_MAX][GPCAN_NODE_NUMBER_EACH_MODULE] =
{
	{FALSE, FALSE, FALSE, FALSE},
	{FALSE, FALSE, FALSE, FALSE},
	{FALSE, FALSE, FALSE, FALSE}
};

static void GpCan_SetNodeBitTiming(Ifx_CAN_N *node, float32 moduleFreq, uint32 baudrate, uint16 samplePoint, uint16 syncJumpWidth)
{
	sint32  maxBRP   = IFX_CAN_N_NBTP_NBRP_MSK + 1;
	sint32  minBRP   = 1;
	sint32  maxTSEG1 = IFX_CAN_N_NBTP_NTSEG1_MSK + 1;
	sint32  minTSEG1 = 3;
	sint32  maxTSEG2 = IFX_CAN_N_NBTP_NTSEG2_MSK + 1;
	sint32  minTSEG2 = 2;
	sint32  maxTBAUD = 0;
	sint32  minTBAUD = 8;

	sint32  tempBRP, tempSJW, tempTSEG1, tempTBAUD = 1;
	sint32  bestBRP   = 1, bestSJW = 1, bestTBAUD = 8, bestTSEG1 = 3, bestTSEG2 = 2;
	float32 bestError = 0;

    /*
     * Bit timing & sampling
     * Tq = (BRP+1)/Fcan if DIV8 = 0
     * Tq = 8*(BRP+1)/Fcan if DIV8 = 1
     * TSync = 1.Tq
     * TSeg1 = (TSEG1+1)*Tq                >= 3Tq
     * TSeg2 = (TSEG2+1)*Tq                >= 2Tq
     * Bit Time = TSync + TSeg1 + TSeg2    >= 8Tq
     *
     * Resynchronization:
     *
     * Tsjw = (SJW + 1)*Tq
     * TSeg1 >= Tsjw + Tprop
     * TSeg2 >= Tsjw
     */

    /* search for best baudrate */
    bestError = (float32)baudrate;
    maxTBAUD  = maxTSEG1 + maxTSEG2 + 1;

    for (tempBRP = 1; tempBRP <= maxBRP; tempBRP++)
    {
        float32 Fquanta = moduleFreq / tempBRP;
        tempTBAUD = Fquanta / baudrate;

        if (tempTBAUD == 0)
        {
            break; /* to avoid division by 0 */
        }

        float32 tempBaudrate = Fquanta / tempTBAUD;
        float32 error        = GPCAN_ABSF(tempBaudrate - baudrate);

        if (tempTBAUD < minTBAUD)
        {
            break;  /* below the minimum allowed limits, break is required otherwise TSEG1 and TSEG2 may result in negitive values */
        }

        if ((tempTBAUD <= maxTBAUD) && (bestError >= error))
        {
            bestBRP   = tempBRP;
            bestTBAUD = tempTBAUD;
            bestError = error;

            if ((tempTBAUD <= 20) && (error < 0.1))
            {
                break;      /* optimal condition */
            }
        }
    }

    if ((bestBRP == 0) && (tempBRP == (maxBRP + 1)))
    {
        bestBRP   = maxBRP;
        bestTBAUD = maxTBAUD;
    }

    if ((bestBRP == 0) && (tempTBAUD < minTBAUD))
    {
        bestBRP   = minBRP;
        bestTBAUD = minTBAUD;
    }

    /* search for best sample point */
    bestError = samplePoint * 0.25; /* 25% tolerance in sample point as max error */

    if (bestTBAUD < maxTSEG1)
    {
        maxTSEG1 = bestTBAUD;
    }

    bestTSEG1 = maxTSEG1;

    for (tempTSEG1 = maxTSEG1; tempTSEG1 >= minTSEG1; tempTSEG1--)
    {
        sint32 tempSamplePoint = ((tempTSEG1 + 1) * 10000) / bestTBAUD;
        sint32 error           = __abs(tempSamplePoint - samplePoint);

        if (bestError > error)
        {
            bestTSEG1 = tempTSEG1;
            bestError = (float)error;
        }

        if (tempSamplePoint < samplePoint)
        {
            /*least possible error */
            break;  /* least possible error has already occured */
        }
    }

    bestTSEG2 = bestTBAUD - bestTSEG1 - 1;

    if (bestTSEG2 > maxTSEG2)
    {
        bestTSEG2 = maxTSEG2;
    }

    if (bestTSEG2 < minTSEG2)
    {
        bestTSEG2 = minTSEG2;
    }

    /* search for best SJW */
    bestError = 10000;

    for (tempSJW = 1; tempSJW <= bestTSEG2; tempSJW++)
    {
        sint32 tempSyncJumpWidth = (tempSJW * 10000) / bestTBAUD;
        sint32 error             = __abs(tempSyncJumpWidth - syncJumpWidth);

        if (bestError > error)
        {
            bestSJW   = tempSJW;
            bestError = (float)error;
        }
    }

    {
        node->NBTP.B.NBRP   = bestBRP - 1;
        node->NBTP.B.NSJW   = bestSJW - 1;
        node->NBTP.B.NTSEG1 = bestTSEG1 - 1;
        node->NBTP.B.NTSEG2 = bestTSEG2 - 1;
    }

}

static void GpCan_SetNodeFastBitTiming(Ifx_CAN_N *node, float32 moduleFreq, uint32 baudrate, uint16 samplePoint, uint16 syncJumpWidth)
{
    sint32  maxBRP   = IFX_CAN_N_DBTP_DBRP_MSK + 1;
    sint32  minBRP   = 1;
    sint32  maxTSEG1 = IFX_CAN_N_DBTP_DTSEG1_MSK + 1;
    sint32  minTSEG1 = 3;
    sint32  maxTSEG2 = IFX_CAN_N_DBTP_DTSEG2_MSK + 1;
    sint32  minTSEG2 = 2;
    sint32  maxTBAUD = 0;
    sint32  minTBAUD = 8;

    sint32  tempBRP, tempSJW, tempTSEG1, tempTBAUD = 1;
    sint32  bestBRP   = 1, bestSJW = 1, bestTBAUD = 8, bestTSEG1 = 3, bestTSEG2 = 2;
    float32 bestError = 0;

    /*
     * Bit timing & sampling
     * Tq = (BRP+1)/Fcan if DIV8 = 0
     * Tq = 8*(BRP+1)/Fcan if DIV8 = 1
     * TSync = 1.Tq
     * TSeg1 = (TSEG1+1)*Tq                >= 3Tq
     * TSeg2 = (TSEG2+1)*Tq                >= 2Tq
     * Bit Time = TSync + TSeg1 + TSeg2    >= 8Tq
     *
     * Resynchronization:
     *
     * Tsjw = (SJW + 1)*Tq
     * TSeg1 >= Tsjw + Tprop
     * TSeg2 >= Tsjw
     */

    /* search for best baudrate */
    bestError = (float32)baudrate;
    maxTBAUD  = maxTSEG1 + maxTSEG2 + 1;

    for (tempBRP = 1; tempBRP <= maxBRP; tempBRP++)
    {
        float32 Fquanta = moduleFreq / tempBRP;
        tempTBAUD = Fquanta / baudrate;

        if (tempTBAUD == 0)
        {
            break; /* to avoid division by 0 */
        }

        float32 tempBaudrate = Fquanta / tempTBAUD;
        float32 error        = GPCAN_ABSF(tempBaudrate - baudrate);

        if (tempTBAUD < minTBAUD)
        {
            break;  /* below the minimum allowed limits, break is required otherwise TSEG1 and TSEG2 may result in negitive values */
        }

        if ((tempTBAUD <= maxTBAUD) && (bestError >= error))
        {
            bestBRP   = tempBRP;
            bestTBAUD = tempTBAUD;
            bestError = error;

            if ((tempTBAUD <= 20) && (error < 0.1))
            {
                break;      /* optimal condition */
            }
        }
    }

    if ((bestBRP == 0) && (tempBRP == (maxBRP + 1)))
    {
        bestBRP   = maxBRP;
        bestTBAUD = maxTBAUD;
    }

    if ((bestBRP == 0) && (tempTBAUD < minTBAUD))
    {
        bestBRP   = minBRP;
        bestTBAUD = minTBAUD;
    }

    /* search for best sample point */
    bestError = samplePoint * 0.25; /* 25% tolerance in sample point as max error */

    if (bestTBAUD < maxTSEG1)
    {
        maxTSEG1 = bestTBAUD;
    }

    bestTSEG1 = maxTSEG1;

    for (tempTSEG1 = maxTSEG1; tempTSEG1 >= minTSEG1; tempTSEG1--)
    {
        sint32 tempSamplePoint = ((tempTSEG1 + 1) * 10000) / bestTBAUD;
        sint32 error           = __abs(tempSamplePoint - samplePoint);

        if (bestError > error)
        {
            bestTSEG1 = tempTSEG1;
            bestError = (float)error;
        }

        if (tempSamplePoint < samplePoint)
        {
            break;  /* least possible error has already occured */
        }
    }

    bestTSEG2 = bestTBAUD - bestTSEG1 - 1;

    if (bestTSEG2 > maxTSEG2)
    {
        bestTSEG2 = maxTSEG2;
    }

    if (bestTSEG2 < minTSEG2)
    {
        bestTSEG2 = minTSEG2;
    }

    /* search for best SJW */
    bestError = 10000;

    for (tempSJW = 1; tempSJW <= bestTSEG2; tempSJW++)
    {
        sint32 tempSyncJumpWidth = (tempSJW * 10000) / bestTBAUD;
        sint32 error             = __abs(tempSyncJumpWidth - syncJumpWidth);

        if (bestError > error)
        {
            bestSJW   = tempSJW;
            bestError = (float)error;
        }
    }

    {
        node->DBTP.B.DBRP   = bestBRP - 1;
        node->DBTP.B.DSJW   = bestSJW - 1;
        node->DBTP.B.DTSEG1 = bestTSEG1 - 1;
        node->DBTP.B.DTSEG2 = bestTSEG2 - 1;
    }
}

static void GpCan_MsgRamSectionInit(uint8 Channel)
{
	GpCan_MsgRamSectionInfo[Channel].mStdFilterStartAddr = 0u;
	GpCan_MsgRamSectionInfo[Channel].mExtFilterStartAddr = 0u;
	GpCan_MsgRamSectionInfo[Channel].mRxFifo0StartAddr = 0u;
	GpCan_MsgRamSectionInfo[Channel].mRxFifo1StartAddr = 0u;
	GpCan_MsgRamSectionInfo[Channel].mTxEventFifoStartAddr = 0u;
	GpCan_MsgRamSectionInfo[Channel].mTxBufferStartAddr = 0u;

	GpCan_MsgRamSectionInfo[Channel].mStdFilterSize = 0u;
	GpCan_MsgRamSectionInfo[Channel].mExtFilterSize = 0u;
	GpCan_MsgRamSectionInfo[Channel].mTxEventFifoSize = 0u;
}

static void GpCan_CalcMsgRamSectionFromConfiguration(uint8 Channel)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId;
	uint8 						 lModuleId;

	uint8                        lTxBufferElementCount = 0u;
	uint8                        lTxEventFifoSize = 0u;

	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);

		/* calculate standard id filter start address */
		/* RX FIFO0 configured and standard id AND RX FIFO1 configured and standard id */
		if(    ((0u < lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize) && (MESSAGE_ID_TYPE_STANDARD == lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxMsgIdType))
			&& ((0u < lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize) && (MESSAGE_ID_TYPE_STANDARD == lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxMsgIdType))
		  )
		{
			GpCan_MsgRamSectionInfo[Channel].mStdFilterStartAddr = GpCan_RamBufferCurrentAddr[lModuleId];
			GpCan_RamBufferCurrentAddr[lModuleId] += (2u/* FIFO0 and FIFO1*/ * GPCAN_MSGRAM_STDFILTER_ELEMENT_SIZE);
			GpCan_MsgRamSectionInfo[Channel].mStdFilterSize = 2u;/* FIFO0 and FIFO1*/
		}
		/* RX FIFO0 configured and standard id OR RX FIFO1 configured and standard id */
		else if(    ((0u < lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize) && (MESSAGE_ID_TYPE_STANDARD == lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxMsgIdType))
				 || ((0u < lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize) && (MESSAGE_ID_TYPE_STANDARD == lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxMsgIdType))
			  )
		{
			GpCan_MsgRamSectionInfo[Channel].mStdFilterStartAddr = GpCan_RamBufferCurrentAddr[lModuleId];
			GpCan_RamBufferCurrentAddr[lModuleId] += (1u/* FIFO0 or FIFO1*/ * GPCAN_MSGRAM_STDFILTER_ELEMENT_SIZE);
			GpCan_MsgRamSectionInfo[Channel].mStdFilterSize = 1u;/* FIFO0 or FIFO1*/
		}
		else
		{
			/* stand id filter start address = 0x00000000 */
			/* stand id filter size = 0 */
		}


		/* calculate extended id filter start address */
		/* RX FIFO0 configured and extended id AND RX FIFO1 configured and extended id */
		if(    ((0u < lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize) && (MESSAGE_ID_TYPE_EXTENDED == lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxMsgIdType))
			&& ((0u < lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize) && (MESSAGE_ID_TYPE_EXTENDED == lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxMsgIdType))
		  )
		{
			GpCan_MsgRamSectionInfo[Channel].mExtFilterStartAddr = GpCan_RamBufferCurrentAddr[lModuleId];
			GpCan_RamBufferCurrentAddr[lModuleId] += (2u/* FIFO0 and FIFO1*/ * GPCAN_MSGRAM_XTDFILTER_ELEMENT_SIZE);
			GpCan_MsgRamSectionInfo[Channel].mExtFilterSize = 2u;/* FIFO0 and FIFO1*/
		}
		/* RX FIFO0 configured and extended id OR RX FIFO1 configured and extended id */
		else if(    ((0u < lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize) && (MESSAGE_ID_TYPE_EXTENDED == lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxMsgIdType))
				 || ((0u < lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize) && (MESSAGE_ID_TYPE_EXTENDED == lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxMsgIdType))
			  )
		{
			GpCan_MsgRamSectionInfo[Channel].mExtFilterStartAddr = GpCan_RamBufferCurrentAddr[lModuleId];
			GpCan_RamBufferCurrentAddr[lModuleId] += (1u/* FIFO0 or FIFO1*/ * GPCAN_MSGRAM_XTDFILTER_ELEMENT_SIZE);
			GpCan_MsgRamSectionInfo[Channel].mExtFilterSize = 1u;/* FIFO0 or FIFO1*/
		}
		else
		{
			/* extended id filter start address = 0x00000000 */
			/* extended id filter size = 0 */
		}

		/* calculate RX FIFO 0 start address */
		if(0u < lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize)
		{
			GpCan_MsgRamSectionInfo[Channel].mRxFifo0StartAddr = GpCan_RamBufferCurrentAddr[lModuleId];
			/* FD support */
			if(TRUE == lControllerConfig->mNodeBaudrate.mFdEnabled)
			{
				GpCan_RamBufferCurrentAddr[lModuleId] += (lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize * GPCAN_MSGRAM_RXFDFIFO_ELEMENT_SIZE);
			}
			else
			{
				GpCan_RamBufferCurrentAddr[lModuleId] += (lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize * GPCAN_MSGRAM_RXFIFO_ELEMENT_SIZE);
			}
		}

		/* calculate RX FIFO 1 start address */
		if(0u < lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize)
		{
			GpCan_MsgRamSectionInfo[Channel].mRxFifo1StartAddr = GpCan_RamBufferCurrentAddr[lModuleId];
			/* FD support */
			if(TRUE == lControllerConfig->mNodeBaudrate.mFdEnabled)
			{
				GpCan_RamBufferCurrentAddr[lModuleId] += (lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize * GPCAN_MSGRAM_RXFDFIFO_ELEMENT_SIZE);
			}
			else
			{
				GpCan_RamBufferCurrentAddr[lModuleId] += (lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize * GPCAN_MSGRAM_RXFIFO_ELEMENT_SIZE);
			}
		}

		/* calculate TX Buffer Element Count */
		lTxBufferElementCount = 0u;
		lTxEventFifoSize = 0u;
		if(0 < lControllerConfig->mNodeTxMessage.mTxFifoSize)
		{
			lTxBufferElementCount += lControllerConfig->mNodeTxMessage.mTxFifoSize;
			lTxEventFifoSize += 1u;
		}
		if(0 < lControllerConfig->mNodeTxMessage.mTxQueue0Size)
		{
			lTxBufferElementCount += lControllerConfig->mNodeTxMessage.mTxQueue0Size;
			lTxEventFifoSize += lControllerConfig->mNodeTxMessage.mTxQueue0Size;
		}
		if(0 < lControllerConfig->mNodeTxMessage.mTxQueue1Size)
		{
			lTxBufferElementCount += lControllerConfig->mNodeTxMessage.mTxQueue1Size;
			lTxEventFifoSize += lControllerConfig->mNodeTxMessage.mTxQueue1Size;
		}
		if(0 < lControllerConfig->mNodeTxMessage.mDedicatedBufferSize)
		{
			lTxBufferElementCount += lControllerConfig->mNodeTxMessage.mDedicatedBufferSize;
			lTxEventFifoSize += lControllerConfig->mNodeTxMessage.mDedicatedBufferSize;
		}
		GpCan_MsgRamSectionInfo[Channel].mTxEventFifoSize = lTxEventFifoSize;


		/* calculate TX event start address */
		if(0 < GpCan_MsgRamSectionInfo[Channel].mTxEventFifoSize)
		{
			GpCan_MsgRamSectionInfo[Channel].mTxEventFifoStartAddr = GpCan_RamBufferCurrentAddr[lModuleId];
			GpCan_RamBufferCurrentAddr[lModuleId] += (GpCan_MsgRamSectionInfo[Channel].mTxEventFifoSize * GPCAN_MSGRAM_TXEVENT_ELEMENT_SIZE);
		}

		/* calculate tx buffer start address */
		if(0 < lTxBufferElementCount)
		{
			GpCan_MsgRamSectionInfo[Channel].mTxBufferStartAddr = GpCan_RamBufferCurrentAddr[lModuleId];
			/* FD support */
			if(TRUE == lControllerConfig->mNodeBaudrate.mFdEnabled)
			{
				GpCan_RamBufferCurrentAddr[lModuleId] += (lTxBufferElementCount * GPCAN_MSGRAM_RXFDFIFO_ELEMENT_SIZE);
			}
			else
			{
				GpCan_RamBufferCurrentAddr[lModuleId] += (lTxBufferElementCount * GPCAN_MSGRAM_RXFIFO_ELEMENT_SIZE);
			}
		}
	}
}

static inline void GpCan_StandardFilterSetting(uint8 Channel)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId;
	uint8 						 lModuleId;

	Ifx_CAN_STDMSG              *lSIDFilterDataPtr = NULL_PTR;
	uint32 						 lSIDFilterStartAddr = 0u;

	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(0u != GpCan_MsgRamSectionInfo[Channel].mStdFilterStartAddr)
		{
			/* Read Standard Identifier filter Start address */
			lSIDFilterStartAddr = GpCan_MsgRamSectionInfo[Channel].mStdFilterStartAddr;

			/* Load with Start address offset */
			lNodeRegAddressPtr->SIDFC.B.FLSSA = ((uint16)((lSIDFilterStartAddr & GPCAN_RAM_ADDRESS_OFFSET_MASK) >> 2u));

			/* Set with Standard section RAM size */
			lNodeRegAddressPtr->SIDFC.B.LSS = (uint8)GpCan_MsgRamSectionInfo[Channel].mStdFilterSize;


			if(   (  (0u < lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize) && (MESSAGE_ID_TYPE_STANDARD == lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxMsgIdType) )
				&&(  (0u < lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize) && (MESSAGE_ID_TYPE_STANDARD == lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxMsgIdType) )
			  )
			{
				lSIDFilterDataPtr = (Ifx_CAN_STDMSG *)lSIDFilterStartAddr;
				lSIDFilterDataPtr->S0.B.SFT = 0x02u; 	/* Calssic Filter*/
				lSIDFilterDataPtr->S0.B.SFEC = 0x01u; 	/* Store in Rx FIFO 0 if filter matches */
				lSIDFilterDataPtr->S0.B.SFID1 = lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoFilter.mFilterMsgId; 	/* SFID1 = filter id */
				lSIDFilterDataPtr->S0.B.SFID2 = lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoFilter.mFilterMask; 	/* SFID2 = mask */

				lSIDFilterDataPtr = (Ifx_CAN_STDMSG *)(lSIDFilterStartAddr + GPCAN_MSGRAM_STDFILTER_ELEMENT_SIZE);
				lSIDFilterDataPtr->S0.B.SFT = 0x02u; 	/* Calssic Filter*/
				lSIDFilterDataPtr->S0.B.SFEC = 0x02u; 	/* Store in Rx FIFO 1 if filter matches */
				lSIDFilterDataPtr->S0.B.SFID1 = lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoFilter.mFilterMsgId; 	/* SFID1 = filter id */
				lSIDFilterDataPtr->S0.B.SFID2 = lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoFilter.mFilterMask; 	/* SFID2 = mask */

			}
			else if( (0u < lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize) && (MESSAGE_ID_TYPE_STANDARD == lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxMsgIdType) )
			{
				lSIDFilterDataPtr = (Ifx_CAN_STDMSG *)lSIDFilterStartAddr;
				lSIDFilterDataPtr->S0.B.SFT = 0x02u; 	/* Calssic Filter*/
				lSIDFilterDataPtr->S0.B.SFEC = 0x01u; 	/* Store in Rx FIFO 0 if filter matches */
				lSIDFilterDataPtr->S0.B.SFID1 = lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoFilter.mFilterMsgId; 	/* SFID1 = filter id */
				lSIDFilterDataPtr->S0.B.SFID2 = lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoFilter.mFilterMask; 	/* SFID2 = mask */
			}
			else if( (0u < lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize) && (MESSAGE_ID_TYPE_STANDARD == lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxMsgIdType) )
			{
				lSIDFilterDataPtr = (Ifx_CAN_STDMSG *)lSIDFilterStartAddr;
				lSIDFilterDataPtr->S0.B.SFT = 0x02u; 	/* Calssic Filter*/
				lSIDFilterDataPtr->S0.B.SFEC = 0x02u; 	/* Store in Rx FIFO 1 if filter matches */
				lSIDFilterDataPtr->S0.B.SFID1 = lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoFilter.mFilterMsgId; 	/* SFID1 = filter id */
				lSIDFilterDataPtr->S0.B.SFID2 = lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoFilter.mFilterMask; 	/* SFID2 = mask */
			}
			else
			{}
		}
	}
}

static inline void GpCan_ExtendedFilterSetting(uint8 Channel)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId;
	uint8 						 lModuleId;

	Ifx_CAN_EXTMSG              *lXIDFilterDataPtr = NULL_PTR;
	uint32 						 lXIDFilterStartAddr = 0u;

	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(0u != GpCan_MsgRamSectionInfo[Channel].mExtFilterStartAddr)
		{
			/* Read Standard Identifier filter Start address */
			lXIDFilterStartAddr = GpCan_MsgRamSectionInfo[Channel].mExtFilterStartAddr;

			/* Load with Start address offset */
			lNodeRegAddressPtr->XIDFC.B.FLESA = ((uint16)((lXIDFilterStartAddr & GPCAN_RAM_ADDRESS_OFFSET_MASK) >> 2u));

			/* Set with Extended section RAM size */
			lNodeRegAddressPtr->XIDFC.B.LSE = (uint8)GpCan_MsgRamSectionInfo[Channel].mExtFilterSize;


			if(   (  (0u < lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize) && (MESSAGE_ID_TYPE_EXTENDED == lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxMsgIdType) )
			    &&(  (0u < lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize) && (MESSAGE_ID_TYPE_EXTENDED == lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxMsgIdType) )
			  )
			{
				lXIDFilterDataPtr = (Ifx_CAN_EXTMSG *)lXIDFilterStartAddr;
				lXIDFilterDataPtr->F1.B.EFT = 0x02u; 	/* Calssic Filter*/
				lXIDFilterDataPtr->F0.B.EFEC = 0x01u; 	/* Store in Rx FIFO 0 if filter matches */
				lXIDFilterDataPtr->F0.B.EFID1 = lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoFilter.mFilterMsgId; 	/* EFID1 = filter id */
				lXIDFilterDataPtr->F1.B.EFID2 = lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoFilter.mFilterMask; 	/* EFID2 = mask */

				lXIDFilterDataPtr = (Ifx_CAN_EXTMSG *)(lXIDFilterStartAddr + GPCAN_MSGRAM_XTDFILTER_ELEMENT_SIZE);
				lXIDFilterDataPtr->F1.B.EFT = 0x02u; 	/* Calssic Filter*/
				lXIDFilterDataPtr->F0.B.EFEC = 0x02u; 	/* Store in Rx FIFO 1 if filter matches */
				lXIDFilterDataPtr->F0.B.EFID1 = lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoFilter.mFilterMsgId; 	/* EFID1 = filter id */
				lXIDFilterDataPtr->F1.B.EFID2 = lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoFilter.mFilterMask; 	/* EFID2 = mask */

			}
			else if( (0u < lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize) && (MESSAGE_ID_TYPE_EXTENDED == lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxMsgIdType) )
			{
				lXIDFilterDataPtr = (Ifx_CAN_EXTMSG *)lXIDFilterStartAddr;
				lXIDFilterDataPtr->F1.B.EFT = 0x02u; 	/* Calssic Filter*/
				lXIDFilterDataPtr->F0.B.EFEC = 0x01u; 	/* Store in Rx FIFO 0 if filter matches */
				lXIDFilterDataPtr->F0.B.EFID1 = lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoFilter.mFilterMsgId; 	/* EFID1 = filter id */
				lXIDFilterDataPtr->F1.B.EFID2 = lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoFilter.mFilterMask; 	/* EFID2 = mask */
			}
			else if( (0u < lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize) && (MESSAGE_ID_TYPE_EXTENDED == lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxMsgIdType) )
			{
				lXIDFilterDataPtr = (Ifx_CAN_EXTMSG *)lXIDFilterStartAddr;
				lXIDFilterDataPtr->F1.B.EFT = 0x02u; 	/* Calssic Filter*/
				lXIDFilterDataPtr->F0.B.EFEC = 0x02u; 	/* Store in Rx FIFO 1 if filter matches */
				lXIDFilterDataPtr->F0.B.EFID1 = lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoFilter.mFilterMsgId; 	/* EFID1 = filter id */
				lXIDFilterDataPtr->F1.B.EFID2 = lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoFilter.mFilterMask; 	/* EFID2 = mask */
			}
			else
			{}
		}
	}
}

static inline void GpCan_RxMessageInit(uint8 Channel)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId;
	uint8 						 lModuleId;
	Ifx_CAN_N_RX_F0C 			 lRxTempFIFO0Config;
	Ifx_CAN_N_RX_F1C 			 lRxTempFIFO1Config;
	Ifx_CAN_N_RX_ESC 			 lRxTempBuffSizeConfig;

	lRxTempFIFO0Config.U = 0u;
	lRxTempFIFO1Config.U = 0u;
	lRxTempBuffSizeConfig.U = 0u;

	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		/* Set Filter for reject non matching and RTR message */
		lNodeRegAddressPtr->GFC.U = GPCAN_GFC_REJT_RTR_NONMATCH;

		if(0u != GpCan_MsgRamSectionInfo[Channel].mRxFifo0StartAddr)
		{
		    /* Set Offset for the F0SA */
			lRxTempFIFO0Config.B.F0SA =(uint16)((GpCan_MsgRamSectionInfo[Channel].mRxFifo0StartAddr & GPCAN_RAM_ADDRESS_OFFSET_MASK) >> 2u);
		    /* Set with the Rx FIFO0 Size*/
			lRxTempFIFO0Config.B.F0S = lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoSize;
		    /* Set with the Rx FIFO0 Threshold (WatermarkLevel)*/
			lRxTempFIFO0Config.B.F0WM = 1u;

			/* Set RX Buffer Data Field Size for FD support */
			if(TRUE == lControllerConfig->mNodeBaudrate.mFdEnabled)
			{
				/*Data Field Size*/
				lRxTempBuffSizeConfig.B.F0DS = 7u; /*111B 64-byte data field  000B 8-byte data field*/
			}


			lNodeRegAddressPtr->RX.F0C.U = lRxTempFIFO0Config.U;
		}

		if(0u != GpCan_MsgRamSectionInfo[Channel].mRxFifo1StartAddr)
		{
		    /* Set Offset for the F0SA */
			lRxTempFIFO1Config.B.F1SA =(uint16)((GpCan_MsgRamSectionInfo[Channel].mRxFifo1StartAddr & GPCAN_RAM_ADDRESS_OFFSET_MASK) >> 2u);
		    /* Set with the Rx FIFO0 Size*/
			lRxTempFIFO1Config.B.F1S = lControllerConfig->mNodeRxMessage.mRxFifo1Config.mRxFifoSize;
		    /* Set with the Rx FIFO0 Threshold (WatermarkLevel)*/
			lRxTempFIFO1Config.B.F1WM = 1u;

			/* Set RX Buffer Data Field Size for FD support */
			if(TRUE == lControllerConfig->mNodeBaudrate.mFdEnabled)
			{
				/*Data Field Size*/
				lRxTempBuffSizeConfig.B.F1DS = 7u;/*111B 64-byte data field  000B 8-byte data field*/
			}

			lNodeRegAddressPtr->RX.F1C.U = lRxTempFIFO1Config.U;
		}

		/* Set Rx Message RAM data Size */
		lNodeRegAddressPtr->RX.ESC.U = lRxTempBuffSizeConfig.U;
	}
}

static inline void GpCan_TxMessageInit(uint8 Channel)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId;
	uint8 						 lModuleId;

	Ifx_CAN_N_TX_EFC  			 lTxTempEvntReg;
	Ifx_CAN_N_TX_BC  			 lTxTempbuffReg;
	Ifx_CAN_N_TX_ESC  			 lTxTempbuffSizeReg;

	lTxTempEvntReg.U = 0u;
	lTxTempbuffReg.U = 0u;
	lTxTempbuffSizeReg.U = 0u;
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(0u != GpCan_MsgRamSectionInfo[Channel].mTxBufferStartAddr)
		{
			/* Set TX Event FIFO Size */
			lTxTempEvntReg.B.EFS = GpCan_MsgRamSectionInfo[Channel].mTxEventFifoSize;
			/* Set Tx Event FIFO Configuration register with Event FIFO Start Address*/
			lTxTempEvntReg.B.EFSA = (uint16)((GpCan_MsgRamSectionInfo[Channel].mTxEventFifoStartAddr & GPCAN_RAM_ADDRESS_OFFSET_MASK) >> 2u);

			/* Set Offset for the TSBA */
			lTxTempbuffReg.B.TBSA = (uint16)((GpCan_MsgRamSectionInfo[Channel].mTxBufferStartAddr & GPCAN_RAM_ADDRESS_OFFSET_MASK) >> 2u);

			/* Set for TX FIFO operation */
			lTxTempbuffReg.B.TFQM = 0u;/*TX FIFO/Queue Mode [0B:TX FIFO operation	1B:TX Queue operation]*/
			/* Set TX FIFO size */
			lTxTempbuffReg.B.TFQS = lControllerConfig->mNodeTxMessage.mTxFifoSize;
			/* Set No of used TX dedicated buffer */
			lTxTempbuffReg.B.NDTB = 	lControllerConfig->mNodeTxMessage.mTxQueue0Size
					                + 	lControllerConfig->mNodeTxMessage.mTxQueue1Size
									+ 	lControllerConfig->mNodeTxMessage.mDedicatedBufferSize;

			/* Set Tx Buffer Data Field Size for FD support */
			if(TRUE == lControllerConfig->mNodeBaudrate.mFdEnabled)
			{
				/*Data Field Size*/
				lTxTempbuffSizeReg.B.TBDS = 7u;/*111B 64-byte data field  000B 8-byte data field*/
			}

			/* Set Event FIFO configuration Register */
			lNodeRegAddressPtr->TX.EFC.U = lTxTempEvntReg.U;

		    /* Set Tx message buffer configuration Register */
		    lNodeRegAddressPtr->TX.BC.U = lTxTempbuffReg.U;

		    /* Set Tx message buffer size configuration Register */
		    lNodeRegAddressPtr->TX.ESC.U = lTxTempbuffSizeReg.U;
		}
	}
}

static inline void GpCan_ModuleInit(uint8 Module)
{
	Ifx_CAN						*lMCMBaseAddressPtr;
	uint32 						 lClockSelConfigValue;
	uint8						 lLoopIdx;
	uint16                       cpu_wdt_password;


	lMCMBaseAddressPtr = (Ifx_CAN *)GpCan_ModuleBaseAddress[Module];
//	Mcal_WritePeripEndInitProtReg((volatile void*)&(lMCMBaseAddressPtr->CLC), GPCAN_CLK_DISABLE);
//	while(GPCAN_MODULE_DISABLE_STATUS == (lMCMBaseAddressPtr->CLC.U & GPCAN_MODULE_DISABLE_STATUS) );
	cpu_wdt_password = IfxScuWdt_getCpuWatchdogPassword();
	IfxScuWdt_clearCpuEndinit(cpu_wdt_password);
	lMCMBaseAddressPtr->CLC.U = GPCAN_CLK_DISABLE;
	IfxScuWdt_setCpuEndinit(cpu_wdt_password);

	lClockSelConfigValue = 0u;
	for(lLoopIdx = 0u; lLoopIdx < GPCAN_NODE_NUMBER_EACH_MODULE; lLoopIdx++)
	{
		lClockSelConfigValue |= GPCAN_MCR_CLKSEL_SET << (lLoopIdx * 2u);
	}
    /* Set MCR.CI and MCR.CCCE to enable clock selection register write */
	lMCMBaseAddressPtr->MCR.U |= GPCAN_CLKSEL_WRITE_ENABLE;
    /*
    Set Clock selection for both Sync and Sync of selected Nodes in the
    SubSystem.
    */
	lMCMBaseAddressPtr->MCR.U |= (uint32)lClockSelConfigValue;
    /* Reset MCR.CI and MCR.CCCE to Clock Change disabled  */
	lMCMBaseAddressPtr->MCR.U = lClockSelConfigValue;
}

static void GpCan_IrqInit(uint8 Channel)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;
	uint8                        lInterruptLineStart = 0u;
	uint8                        lLine = 0u;

	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lInterruptLineStart = lNodeId * 4u;/* four interrupt lines were used for each controller */

		if( (GPCAN_MODULE_NUMBER_MAX > lModuleId) && (GPCAN_NODE_NUMBER_EACH_MODULE > lNodeId) )
		{
			for(lLine = 0u; lLine < 3u;/* three interrupt lines were actually used for each controller */ lLine++)
			{
				if(0 < GpCan_InterruptSets[lModuleId][lInterruptLineStart + lLine].mSRPN)
				{
					/*
					 * interrupt line 0: RX FIFO0 new data
					 * interrupt line 1: RX FIFO1 new data
					 * interrupt line 2: TX event
					 * */
					/* Set CLRR to clear SRR bit and disable SRE bit */
					MODULE_SRC.CAN.CAN[lModuleId].INT[lInterruptLineStart + lLine].U = GPCAN_IRQ_DISABLE_CLEAR_SRC;
					/* Type of Service Control is written to the SRC registers*/
					MODULE_SRC.CAN.CAN[lModuleId].INT[lInterruptLineStart + lLine].B.TOS = GpCan_InterruptSets[lModuleId][lInterruptLineStart + lLine].mTOS;
					/* Interrupt Priority is written to the SRC registers*/
					MODULE_SRC.CAN.CAN[lModuleId].INT[lInterruptLineStart + lLine].B.SRPN = GpCan_InterruptSets[lModuleId][lInterruptLineStart + lLine].mSRPN;
					/* Service Request Enable is written to the SRC registers*/
					MODULE_SRC.CAN.CAN[lModuleId].INT[lInterruptLineStart + lLine].B.SRE = 1u;
				}
			}
		}
	}
}

static void GpCan_EnableControllerInterrupts(uint8 Channel)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(CAN_EVENT_HANDLING_INTERRUPT == lControllerConfig->mEventHandle.mRxEventHandle)
		{
			lNodeRegAddressPtr->IE.B.RF0NE = 1u;
			lNodeRegAddressPtr->IE.B.RF1NE = 1u;
		}

		if(CAN_EVENT_HANDLING_INTERRUPT == lControllerConfig->mEventHandle.mTxEventHandle)
		{
			/*lNodeRegAddressPtr->IE.B.TCE = 1u;*/
			lNodeRegAddressPtr->IE.B.TEFNE = 1u;
		}
		/*lNodeRegAddressPtr->IE.B.BOE = 1u;*/
	}
}

static void GpCan_TxEventHandler(uint8 Channel)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	const Ifx_CAN_TXEVENT       *lTxEvntReadData;
	uint8 						 lTxEvntFillLvlVal = 0u;
	uint8 						 lLoopExitFlag = 0u;
	uint32 						 lTxEvntFIFOstartAddr;
	uint32 						 lTxEvntFIFORealAddr;
	uint32 						 lTxEvntFIFOGetIndex;
	uint16 			             lTxHandleIndx;

	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];


		/* Set Tx Event FIFO Start Address */
		lTxEvntFIFOstartAddr = GpCan_MsgRamSectionInfo[Channel].mTxEventFifoStartAddr;
		/* Set safety loop exit flag with value zero */
		lLoopExitFlag = 0u;
		/* Read Fill Level value */
		lTxEvntFillLvlVal = lNodeRegAddressPtr->TX.EFS.B.EFFL;

		/* Read Tx event FIFO register for read No of stored Events */
		while( (0u != lTxEvntFillLvlVal) && (GPCAN_NOOF_TX_HW_BUFF_AVAILABLE > lLoopExitFlag) )
		{
		    /* Read TxEvent buffer index */
		    lTxEvntFIFOGetIndex = lNodeRegAddressPtr->TX.EFS.B.EFGI;
		    /* Set Real Event FIFO element address */
		    lTxEvntFIFORealAddr = lTxEvntFIFOstartAddr + (lTxEvntFIFOGetIndex * (uint32)GPCAN_MSGRAM_TXEVENT_ELEMENT_SIZE);

		    /* Load EventFIFO element address */
		    lTxEvntReadData = (Ifx_CAN_TXEVENT*)lTxEvntFIFORealAddr;

		    /* Read Message Marker */
		    lTxHandleIndx = (uint16)lTxEvntReadData->E1.B.MM;

		    Can_TxConfirmation(Channel, lTxEvntReadData);

		    /* Acknowledge shall set to free the Tx Event FIFO */
		    lNodeRegAddressPtr->TX.EFA.B.EFAI =(uint8)lTxEvntFIFOGetIndex;

		    GpCan_TxQueueStatus[lModuleId][lNodeId].mQueueState[lTxHandleIndx] = GpCan_TxQueueState_Idle;

		    /* Increment exit loop condition for safety */
		    lLoopExitFlag++;

		    /* Read Fill Level value */
		    lTxEvntFillLvlVal =  lNodeRegAddressPtr->TX.EFS.B.EFFL;
		}
	}
}

static void GpCan_RxMsgStructInit(Can_Message_t *CanRxMsgPtr)
{
	uint8				lLoopIdx;
	if(NULL_PTR != CanRxMsgPtr)
	{
		CanRxMsgPtr->BRS = 0u;
		CanRxMsgPtr->CanId = 0u;
		CanRxMsgPtr->DLC = 0u;
		CanRxMsgPtr->FDF = 0u;
		CanRxMsgPtr->XTD = 0u;

		for(lLoopIdx = 0u; lLoopIdx < 16u; lLoopIdx++)
		{
			CanRxMsgPtr->MessageData.Word[lLoopIdx] = 0u;
		}
	}
}

static void GpCan_RxExtractData(uint8 Channel, uint8 RxBuffIndex, GpCan_RxBufferType RxBufferType)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	Can_Message_t                lCanRxMsg;
	const Ifx_CAN_RXMSG         *lRxMsgRAMPtr;
	uint32                       lRxReadStartAddr;
	uint32                       lRxReadOffsetAddr;
	uint8                        lRxMsgDLC;
	uint8                        lRxMsgFilterIndx;
	uint8                        lRxMsgCnt;
	uint32                       lRxMsgId;

	lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
	lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
	lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
	lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];


	GpCan_RxMsgStructInit(&lCanRxMsg);

	if(GPCAN_RX_FIFO0 == RxBufferType)
	{   /* Read Rx Message RAM start address of RXFIFO0 */
		lRxReadStartAddr = GpCan_MsgRamSectionInfo[Channel].mRxFifo0StartAddr;
	}
	else if(GPCAN_RX_FIFO1 == RxBufferType)
	{   /* Read Rx Message RAM start address of RXFIFO1 */
		lRxReadStartAddr = GpCan_MsgRamSectionInfo[Channel].mRxFifo1StartAddr;
	}
	else
	{   /* Set Rx Message RAM start address of dedicated buffer */
		lRxReadStartAddr = 0u;
	}

	/* Set OFFSET address with  buffer position */
	lRxReadOffsetAddr = RxBuffIndex;
	if(0u != lRxReadStartAddr)
	{
		/* Load the data receive message buffer address */
		if(TRUE == lControllerConfig->mNodeBaudrate.mFdEnabled)
		{
			lRxReadStartAddr = lRxReadStartAddr + (lRxReadOffsetAddr * GPCAN_MSGRAM_RXFDFIFO_ELEMENT_SIZE);
		}
		else
		{
			lRxReadStartAddr = lRxReadStartAddr + (lRxReadOffsetAddr * GPCAN_MSGRAM_RXFIFO_ELEMENT_SIZE);
		}

		/* Load the data receive message buffer address */
		lRxMsgRAMPtr = (Ifx_CAN_RXMSG *)lRxReadStartAddr;
	    /* Extract DLC information */
	    lRxMsgDLC = lRxMsgRAMPtr->R1.B.DLC;
	    /* Read Filter Index */
	    lRxMsgFilterIndx = lRxMsgRAMPtr->R1.B.FIDX;

	    /* Extract receive Msg.ID  and ID Type */
	    if (0u == lRxMsgRAMPtr->R0.B.XTD)
	    {
			/* Read received message Id and Message type */
			lRxMsgId = lRxMsgRAMPtr->R0.B.ID >> 18u;
	    }
	    else
	    {
			/* Set message ID type as Extended */
			/*lRxMsgId = GPCAN_SET_XTD_BIT_MASK;*/
			/* Copy message ID  */
			/*lRxMsgId |= (uint32)lRxMsgRAMPtr->R0.B.ID;*/
	    	lRxMsgId = (uint32)lRxMsgRAMPtr->R0.B.ID;

			lCanRxMsg.XTD = 1u;
	    }
	    lCanRxMsg.CanId = lRxMsgId;

	    /* Read receive data information from R1 RAM element */
	    if( 1u == lRxMsgRAMPtr->R1.B.FDF)
		{
			/* Set FD bit of MsgId */
			/*lRxMsgId |= (uint32)GPCAN_SET_FD_MASK;*/
	    	lCanRxMsg.FDF = 1u;
		}
	    /* Clear to read from Byte0 */
	    lRxMsgCnt = 0u;
	    /* Convert DLC length to Number of Data Bytes supported by Hw */
	    lRxMsgDLC = GpCan_DlcConvDataByte[lRxMsgDLC];
	    lCanRxMsg.DLC = lRxMsgDLC;

	    /* Copy Message from RAM section to local data buffer */
	    while(lRxMsgCnt < lRxMsgDLC)
	    {
			/* copy data from byte0 to n the buffer */
	    	lCanRxMsg.MessageData.Byte[lRxMsgCnt] = lRxMsgRAMPtr->DB[lRxMsgCnt].U;
			/* Increment to point next byte */
			lRxMsgCnt++;
	    }

	    lCanRxMsg.BRS = lRxMsgRAMPtr->R1.B.BRS;
	    lCanRxMsg.RXTS = lRxMsgRAMPtr->R1.B.RXTS;


	    /* Call CanIf_RxIndication function with receive message information */
	    Can_RxIndication(0, &lCanRxMsg);
	}
}

static void GpCan_ReceiveHandler(uint8 Channel)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	uint8 						 lRxHandleBuffPos;
	uint8 						 lRxFillLvlVal;
	uint8 						 lLoopExitFlag;

	lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
	lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
	lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
	lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

	/*Recieve data buffer is RXFIFO0*/
	{
		/* Check Received CAN message is lost or not */
		if(0u == lNodeRegAddressPtr->RX.F0S.B.RF0L)
		{
			/* Set safety loop exit flag with value zero */
			lLoopExitFlag = 0u;
			/* Read Fill Level value */
			lRxFillLvlVal = lNodeRegAddressPtr->RX.F0S.B.F0FL;
			/* Check if any of the message received by RXFIFO0 */
			while(lLoopExitFlag < lRxFillLvlVal)
			{
				/* Read Rx FIFO 0 Get Index */
				lRxHandleBuffPos = lNodeRegAddressPtr->RX.F0S.B.F0GI;
				/* Invoke data retrieve function */
				GpCan_RxExtractData(Channel, lRxHandleBuffPos, GPCAN_RX_FIFO0);
				/* Set read Acknowledge of buffer */
				lNodeRegAddressPtr->RX.F0A.U = lRxHandleBuffPos;
				/* Increment exit loop condition for safety */
				lLoopExitFlag++;
			}
		}
		else
		{
			/*clear interrupt state */
			lNodeRegAddressPtr->IR.B.RF0L = 1u;
		}
	}

	/*Recieve data buffer is RXFIFO1*/
	{
		if(0u == lNodeRegAddressPtr->RX.F1S.B.RF1L)
		{
			/* Set safety loop exit flag with value zero */
			lLoopExitFlag = 0u;
			/* Read Fill Level value */
			lRxFillLvlVal = lNodeRegAddressPtr->RX.F1S.B.F1FL;
			/* Check if any of the message received by RXFIFO1 */
			while(lLoopExitFlag < lRxFillLvlVal)
			{
				/* Read Rx FIFO 1 Get Index */
				lRxHandleBuffPos = lNodeRegAddressPtr->RX.F1S.B.F1GI;
				/* Invoke data retrieve function */
				GpCan_RxExtractData(Channel, lRxHandleBuffPos, GPCAN_RX_FIFO1);
				/* Set read Acknowledge of buffer */
				lNodeRegAddressPtr->RX.F1A.U = lRxHandleBuffPos;
				/* Increment exit loop condition for safety */
				lLoopExitFlag++;
			}
		}
		else
		{
			/*clear interrupt state */
			lNodeRegAddressPtr->IR.B.RF1L = 1u;
		}
	}

}



static void GpCan_IsrRxFIFO0Handler(uint8 Controller)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	uint8						 lChannel;

	lChannel = GpCan_ControllerChannel[Controller];
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > lChannel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[lChannel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(CAN_EVENT_HANDLING_POLLING != lControllerConfig->mEventHandle.mRxEventHandle)
		{
			if( 1u == lNodeRegAddressPtr->IR.B.RF0N )
			{
				GpCan_ReceiveHandler(lChannel);

				/* Reset flag for New message to RXFIFO0 */
			    for(uint8 lClearCnt = 0; lClearCnt < GPCAN_CLEAR_IR_RETRY_TIMES; lClearCnt++)
			    {
				   /* After interrupt flag is cleared, it should be read back and check if it is really cleared,
				    * if not, do the clear again until it is really cleared */
				   /* See MCMCAN_AI.H001 in errata sheet */
					lNodeRegAddressPtr->IR.U = GPCAN_CLEAR_IE_RF0N_BIT;
				    if(0u == lNodeRegAddressPtr->IR.B.RF0N)
				    {
					    break;
				    }
			    }

			}
		}
	}
}

static void GpCan_IsrRxFIFO1Handler(uint8 Controller)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	uint8						 lChannel;

	lChannel = GpCan_ControllerChannel[Controller];
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > lChannel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[lChannel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(CAN_EVENT_HANDLING_POLLING != lControllerConfig->mEventHandle.mRxEventHandle)
		{
			if( 1u == lNodeRegAddressPtr->IR.B.RF1N )
			{
				GpCan_ReceiveHandler(lChannel);

				/* Reset flag for New message to RXFIFO1 */
			    for(uint8 lClearCnt = 0; lClearCnt < GPCAN_CLEAR_IR_RETRY_TIMES; lClearCnt++)
			    {
				   /* After interrupt flag is cleared, it should be read back and check if it is really cleared,
				    * if not, do the clear again until it is really cleared */
				   /* See MCMCAN_AI.H001 in errata sheet */
					lNodeRegAddressPtr->IR.U = GPCAN_CLEAR_IE_RF1N_BIT;
				    if(0u == lNodeRegAddressPtr->IR.B.RF1N)
				    {
					   break;
				    }
			    }

			}
		}
	}
}

static void GpCan_IsrTxCompletedHandler(uint8 Controller)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	uint8						 lChannel;

	lChannel = GpCan_ControllerChannel[Controller];
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > lChannel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[lChannel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(CAN_EVENT_HANDLING_POLLING != lControllerConfig->mEventHandle.mTxEventHandle)
		{
			if(1u == lNodeRegAddressPtr->IR.B.TEFN)
			{
				GpCan_TxEventHandler(lChannel);

				/* Reset flag for next TxEvent Entry */
			    for(uint8 lClearCnt = 0; lClearCnt < GPCAN_CLEAR_IR_RETRY_TIMES; lClearCnt++)
			    {
				   /* After interrupt flag is cleared, it should be read back and check if it is really cleared,
				    * if not, do the clear again until it is really cleared */
				   /* See MCMCAN_AI.H001 in errata sheet */
				   lNodeRegAddressPtr->IR.U = GPCAN_CLEAR_IE_TEFN_BIT;
				   if(0u == lNodeRegAddressPtr->IR.B.TEFN)
				   {
					   break;
				   }
			   }
//				lNodeRegAddressPtr->IR.U = GPCAN_CLEAR_IE_TEFN_BIT;
			}
		}
	}
}


static Can_ReturnValue_t GpCan_Write(uint8 Channel, uint8 TxBufferIndex, Can_Message_t *TranMsgPtr)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	Ifx_CAN_TXMSG				*lTxMsgBufferPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;
	uint32 						 lTxWriteStartAddr = 0u;
	uint32 						 lBuffIndex = 0u;
	uint8 						 lBuffElementIndex = 0u;
	uint8                        lTxMsgDlc = 0u;
	uint8 					     lDataBytePos = 0u;
	Can_ReturnValue_t			 lResult;

	lResult = CAN_RTN_NOK;
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		lTxWriteStartAddr = GpCan_MsgRamSectionInfo[Channel].mTxBufferStartAddr;

		lResult = CAN_RTN_OK;

		lBuffIndex = 0u;

		if(GPCAN_TX_BUFFER_INDEX_FIFO != TxBufferIndex)
		{
			/* Copy the buffer Index for Mask */
			lBuffIndex = (uint32)(1u << TxBufferIndex);
			/* Is buffer Free */
			if( 0u != (lNodeRegAddressPtr->TX.BRP.U & lBuffIndex) )
			{
				/* Set return value as Busy */
				lBuffElementIndex = 0u;
				lResult = CAN_RTN_NOK;
			}
			else
			{
				/* Copy the exact buffer element offset */
				lBuffElementIndex = TxBufferIndex;
				GpCan_TxQueueStatus[lModuleId][lNodeId].mQueueState[TxBufferIndex] = GpCan_TxQueueState_Pending;
			}
		}
		else
		{
			/* Check TXFIFO is Free or not */
			if(1u == lNodeRegAddressPtr->TX.FQS.B.TFQF)
			{
				lBuffElementIndex = 0u;
				lResult = CAN_RTN_NOK;
			}
			else
			{
				lBuffElementIndex = lNodeRegAddressPtr->TX.FQS.B.TFQPI;
				lBuffIndex = (uint32)(1 << lBuffElementIndex);
			}
		}

		if(CAN_RTN_OK == lResult)
		{
			/* Set buffer size with FD support */
			if(TRUE == lControllerConfig->mNodeBaudrate.mFdEnabled)
			{
				lTxWriteStartAddr = (lTxWriteStartAddr + (GPCAN_MSGRAM_TXFDBUFFER_ELEMENT_SIZE * lBuffElementIndex));
			}
			else
			{
				lTxWriteStartAddr = (lTxWriteStartAddr + (GPCAN_MSGRAM_TXBUFFER_ELEMENT_SIZE * lBuffElementIndex));
			}
			/* Set with Transmit message buffer0 pointer */
			lTxMsgBufferPtr = (Ifx_CAN_TXMSG*) lTxWriteStartAddr;
			/* Reset the T0 Msg buffer being accessed */
			lTxMsgBufferPtr->T0.U = (uint32)0u;
			/* Reset the RTR bit to avoid transmit messages triggered by remote transmission requests */
			lTxMsgBufferPtr->T0.B.RTR = 0u;

		    if(0u != TranMsgPtr->XTD)
		    {
				/* Store extended Id and set XTD bit */
				lTxMsgBufferPtr->T0.B.XTD = 1u;
				lTxMsgBufferPtr->T0.B.ID  = ((TranMsgPtr->CanId) & GPCAN_EXTENDED_ID_MASK);
		    }
		    else
		    {
				/* shift Standard Identifier to position 28..18 */
				lTxMsgBufferPtr->T0.B.ID = (TranMsgPtr->CanId & GPCAN_STANDARD_ID_MASK) << GPCAN_SHIFT_EIGHTEEN;
				/* Set Id Type as Standard */
				lTxMsgBufferPtr->T0.B.XTD = 0u;
		    }

			/* Set DLC with requested value */
			lTxMsgDlc = TranMsgPtr->DLC;
			lTxMsgBufferPtr->T1.U = (uint32)0u;
			if(0 != TranMsgPtr->FDF)
			{
				/* Set Tx message with FD */
				lTxMsgBufferPtr->T1.B.FDF = 1u;
			}
			else
			{
				/* Set Tx message with Normal */
				lTxMsgBufferPtr->T1.B.FDF = 0u;
			}

			if(0 != TranMsgPtr->BRS)
			{
				/* Enable BRS */
				lTxMsgBufferPtr->T1.B.BRS = 1u;
			}
			else
			{
				/* Disable BRS */
				lTxMsgBufferPtr->T1.B.BRS = 0u;
			}

			if(TranMsgPtr->DLC > GPCAN_SHIFT_TWENTYFOUR)
			{
				/* Set DLC length with Hw Supported value */
				lTxMsgDlc = (((TranMsgPtr->DLC + 15u) >> 4u) + 11u);
			}
			else if (TranMsgPtr->DLC > 8u)
			{
				/* Set DLC length with Hw Supported value */
				lTxMsgDlc = (((TranMsgPtr->DLC + 3u) >> 2u) + 6u);
			}
			else
			{/* Do Nothing */}

		    /* Write DLC value to the T1 buffer */
		    lTxMsgBufferPtr->T1.B.DLC = lTxMsgDlc;

		    /* Write Event FIFO */
		    lTxMsgBufferPtr->T1.B.EFC = 1u;

		    lTxMsgBufferPtr->T1.B.MM = lBuffElementIndex;

		    lDataBytePos = 0u;
		    lTxMsgDlc = GpCan_DlcConvDataByte[lTxMsgDlc];
		    while(lTxMsgDlc > lDataBytePos)
		    {
		    	if(lDataBytePos < TranMsgPtr->DLC)
		    	{
		    		/* Copy Message data to the Tx Buffer */
		    		lTxMsgBufferPtr->DB[lDataBytePos].U = TranMsgPtr->MessageData.Byte[lDataBytePos];
		    	}
		    	else
		    	{
		    		/* Store with padding values to the Tx buffer */
		    		lTxMsgBufferPtr->DB[lDataBytePos].U = 0u;
		    	}
		    	lDataBytePos++;
		    }

		    /*Request for the Transmission*/
		    lNodeRegAddressPtr->TX.BAR.U |= (Ifx_UReg_32Bit)lBuffIndex;
			while(( lNodeRegAddressPtr->TX.BTO.U &= (Ifx_UReg_32Bit)lBuffIndex) == 0){};
			
		}
	}

	return lResult;
}

uint8 Can_CheckBusError(uint8 Channel)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;
	uint8                        lBusoffError = 0u;
	uint32                       lTempInitStatus = 0u;
	uint32                       lTxPendingStatus = 0u;

	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		lTempInitStatus = lNodeRegAddressPtr->CCCR.B.INIT;

		if( (1u == lNodeRegAddressPtr->PSR.B.BO) && (1u == lTempInitStatus) )
		{
			/* Check for pending request */
			if(0u != lNodeRegAddressPtr->TX.BRP.U)
			{
				/* Read Pending Tx Request for buffer */
				lTxPendingStatus = lNodeRegAddressPtr->TX.BRP.U;
				/* Set the pending request with cancellation request */
				lNodeRegAddressPtr->TX.BCR.U = lTxPendingStatus;
			}

			/* Reset flag for next TxEvent Entry */
			lBusoffError = 1u;
		}
	}

	return lBusoffError;
}


void Can_ClearBusError(uint8 Channel)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	uint32						 lRegValue;
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		lRegValue = lNodeRegAddressPtr->PSR.U;
	}
}


void Can_ChInit(uint8 Channel)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	const volatile uint32       *lRegAddressPtr;
	uint8						 lNodeId;
	uint8 						 lModuleId;
	uint8 						 lIntLineOffset = 0u;

	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];
		GpCan_ControllerChannel[lControllerConfig->mNodeId] = Channel;

		if(FALSE == GpCan_ModuleIsInited[lModuleId])
		{
			GpCan_ModuleIsInited[lModuleId] = TRUE;
			GpCan_ModuleInit(lModuleId);
		}

		lIntLineOffset = 4u * lNodeId;

		/* Interrupt Line assignment for RXFIFO 0 New Data */
		lNodeRegAddressPtr->GRINT2.B.RXF0N = 0u + lIntLineOffset;
		/* Interrupt Line assignment for RXFIFO 1 New Data */
		lNodeRegAddressPtr->GRINT2.B.RXF1N = 1u + lIntLineOffset;
		/* Interrupt Line assignment for Transmission Completed */
		//lNodeRegAddressPtr->GRINT2.B.TRACO = 2u + lIntLineOffset;
		lNodeRegAddressPtr->GRINT1.B.TEFIFO = 2u + lIntLineOffset;

		/* Interrupt Line assignment for BUSOFF */
		/*lNodeRegAddressPtr->GRINT1.B.BOFF = 3u + lIntLineOffset;*/

		GpCan_EnableControllerInterrupts(Channel);
		GpCan_IrqInit(Channel);

		if(0u == lNodeRegAddressPtr->CCCR.B.INIT)
		{
			/* Set with Initialization mode */
			lNodeRegAddressPtr->CCCR.B.INIT = 1u;

			while(1u != lNodeRegAddressPtr->CCCR.B.INIT);
		}

		lNodeRegAddressPtr->CCCR.B.CCE = 1u;

		GpCan_SetNodeBitTiming(lNodeRegAddressPtr, lControllerConfig->mNodeBaudrate.mModuleFreq,
												   lControllerConfig->mNodeBaudrate.mBaudrate,
												   lControllerConfig->mNodeBaudrate.mSamplePoint,
												   lControllerConfig->mNodeBaudrate.mSyncJumpWidth);

		if(TRUE == lControllerConfig->mNodeBaudrate.mFdEnabled)
		{
			GpCan_SetNodeFastBitTiming(lNodeRegAddressPtr, lControllerConfig->mNodeBaudrate.mModuleFreq,
													       lControllerConfig->mNodeBaudrate.mFdBaudConfig.mFdBaudrate,
													       lControllerConfig->mNodeBaudrate.mFdBaudConfig.mFdSamplePoint,
													       lControllerConfig->mNodeBaudrate.mFdBaudConfig.mFdSyncJumpWidth);
			if(0u != lControllerConfig->mNodeBaudrate.mFdBaudConfig.mFdTransDelayOffset)
			{
				/* enable Transceiver Delay Compensation */
				lNodeRegAddressPtr->DBTP.B.TDC = 1u;
				/* set Transceiver Delay Compensation offset */
				lNodeRegAddressPtr->TDCR.B.TDCO = lControllerConfig->mNodeBaudrate.mFdBaudConfig.mFdTransDelayOffset;
			}

			/* Enable CANFD */
			lNodeRegAddressPtr->CCCR.B.FDOE = 1u;

			/* Enable baudrate switch */
			lNodeRegAddressPtr->CCCR.B.BRSE = 1u;
		}

		lNodeRegAddressPtr->NPCR.B.RXSEL = lControllerConfig->mRxSel;

		lNodeRegAddressPtr->TSCC.B.TSS = 0x2;    /* for canfd, TSS will be b'10 */
		lNodeRegAddressPtr->NT.CCR.B.TPSC = 0xF; /* 100MHz/(15+1) = 6.25MHz */
		lNodeRegAddressPtr->NT.CCR.B.STSTART = 0x1; /* start timestamp counter */

		/* Clear All pending Interrupts */
		lNodeRegAddressPtr->IR.U = GPCAN_CLEAR_ALL_INTERRUPTS;

		if(FALSE == GpCan_RamSectionInitState[lModuleId][lNodeId])
		{
			GpCan_RamSectionInitState[lModuleId][lNodeId] = TRUE;

			GpCan_MsgRamSectionInit(Channel);
			GpCan_CalcMsgRamSectionFromConfiguration(Channel);
		}

		GpCan_StandardFilterSetting(Channel);
		GpCan_ExtendedFilterSetting(Channel);
		GpCan_RxMessageInit(Channel);
		GpCan_TxMessageInit(Channel);


		/* Set CAN controller with normal operation mode */
		lNodeRegAddressPtr->CCCR.B.INIT = 0u;
		lRegAddressPtr = (const volatile uint32*) (&(lNodeRegAddressPtr->CCCR.U));
		while( GPCAN_NODE_INIT_MODE == (((uint32)*lRegAddressPtr) & GPCAN_NODE_INIT_MODE) );
	}
}




void Can_MainFunction_Read(void)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;
	uint8 						 lCtrlIndex = 0u;

	for(lCtrlIndex = 0u; lCtrlIndex < GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET; lCtrlIndex++)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[lCtrlIndex];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(CAN_EVENT_HANDLING_POLLING == lControllerConfig->mEventHandle.mRxEventHandle)
		{
			GpCan_ReceiveHandler(lCtrlIndex);
		}
	}
}



void Can_MainFunction_Write(void)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8 						 lCtrlIndex = 0u;

	for(lCtrlIndex = 0u; lCtrlIndex < GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET; lCtrlIndex++)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[lCtrlIndex];
		if(CAN_EVENT_HANDLING_POLLING == lControllerConfig->mEventHandle.mTxEventHandle)
		{
			GpCan_TxEventHandler(lCtrlIndex);
		}
	}
}

Can_ReturnValue_t Can_TxFIFO_Write(uint8 Channel, Can_Message_t *TranMsgPtr)
{
	Can_ReturnValue_t			 lResult;

	lResult = CAN_RTN_NOK;
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lResult = GpCan_Write(Channel, GPCAN_TX_BUFFER_INDEX_FIFO, TranMsgPtr);
	}

	return lResult;
}

Can_ReturnValue_t Can_TxQueue0_Write(uint8 Channel, Can_Message_t *TranMsgPtr)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	Can_ReturnValue_t			 lResult;
	uint8						 lLoopIdx;
	uint8						 lTxBufferIdx;
	uint32 						 lBuffIndex = 0u;

	lResult = CAN_RTN_NOK;
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(0u < lControllerConfig->mNodeTxMessage.mTxQueue0Size)
		{
			lTxBufferIdx = lControllerConfig->mNodeTxMessage.mDedicatedBufferSize;
			for(lLoopIdx = 0u; lLoopIdx < lControllerConfig->mNodeTxMessage.mTxQueue0Size; lLoopIdx++)
			{
				if(GpCan_TxQueueState_Idle == GpCan_TxQueueStatus[lModuleId][lNodeId].mQueueState[lTxBufferIdx])
				{
					/* Copy the buffer Index for Mask */
					lBuffIndex = (uint32)(1u << lTxBufferIdx);
					if( 0u == (lNodeRegAddressPtr->TX.BRP.U & lBuffIndex) )
					{
						break;
					}
					lTxBufferIdx++;
				}
			}

			if(lLoopIdx < lControllerConfig->mNodeTxMessage.mTxQueue0Size)
			{
				lResult = GpCan_Write(Channel, lTxBufferIdx, TranMsgPtr);
			}
		}
	}

	return lResult;
}

Can_ReturnValue_t Can_TxQueue1_Write(uint8 Channel, Can_Message_t *TranMsgPtr)
{
	Ifx_CAN_N 					*lNodeRegAddressPtr = NULL_PTR;
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	Can_ReturnValue_t			 lResult;
	uint8						 lLoopIdx;
	uint8						 lTxBufferIdx;
	uint32 						 lBuffIndex = 0u;

	lResult = CAN_RTN_NOK;
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);
		lNodeRegAddressPtr = (Ifx_CAN_N *)GpCan_NodeRegAddress[lModuleId][lNodeId];

		if(0u < lControllerConfig->mNodeTxMessage.mTxQueue1Size)
		{
			lTxBufferIdx = lControllerConfig->mNodeTxMessage.mDedicatedBufferSize + lControllerConfig->mNodeTxMessage.mTxQueue0Size;
			for(lLoopIdx = 0u; lLoopIdx < lControllerConfig->mNodeTxMessage.mTxQueue1Size; lLoopIdx++)
			{
				if(GpCan_TxQueueState_Idle == GpCan_TxQueueStatus[lModuleId][lNodeId].mQueueState[lTxBufferIdx])
				{
					lBuffIndex = (uint32)(1u << lTxBufferIdx);
					if( 0u == (lNodeRegAddressPtr->TX.BRP.U & lBuffIndex) )
					{
						break;
					}
					lTxBufferIdx++;
				}
			}

			if(lLoopIdx < lControllerConfig->mNodeTxMessage.mTxQueue1Size)
			{
				lResult = GpCan_Write(Channel, lTxBufferIdx, TranMsgPtr);
			}
		}
	}

	return lResult;
}

Can_ReturnValue_t Can_TxDedicatedBuffer_Write(uint8 Channel, uint8 TxBufferIndex, Can_Message_t *TranMsgPtr)
{
	GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;
	uint8						 lNodeId = 0u;
	uint8 						 lModuleId = 0u;

	Can_ReturnValue_t			 lResult;
	uint8                        lTxBufferCount = 0u;

	lResult = CAN_RTN_NOK;
	if(GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET > Channel)
	{
		lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
		lNodeId = GpCan_GetNodeIdFromControllerConfig(lControllerConfig->mNodeId);
		lModuleId = GpCan_GetModuleIdFromControllerConfig(lControllerConfig->mNodeId);

		if(0u < lControllerConfig->mNodeTxMessage.mDedicatedBufferSize)
		{
			lTxBufferCount = TxBufferIndex + lControllerConfig->mNodeTxMessage.mTxFifoSize
					       + lControllerConfig->mNodeTxMessage.mTxQueue0Size + lControllerConfig->mNodeTxMessage.mTxQueue1Size;
			if(GPCAN_TX_BUFFER_ELEMENT_MAX > lTxBufferCount)
			{
				lResult = GpCan_Write(Channel, TxBufferIndex, TranMsgPtr);
			}
		}
	}

	return lResult;
}

void Can_Configurre_Filters(unsigned          char Channel,unsigned int id)
{
  GpCan_ControllerConfigType	*lControllerConfig = NULL_PTR;

  lControllerConfig = &GpCan_ControllerConfigInfo[Channel];
  lControllerConfig->mNodeRxMessage.mRxFifo0Config.mRxFifoFilter.mFilterMsgId = id;	  /* SFID1 = filter id */

  GpCan_StandardFilterSetting(Channel);
}

typedef struct
{
	uint32 			RxFifo0Count;
	uint32 			RxFifo1Count;
	uint32 			TxCount;
}Ts_IrqCountType;

Ts_IrqCountType test_IrqCount[12];

#if (GPCAN_IRQ_CAN0_SR0_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR0_PRIO) __vector_table(0) CAN0Controller0_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN0Controller0_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN0_SR0_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	test_IrqCount[0].RxFifo0Count++;
	GpCan_IsrRxFIFO0Handler(CAN0_Controller0);
}
#endif

#if (GPCAN_IRQ_CAN0_SR1_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR1_PRIO) __vector_table(0) CAN0Controller0_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN0Controller0_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN0_SR1_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	test_IrqCount[0].RxFifo1Count++;
	GpCan_IsrRxFIFO1Handler(CAN0_Controller0);
}
#endif

#if (GPCAN_IRQ_CAN0_SR2_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR2_PRIO) __vector_table(0) CAN0Controller0_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN0Controller0_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN0_SR2_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	test_IrqCount[0].TxCount++;
	GpCan_IsrTxCompletedHandler(CAN0_Controller0);
}
#endif

#if (GPCAN_IRQ_CAN0_SR4_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR4_PRIO) __vector_table(0) CAN0Controller1_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN0Controller1_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN0_SR4_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	test_IrqCount[1].RxFifo0Count++;
	GpCan_IsrRxFIFO0Handler(CAN0_Controller1);

}
#endif

#if (GPCAN_IRQ_CAN0_SR5_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR5_PRIO) __vector_table(0) CAN0Controller1_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN0Controller1_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN0_SR5_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	test_IrqCount[1].RxFifo1Count++;
	GpCan_IsrRxFIFO1Handler(CAN0_Controller1);
}
#endif

#if (GPCAN_IRQ_CAN0_SR6_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR6_PRIO) __vector_table(0) CAN0Controller1_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN0Controller1_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN0_SR6_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	test_IrqCount[1].TxCount++;
	GpCan_IsrTxCompletedHandler(CAN0_Controller1);
}
#endif

#if (GPCAN_IRQ_CAN0_SR8_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR8_PRIO) __vector_table(0) CAN0Controller2_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN0Controller2_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN0_SR8_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	test_IrqCount[2].RxFifo0Count++;
	GpCan_IsrRxFIFO0Handler(CAN0_Controller2);
}
#endif

#if (GPCAN_IRQ_CAN0_SR9_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR9_PRIO) __vector_table(0) CAN0Controller2_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN0Controller2_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN0_SR9_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	test_IrqCount[2].RxFifo1Count++;
	GpCan_IsrRxFIFO1Handler(CAN0_Controller2);
}
#endif

#if (GPCAN_IRQ_CAN0_SR10_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR10_PRIO) __vector_table(0) CAN0Controller2_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN0Controller2_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN0_SR10_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	test_IrqCount[2].TxCount++;
	GpCan_IsrTxCompletedHandler(CAN0_Controller2);
}
#endif

#if (GPCAN_IRQ_CAN0_SR12_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR12_PRIO) __vector_table(0) CAN0Controller3_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN0Controller3_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN0_SR12_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO0Handler(CAN0_Controller3);
}
#endif

#if (GPCAN_IRQ_CAN0_SR13_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR13_PRIO) __vector_table(0) CAN0Controller3_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN0Controller3_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN0_SR13_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO1Handler(CAN0_Controller3);
}
#endif

#if (GPCAN_IRQ_CAN0_SR14_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN0_SR14_PRIO) __vector_table(0) CAN0Controller3_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN0Controller3_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN0_SR14_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrTxCompletedHandler(CAN0_Controller3);
}
#endif

#if (GPCAN_IRQ_CAN1_SR0_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR0_PRIO) __vector_table(0) CAN1Controller0_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN1Controller0_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN1_SR0_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO0Handler(CAN1_Controller0);
}
#endif

#if (GPCAN_IRQ_CAN1_SR1_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR1_PRIO) __vector_table(0) CAN1Controller0_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN1Controller0_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN1_SR1_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO1Handler(CAN1_Controller0);
}
#endif

#if (GPCAN_IRQ_CAN1_SR2_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR2_PRIO) __vector_table(0) CAN1Controller0_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN1Controller0_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN1_SR2_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrTxCompletedHandler(CAN1_Controller0);
}
#endif

#if (GPCAN_IRQ_CAN1_SR4_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR4_PRIO) __vector_table(0) CAN1Controller1_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN1Controller1_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN1_SR4_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO0Handler(CAN1_Controller1);
}
#endif

#if (GPCAN_IRQ_CAN1_SR5_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR5_PRIO) __vector_table(0) CAN1Controller1_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN1Controller1_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN1_SR5_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO1Handler(CAN1_Controller1);
}
#endif

#if (GPCAN_IRQ_CAN1_SR6_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR6_PRIO) __vector_table(0) CAN1Controller1_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN1Controller1_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN1_SR6_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrTxCompletedHandler(CAN1_Controller1);
}
#endif

#if (GPCAN_IRQ_CAN1_SR8_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR8_PRIO) __vector_table(0) CAN1Controller2_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN1Controller2_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN1_SR8_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO0Handler(CAN1_Controller2);
}
#endif

#if (GPCAN_IRQ_CAN1_SR9_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR9_PRIO) __vector_table(0) CAN1Controller2_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN1Controller2_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN1_SR9_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO1Handler(CAN1_Controller2);
}
#endif

#if (GPCAN_IRQ_CAN1_SR10_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR10_PRIO) __vector_table(0) CAN1Controller2_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN1Controller2_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN1_SR10_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrTxCompletedHandler(CAN1_Controller2);
}
#endif

#if (GPCAN_IRQ_CAN1_SR12_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR12_PRIO) __vector_table(0) CAN1Controller3_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN1Controller3_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN1_SR12_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO0Handler(CAN1_Controller3);
}
#endif

#if (GPCAN_IRQ_CAN1_SR13_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR13_PRIO) __vector_table(0) CAN1Controller3_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN1Controller3_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN1_SR13_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO1Handler(CAN1_Controller3);
}
#endif

#if (GPCAN_IRQ_CAN1_SR14_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN1_SR14_PRIO) __vector_table(0) CAN1Controller3_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN1Controller3_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN1_SR14_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrTxCompletedHandler(CAN1_Controller3);
}
#endif

#if (GPCAN_IRQ_CAN2_SR0_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR0_PRIO) __vector_table(0) CAN2Controller0_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN2Controller0_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN2_SR0_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO0Handler(CAN2_Controller0);
}
#endif

#if (GPCAN_IRQ_CAN2_SR1_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR1_PRIO) __vector_table(0) CAN2Controller0_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN2Controller0_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN2_SR1_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO1Handler(CAN2_Controller0);
}
#endif

#if (GPCAN_IRQ_CAN2_SR2_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR2_PRIO) __vector_table(0) CAN2Controller0_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN2Controller0_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN2_SR2_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrTxCompletedHandler(CAN2_Controller0);
}
#endif

#if (GPCAN_IRQ_CAN2_SR4_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR4_PRIO) __vector_table(0) CAN2Controller1_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN2Controller1_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN2_SR4_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO0Handler(CAN2_Controller1);
}
#endif

#if (GPCAN_IRQ_CAN2_SR5_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR5_PRIO) __vector_table(0) CAN2Controller1_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN2Controller1_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN2_SR5_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO1Handler(CAN2_Controller1);
}
#endif

#if (GPCAN_IRQ_CAN2_SR6_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR6_PRIO) __vector_table(0) CAN2Controller1_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN2Controller1_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN2_SR6_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrTxCompletedHandler(CAN2_Controller1);
}
#endif

#if (GPCAN_IRQ_CAN2_SR8_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR8_PRIO) __vector_table(0) CAN2Controller2_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN2Controller2_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN2_SR8_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO0Handler(CAN2_Controller2);
}
#endif

#if (GPCAN_IRQ_CAN2_SR9_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR9_PRIO) __vector_table(0) CAN2Controller2_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN2Controller2_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN2_SR9_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO1Handler(CAN2_Controller2);
}
#endif

#if (GPCAN_IRQ_CAN2_SR10_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR10_PRIO) __vector_table(0) CAN2Controller2_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN2Controller2_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN2_SR10_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();;

	GpCan_IsrTxCompletedHandler(CAN2_Controller2);
}
#endif

#if (GPCAN_IRQ_CAN2_SR12_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR12_PRIO) __vector_table(0) CAN2Controller3_RxFIFO0IrqProcessing(void)
IFX_INTERRUPT(CAN2Controller3_RxFIFO0IrqProcessing, 0, GPCAN_IRQ_CAN2_SR12_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO0Handler(CAN2_Controller3);
}
#endif

#if (GPCAN_IRQ_CAN2_SR13_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR13_PRIO) __vector_table(0) CAN2Controller3_RxFIFO1IrqProcessing(void)
IFX_INTERRUPT(CAN2Controller3_RxFIFO1IrqProcessing, 0, GPCAN_IRQ_CAN2_SR13_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrRxFIFO1Handler(CAN2_Controller3);
}
#endif

#if (GPCAN_IRQ_CAN2_SR14_PRIO > 0)
//void __interrupt(GPCAN_IRQ_CAN2_SR14_PRIO) __vector_table(0) CAN2Controller3_TxEventIrqProcessing(void)
IFX_INTERRUPT(CAN2Controller3_TxEventIrqProcessing, 0, GPCAN_IRQ_CAN2_SR14_PRIO)
{
	__mtcr(CPU_ICR, ((__mfcr(CPU_ICR) & 0xFFFF00u) | GPCAN_IRQ_GROUP_MAX_PRIO));
	__enable();

	GpCan_IsrTxCompletedHandler(CAN2_Controller3);
}
#endif






