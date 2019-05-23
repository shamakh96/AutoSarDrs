 /******************************************************************************
 *
 * Std_Types.h
 *
 * Author: r
 *
 *******************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"
#include "Compiler.h"

/*
 *  Describes the standard Return Type Definitions used in the project
 */
typedef uint8  Std_ReturnType;


#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */

#define E_OK            ((Std_ReturnType)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((Std_ReturnType)0x01U)      /* Function Return NOT OK */

#define HIGH 			1
#define LOW				0

#endif /* STD_TYPES_H */
