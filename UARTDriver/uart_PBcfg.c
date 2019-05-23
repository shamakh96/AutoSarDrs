/*
 * uart_PBcfg.c
 *
 *  Created on: May 21, 2019
 *      Author: r
 */



#include "uart.h"


UART_configType UART_Configurations = {


		HIGH,				/* double speed Mode */
		HIGH,				/* Transmitter Enable */
		HIGH,				/* Receiver Enable */
		LOW,				/* Stop bits on:2 , off:1 */
		LOW,				/* Rx complete interrupt */
		LOW,				/* Tx complete interrupt  */
		LOW,				/* Register Empty interrupt */
		charSIZE_EIGHT,		/* character size in transmission */
		PARITY_EVEN			/* Parity Mode */

};

