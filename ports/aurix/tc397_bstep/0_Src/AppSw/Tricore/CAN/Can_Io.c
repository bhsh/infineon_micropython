/*
 * Can_Io.c
 *
 *  Created on: May 27, 2020
 *      Author: zhangedi
 */

#include "can_io.h"

void Can_Io_Init(void)
{
	/* CAN0_N1, P14.0 (CAN_TX), P14.1 (CAN_RX) */
//	P14_IOCR0.B.PC0 = 0x15;
//	P14_IOCR0.B.PC1 = 0x00;
	P20_IOCR4.B.PC7 = 0x00;
	P20_IOCR8.B.PC8 = 0x15;
}



