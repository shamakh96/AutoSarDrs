/*
 * uart.h
 *
 *  Created on: May 21, 2019
 *      Author: r
 */

#ifndef UART_H_
#define UART_H_


#include <avr/io.h>
#include <avr/interrupt.h>
#include "Std_Types.h"
#include "uart_cfg.h"


//typedef enum { FIVE,SIX,SEVEN,EIGHT } charSizeType ;
/*

typedef struct {

	uint8 doubleSpeed ;
	uint8 transmiterEnable ;
	uint8 receiverEnable ;
	charSizeType charSize ;
	uint8 TwoStop ;
	uint8 RxInterrupt ;
	uint8 TxInterrupt ;
	uint8 EmptyInterrupt ;
}UART_configType ;
*/


typedef struct {

	uint8 doubleSpeed : 1 ;
	uint8 transmiterEnable : 1 ;
	uint8 receiverEnable : 1 ;
	uint8 TwoStop : 1 ;
	uint8 RxInterrupt : 1  ;
	uint8 TxInterrupt : 1 ;
	uint8 EmptyInterrupt : 1 ;
	uint8 charSize : 2 ;
	uint8 parityMode : 2 ;

}UART_configType;

extern UART_configType UART_Configurations ;

void UART_init (  UART_configType*  ) ;
void UART_Transmit (uint8 data) ;
uint8 UART_Receive (void);
void set_RxPtrF ( void (*rxPtr)(void) );
void set_TxPtrF ( void (*txPtr)(void) );
void set_REPtrF ( void (*rePtr)(void) );




#endif /* UART_H_ */
