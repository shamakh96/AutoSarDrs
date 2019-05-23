/*
 * main.c
 *
 *  Created on: May 22, 2019
 *      Author: r
 */

#include "uart.h"


void getData (void) ;

uint8 data = 5 ;

int main ()
{

	DDRA = 0xFF ;
	PORTA = 0x00 ;

	UART_init (&UART_Configurations);
	//set_RxPtrF (getData);
	//sei();


	while (1)
	{

		data = UART_Receive ();
		PORTA = data ;

	}



}

void getData (void)
{
	data = UDR ;

}
