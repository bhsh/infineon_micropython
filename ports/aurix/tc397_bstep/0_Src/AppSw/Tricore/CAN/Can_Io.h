/*
 * Can_Io.h
 *
 *  Created on: May 27, 2020
 *      Author: zhangedi
 */

#ifndef _SRC_APPSW_TRICORE_CAN_CAN_IO_H_
#define _SRC_APPSW_TRICORE_CAN_CAN_IO_H_

#include "IfxPort_reg.h"

void Can_Io_Init(void);
void Can_Configurre_Filters(unsigned          char Channel,unsigned int id);


#endif /* 0_SRC_APPSW_TRICORE_CAN_CAN_IO_H_ */
