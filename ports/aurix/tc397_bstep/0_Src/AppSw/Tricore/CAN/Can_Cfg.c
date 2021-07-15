/*
 * Can_Cfg.c
 *
 *  Created on: 2018-10-17
 *      Author: zhangwei
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Can.h"


GpCan_ControllerConfigType GpCan_ControllerConfigInfo[GPCAN_MAX_NUM_CONTROLLERS_IN_CONFIGSET] =
{
#if 1
	/* **************User Controller 0 Configuration Start ****************************/
	{
		CAN1_Controller3,											/*NodeId*/
		CANXX_RXSEL_RXDB,											/*RxSel*/

		{	/*EventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
		},

		{	/*NodeBaudrateConfiguration*/
			80000000,													/*ModuleFreq*/
		    500000,													    /*BaudRate*/
		    8000,														/*SamplePoint*/
		    3,															/*SyncJumpWidth*/
		    TRUE,														/*FdEnabled*/
		    {5000000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
		},

		{	/*NodeTxMessageConfiguration*/
		  10,															/*TxFifoSize*/
		  10,															/*TxQueue0Size*/
		  10,															/*TxQueue1Size*/
		  0																/*DedicatedBufferSize*/
		},

		{	/*NodeRxMessage*/
			{	/*RxFIFO 0 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x10a,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
			{	/*RxFIFO 1 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x10b,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
		}
	},
	/* **************User Controller 0 Configuration End ****************************/

	/* **************User Controller 1 Configuration Start ****************************/
	{
		CAN0_Controller1,											/*NodeId*/
		CANXX_RXSEL_RXDB,											/*RxSel*/

		{	/*EventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
		},

		{	/*NodeBaudrateConfiguration*/
			80000000,													/*ModuleFreq*/
		    500000,													    /*BaudRate*/
		    8000,														/*SamplePoint*/
		    3,															/*SyncJumpWidth*/
		    TRUE,														/*FdEnabled*/
		    {5000000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
		},

		{	/*NodeTxMessageConfiguration*/
		  10,															/*TxFifoSize*/
		  10,															/*TxQueue0Size*/
		  10,															/*TxQueue1Size*/
		  0																/*DedicatedBufferSize*/
		},

		{	/*NodeRxMessage*/
			{	/*RxFIFO 0 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x108,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
			{	/*RxFIFO 1 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x109,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
		}
	},
	/* **************User Controller 1 Configuration End ****************************/

	/* **************User Controller 2 Configuration Start ****************************/
	{
			CAN0_Controller0,											/*NodeId*/
			CANXX_RXSEL_RXDB,											/*RxSel*/

			{	/*EventHandle*/
				CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
				CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
			},

			{	/*NodeBaudrateConfiguration*/
				80000000,													/*ModuleFreq*/
			    500000,													    /*BaudRate*/
			    8000,														/*SamplePoint*/
			    3,															/*SyncJumpWidth*/
			    FALSE,														/*FdEnabled*/
			    {500000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
			},

			{	/*NodeTxMessageConfiguration*/
			  10,															/*TxFifoSize*/
			  10,															/*TxQueue0Size*/
			  10,															/*TxQueue1Size*/
			  0																/*DedicatedBufferSize*/
			},

			{	/*NodeRxMessage*/
				{	/*RxFIFO 0 Configuration*/
					14,														/*RxFifoSize*/
					MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
					{0x106,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
				},
				{	/*RxFIFO 1 Configuration*/
					14,														/*RxFifoSize*/
					MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
					{0x107,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
				},
			}
		},
	/* **************User Controller 2 Configuration End ****************************/

	/* **************User Controller 3 Configuration Start ****************************/
	{
		CAN2_Controller2,											/*NodeId*/
		CANXX_RXSEL_RXDA,											/*RxSel*/

		{	/*EventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
		},

		{	/*NodeBaudrateConfiguration*/
			80000000,													/*ModuleFreq*/
		    500000,													    /*BaudRate*/
		    8000,														/*SamplePoint*/
		    3,															/*SyncJumpWidth*/
		    TRUE,														/*FdEnabled*/
		    {5000000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
		},

		{	/*NodeTxMessageConfiguration*/
		  10,															/*TxFifoSize*/
		  10,															/*TxQueue0Size*/
		  10,															/*TxQueue1Size*/
		  0																/*DedicatedBufferSize*/
		},

		{	/*NodeRxMessage*/
			{	/*RxFIFO 0 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x104,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
			{	/*RxFIFO 1 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x105,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
		}
	},
	/* **************User Controller 3 Configuration End ****************************/

	/* **************User Controller 4 Configuration Start ****************************/
	{
		CAN0_Controller2,											/*NodeId*/
		CANXX_RXSEL_RXDD,											/*RxSel*/

		{	/*EventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
		},

		{	/*NodeBaudrateConfiguration*/
			80000000,													/*ModuleFreq*/
		    500000,													    /*BaudRate*/
		    8000,														/*SamplePoint*/
		    3,															/*SyncJumpWidth*/
		    TRUE,														/*FdEnabled*/
		    {5000000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
		},

		{	/*NodeTxMessageConfiguration*/
		  10,															/*TxFifoSize*/
		  10,															/*TxQueue0Size*/
		  10,															/*TxQueue1Size*/
		  0																/*DedicatedBufferSize*/
		},

		{	/*NodeRxMessage*/
			{	/*RxFIFO 0 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x102,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
			{	/*RxFIFO 1 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x103,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
		}
	},
	/* **************User Controller 4 Configuration End ****************************/

	/* **************User Controller 5 Configuration Start ****************************/
	{
		CAN2_Controller1,											/*NodeId*/
		CANXX_RXSEL_RXDA,											/*RxSel*/

		{	/*EventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
		},

		{	/*NodeBaudrateConfiguration*/
			80000000,													/*ModuleFreq*/
		    500000,													    /*BaudRate*/
		    8000,														/*SamplePoint*/
		    3,															/*SyncJumpWidth*/
		    TRUE,														/*FdEnabled*/
		    {5000000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
		},

		{	/*NodeTxMessageConfiguration*/
		  10,															/*TxFifoSize*/
		  10,															/*TxQueue0Size*/
		  10,															/*TxQueue1Size*/
		  0																/*DedicatedBufferSize*/
		},

		{	/*NodeRxMessage*/
			{	/*RxFIFO 0 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x100,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
			{	/*RxFIFO 1 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x101,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
		}
	},
	/* **************User Controller 5 Configuration Start ****************************/
	/* **************User Controller 6 Configuration Start ****************************/
	{
		CAN1_Controller0,											/*NodeId*/
		CANXX_RXSEL_RXDA,											/*RxSel*/

		{	/*EventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
		},

		{	/*NodeBaudrateConfiguration*/
			80000000,													/*ModuleFreq*/
		    500000,													    /*BaudRate*/
		    8000,														/*SamplePoint*/
		    3,															/*SyncJumpWidth*/
		    TRUE,														/*FdEnabled*/
		    {5000000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
		},

		{	/*NodeTxMessageConfiguration*/
		  10,															/*TxFifoSize*/
		  10,															/*TxQueue0Size*/
		  10,															/*TxQueue1Size*/
		  0																/*DedicatedBufferSize*/
		},

		{	/*NodeRxMessage*/
			{	/*RxFIFO 0 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x100,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
			{	/*RxFIFO 1 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x101,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
		}
	},
	/* **************User Controller 6 Configuration Start ****************************/
	/* **************User Controller 7 Configuration Start ****************************/
	{
		CAN1_Controller2,											/*NodeId*/
		CANXX_RXSEL_RXDB,											/*RxSel*/

		{	/*EventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
		},

		{	/*NodeBaudrateConfiguration*/
			80000000,													/*ModuleFreq*/
		    500000,													    /*BaudRate*/
		    8000,														/*SamplePoint*/
		    3,															/*SyncJumpWidth*/
		    TRUE,														/*FdEnabled*/
		    {5000000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
		},

		{	/*NodeTxMessageConfiguration*/
		  10,															/*TxFifoSize*/
		  10,															/*TxQueue0Size*/
		  10,															/*TxQueue1Size*/
		  0																/*DedicatedBufferSize*/
		},

		{	/*NodeRxMessage*/
			{	/*RxFIFO 0 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x100,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
			{	/*RxFIFO 1 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x101,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
		}
	},
	/* **************User Controller 7 Configuration Start ****************************/
	/* **************User Controller 8 Configuration Start ****************************/
	{
		CAN0_Controller3,											/*NodeId*/
		CANXX_RXSEL_RXDC,											/*RxSel*/

		{	/*EventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
		},

		{	/*NodeBaudrateConfiguration*/
			80000000,													/*ModuleFreq*/
		    500000,													    /*BaudRate*/
		    8000,														/*SamplePoint*/
		    3,															/*SyncJumpWidth*/
		    TRUE,														/*FdEnabled*/
		    {5000000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
		},

		{	/*NodeTxMessageConfiguration*/
		  10,															/*TxFifoSize*/
		  10,															/*TxQueue0Size*/
		  10,															/*TxQueue1Size*/
		  0																/*DedicatedBufferSize*/
		},

		{	/*NodeRxMessage*/
			{	/*RxFIFO 0 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x100,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
			{	/*RxFIFO 1 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x101,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
		}
	},
	/* **************User Controller 8 Configuration Start ****************************/
	/* **************User Controller 9 Configuration Start ****************************/
	{
		CAN1_Controller1,											/*NodeId*/
		CANXX_RXSEL_RXDB,											/*RxSel*/

		{	/*EventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*RxEventHandle*/
			CAN_EVENT_HANDLING_INTERRUPT,								/*TxEventHandle*/
		},

		{	/*NodeBaudrateConfiguration*/
			80000000,													/*ModuleFreq*/
		    500000,													    /*BaudRate*/
		    8000,														/*SamplePoint*/
		    3,															/*SyncJumpWidth*/
		    TRUE,														/*FdEnabled*/
		    {5000000, 8000, 2, 13}										/*FdBaudConfig{FdBaudrate,FdSamplePoint,FdSyncJumpWidth,FdTransDelayOffset}*/
		},

		{	/*NodeTxMessageConfiguration*/
		  10,															/*TxFifoSize*/
		  10,															/*TxQueue0Size*/
		  10,															/*TxQueue1Size*/
		  0																/*DedicatedBufferSize*/
		},

		{	/*NodeRxMessage*/
			{	/*RxFIFO 0 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x100,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
			{	/*RxFIFO 1 Configuration*/
				14,														/*RxFifoSize*/
				MESSAGE_ID_TYPE_STANDARD,								/*RxMsgIdType*/
				{0x101,0x7ff}											/*RxFifoFilter{FilterMsgId,FilterMask}*/
			},
		}
	},
#endif
	/* **************User Controller 9 Configuration Start ****************************/
};

