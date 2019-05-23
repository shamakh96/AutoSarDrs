/*
 * Port_cfg.h
 *
 *  Created on: Apr 22, 2019
 *      Author: r
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_
/*
 * MCU specific -- i think it should be in Platform_Types.h -- but it is closely related to this driver anyway.
 */
#define NUMBER_OF_CHANNELS 32

#define PORT_A 			0
#define PORT_B 			1
#define PORT_C 			2
#define PORT_D 			3

#define PIN_0			0
#define PIN_1			1
#define PIN_2			2
#define PIN_3			3
#define PIN_4			4
#define PIN_5			5
#define PIN_6			6
#define PIN_7			7

/*
 * Symbols indicate the exact index (ID) of all channels in MCU ---- AutoSAR says they should be here
 */
#define PORT_A_PIN_0 	0
#define PORT_A_PIN_1 	1
#define PORT_A_PIN_2 	2
#define PORT_A_PIN_3 	3
#define PORT_A_PIN_4 	4
#define PORT_A_PIN_5 	5
#define PORT_A_PIN_6 	6
#define PORT_A_PIN_7 	7

#define PORT_B_PIN_0 	8
#define PORT_B_PIN_1 	9
#define PORT_B_PIN_2 	10
#define PORT_B_PIN_3 	11
#define PORT_B_PIN_4 	12
#define PORT_B_PIN_5 	13
#define PORT_B_PIN_6 	14
#define PORT_B_PIN_7	15

#define PORT_C_PIN_0 	16
#define PORT_C_PIN_1 	17
#define PORT_C_PIN_2 	18
#define PORT_C_PIN_3 	19
#define PORT_C_PIN_4 	20
#define PORT_C_PIN_5 	21
#define PORT_C_PIN_6 	22
#define PORT_C_PIN_7	23

#define PORT_D_PIN_0 	24
#define PORT_D_PIN_1 	25
#define PORT_D_PIN_2 	26
#define PORT_D_PIN_3 	27
#define PORT_D_PIN_4 	28
#define PORT_D_PIN_5 	29
#define PORT_D_PIN_6 	30
#define PORT_D_PIN_7	31



#endif /* PORT_CFG_H_ */
