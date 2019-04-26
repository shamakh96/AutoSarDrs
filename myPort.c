/*
 * myPort.c
 *
 *  Created on: Apr 22, 2019
 *      Author: r
 */



#include "myPort.h"
#include "Dio_Regs.h"



STATIC Port_Channel_ConfigType * Port_PortChannels = NULL_PTR ;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;



/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port Driver module.
************************************************************************************/
void Port_init (const Port_ConfigType * ConfigPtr)
{
	Port_Status = PORT_INITIALIZED ;

	/*
	 * use the global pointer to point to the configuration set to be used by all function in this file scope
	 */
	Port_PortChannels = ConfigPtr -> channels ;
	uint8 *DDR_Ptr = NULL_PTR ;
	uint8 *PORT_Ptr = NULL_PTR ;
	uint8 index ;

	for (index = 0 ; index < NUMBER_OF_CHANNELS ; index++)
	{
		switch ( Port_PortChannels[index].Port_Num )
		{
		case 0:
		DDR_Ptr = &DDRA_REG ;
		PORT_Ptr = &PORTA_REG ;
		break;
		case 1:
		DDR_Ptr = &DDRB_REG ;
		PORT_Ptr = &PORTB_REG ;
		break;
		case 2:
		DDR_Ptr = &DDRC_REG ;
		PORT_Ptr = &PORTC_REG ;
		break;
		case 3:
		DDR_Ptr = &DDRD_REG ;
		PORT_Ptr = &PORTD_REG ;
		break;

		}
		if (Port_PortChannels[index].Direction == PORT_PIN_OUT )
		{
			SET_BIT(*DDR_Ptr,Port_PortChannels[index].Pin_Num);

			if (Port_PortChannels[index].init_pull == STD_High)
			{
				SET_BIT(*PORT_Ptr,Port_PortChannels[index].Pin_Num);
			}
			else
			{
				CLEAR_BIT (*PORT_Ptr,Port_PortChannels[index].Pin_Num);
			}

		}
		else
		{
			CLEAR_BIT(*DDR_Ptr,Port_PortChannels[index].Pin_Num);

			if (Port_PortChannels[index].init_pull == PULL_UP)
			{
				SET_BIT(*PORT_Ptr,Port_PortChannels[index].Pin_Num);
			}
			else
			{
				CLEAR_BIT (*PORT_Ptr,Port_PortChannels[index].Pin_Num);
			}
		}


	}


}

/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin ---- Port Pin ID number
* 				   Direction ---- Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction.
************************************************************************************/
void Port_SetPinDirection (Port_PinType Pin , Port_PinDirectionType Direction )
{
	uint8 *DDR_Ptr = NULL_PTR ;
	uint8 *PORT_Ptr = NULL_PTR ;


	if (PORT_INITIALIZED == Port_Status)
	{
		switch (Port_PortChannels[Pin].Port_Num)
		{
		case 0:
		DDR_Ptr = &DDRA_REG ;
		PORT_Ptr = &PORTA_REG ;
		break;
		case 1:
		DDR_Ptr = &DDRB_REG ;
		PORT_Ptr = &PORTB_REG ;
		break;
		case 2:
		DDR_Ptr = &DDRC_REG ;
		PORT_Ptr = &PORTC_REG ;
		break;
		case 3:
		DDR_Ptr = &DDRD_REG ;
		PORT_Ptr = &PORTD_REG ;
		break;

		}

		if (PORT_PIN_OUT == Direction)
		{
			SET_BIT(*DDR_Ptr,Port_PortChannels[Pin].Pin_Num);
			CLEAR_BIT(*PORT_Ptr,Port_PortChannels[Pin].Pin_Num); ////// initial value 0	if i want to

		}
		else
		{
			CLEAR_BIT(*DDR_Ptr,Port_PortChannels[Pin].Pin_Num);
			SET_BIT(*PORT_Ptr,Port_PortChannels[Pin].Pin_Num); ////// Pull up default --- i said so !

		}
	}
	else {

	}

}

