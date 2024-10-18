 /******************************************************************************
 * lm35_temp_sensor.h
 *
 *  Created on: Oct 3, 2024
 *      Author: Malak
 *******************************************************************************/

#ifndef LM35_TEMP_SENSOR_H_
#define LM35_TEMP_SENSOR_H_

#include"std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TEMPERATURE_SENSOR_CHANNEL_ID		1
#define SENSOR_MAX_TEMPRATURE				150
#define SENSOR_MAX_VOLT_VALUE				1.5

/*******************************************************************************
 *                        	  Function Prototypes                              *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemprature(void);


#endif /* LM35_TEMP_SENSOR_H_ */
