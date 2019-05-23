/*
 * uart_cfg.h
 *
 *  Created on: May 21, 2019
 *      Author: r
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_

#define F_OSC 1000000
#define BAUD 9600
#define MYUBRR F_OSC/8/BAUD -1

#define charSIZE_FIVE 	0
#define charSIZE_SIX 	1
#define charSIZE_SEVEN 	2
#define charSIZE_EIGHT	3

#define PARITY_DIS 		0
#define PARITY_EVEN		2
#define PARITY_ODD		3

#endif /* UART_CFG_H_ */
