 /******************************************************************************
 * flame_sensor.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Malak
 *******************************************************************************/

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define FlameSensor_INPUT_PORT_ID   	PORTD_ID
#define FlameSensor_INPUT_PIN_ID    	PIN2_ID

/*******************************************************************************
 *                             Function Prototypes                             *
 *******************************************************************************/

/*
 * Description :
 * Initialize the Flame Sensor:
 */
void FlameSensor_init(void);

/*
 * Description :
 * Get the value from the Flame Sensor.
 */
uint8 FlameSensor_getValue(void);


#endif /* FLAME_SENSOR_H_ */
