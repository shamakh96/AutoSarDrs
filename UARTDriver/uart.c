/*
 * uart.c
 *
 *  Created on: May 21, 2019
 *      Author: r
 */


#include "uart.h"

static void (* volatile RxInterPtr)(void) = NULL_PTR ;
static void (* volatile TxInterPtr)(void) = NULL_PTR ;
static void (* volatile REInterPtr)(void) = NULL_PTR ;

static UART_configType g_configs ;

void UART_init ( UART_configType * ConfigPtr )
{

	g_configs = *ConfigPtr ;
	UBRRH = (uint8 ) ( (MYUBRR) >> 8) ;
	UBRRL = (uint8 ) (MYUBRR) ;

	UCSRA = ( ( ConfigPtr -> doubleSpeed) 		<< U2X);

	UCSRB = ( ( ConfigPtr -> transmiterEnable) 	<< TXEN ) |
			( ( ConfigPtr -> receiverEnable) 	<< RXEN ) |
			( ( ConfigPtr -> RxInterrupt) 		<< RXCIE) |
			( ( ConfigPtr -> TxInterrupt) 		<< TXCIE) |
			( ( ConfigPtr -> EmptyInterrupt) 	<< UDRIE) ;

	UCSRC = (	STD_ON 							<< URSEL) |
			( ( ConfigPtr -> charSize) 			<< UCSZ0) |
			( ( ConfigPtr -> TwoStop) 			<< USBS ) |
			( ( ConfigPtr -> parityMode) 		<< UPM0 ) ;

}

void UART_Transmit (uint8 data)
{
	while ( !(UCSRA & (1 << UDRE)) ) ;

	UDR = data ;



}
uint8 UART_Receive (void)
{
	uint8 status , data ;

	while ( !( UCSRA & (1 << RXC)) );

	status = UCSRA ;
	data = UDR ;

	if (g_configs.parityMode)
	{
		if ( (status) & ( (1 << FE) | (1 << DOR) | (1 >> PE) ))
			return -1 ;
		else
			return data ;
	}
	else
	{
		if ( (status) & ( (1 << FE ) | (1 << DOR) ) )
			return -1 ;

		else
			return data ;
	}


}

void set_RxPtrF ( void (*rxPtr)(void) )
{
	RxInterPtr = rxPtr ;
}
void set_TxPtrF ( void (*txPtr)(void) )
{
	TxInterPtr = txPtr ;
}
void set_REPtrF ( void (*rePtr)(void) )
{
	REInterPtr = rePtr ;
}

ISR (USART_RXC_vect)
{

	if (RxInterPtr != NULL_PTR)
		RxInterPtr();


}
ISR (USART_TXC_vect)
{
	if (TxInterPtr != NULL_PTR)
		TxInterPtr ();

}
ISR (USART_UDRE_vect)
{

	if (REInterPtr != NULL_PTR)
	REInterPtr();

}


