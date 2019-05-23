/*
 * myPort.h
 *
 *  Created on: Apr 22, 2019
 *      Author: r
 */

#ifndef MYPORT_H_
#define MYPORT_H_

#include "Std_Types.h"

#include "Port_cfg.h"
#include "Common_Macros.h"


/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/*possible directions of a port pin*/
typedef enum { PORT_PIN_IN , PORT_PIN_OUT } Port_PinDirectionType;
/*possible initial value if output --- or pull up and down feature if input*/
typedef enum { STD_High = 1 , PULL_UP = 1  , PULL_DOWN = 0  , STD_Low = 0   } 	Port_initVal_PullType ;

/*data type for the symbolic name of a port pin*/
typedef uint8 Port_PinType ;


/*
 *  Port_Channel_ConfigType structure is the user defined data type of every channel used
 */

typedef struct  {

	uint8 Port_Num ;
	uint8 Pin_Num ;
	Port_PinDirectionType Direction ;
	Port_initVal_PullType init_pull ;

}Port_Channel_ConfigType ;

/*
 * Port_ConfigType is the type of configuration set
 */
typedef struct {

	Port_Channel_ConfigType channels [NUMBER_OF_CHANNELS] ;
}Port_ConfigType ;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void Port_init (const Port_ConfigType * CofigPtr);
void Port_SetPinDirection (Port_PinType , Port_PinDirectionType);


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern Port_ConfigType Port_Configuration ;

#endif /* MYPORT_H_ */
