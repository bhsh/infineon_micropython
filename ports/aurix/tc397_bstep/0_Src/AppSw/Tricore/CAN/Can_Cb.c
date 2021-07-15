/*
 * Can_Cb.c
 *
 *  Created on: May 26, 2020
 *      Author: ZhangEdi
 */
#include "Can_Cb.h"

void CAN1_RX1_IRQHandler(void);
volatile uint16 test_CanTxCount, test_CanRxCount;
volatile uint16 test_TimeStampRecord[10];
volatile Can_Message_t test_CanRxMsg[10];
volatile uint16 test_DataUpdate;

void Can_TxConfirmation (uint8 CanTxPduId, Ifx_CAN_TXEVENT* TxEvent)
{
	test_TimeStampRecord[test_CanTxCount++] = TxEvent->E1.B.TXTS;
	if(test_CanTxCount == 10)
	{
		test_CanTxCount = 0;
	}
}
void py_tc397_get_can_rx_Msg(unsigned int *msgid,unsigned char *data, unsigned char *len)
{
   if(test_DataUpdate == 1)
   {
     //Update the data when the data is valid
     test_DataUpdate  = 0;
     *msgid = test_CanRxMsg[test_CanRxCount].CanId;
     *len   = test_CanRxMsg[test_CanRxCount].DLC;
     int i;
     for(i = 0; i < test_CanRxMsg[test_CanRxCount].DLC; i++)
     {
        *data++  = test_CanRxMsg[test_CanRxCount].MessageData.Byte[i];
     }
   }
   else
   {
     //Reset the data when the data is invalid
	  *msgid = 0;
	  *len   = 8;
	  int i;
	  for(i = 0; i < 8; i++)
	  {
		 *data++  = 0x30; //return 0 
	  }
   }
}

void Can_RxIndication(uint8 RxHandle, Can_Message_t *RecMsgPtr)
{
	uint8 lLoopIdx;
	test_CanRxMsg[test_CanRxCount].CanId = RecMsgPtr->CanId;
	test_CanRxMsg[test_CanRxCount].DLC = RecMsgPtr->DLC;
	test_CanRxMsg[test_CanRxCount].BRS = RecMsgPtr->BRS;
	test_CanRxMsg[test_CanRxCount].FDF = RecMsgPtr->FDF;
	test_CanRxMsg[test_CanRxCount].XTD = RecMsgPtr->XTD;
	test_CanRxMsg[test_CanRxCount].RXTS = RecMsgPtr->RXTS;

	//Update the flag
	test_DataUpdate = 1;

	for(lLoopIdx = 0u; lLoopIdx < 8; lLoopIdx++)
	{
		test_CanRxMsg[test_CanRxCount].MessageData.Byte[lLoopIdx] = RecMsgPtr->MessageData.Byte[lLoopIdx];
	}

	//test_CanRxCount++;

	if(test_CanRxCount == 10)
	{
		test_CanRxCount = 0;
	}

	CAN1_RX0_IRQHandler();
}
