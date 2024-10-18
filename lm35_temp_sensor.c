 /******************************************************************************
 * lm35_temp_sensor.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Malak
 *******************************************************************************/

#include "lm35_temp_sensor.h"

#include"adc.h"
#include<util/delay.h>

uint8 LM35_getTemprature(void){

	uint8 temprature_value = 0;
	static uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(TEMPERATURE_SENSOR_CHANNEL_ID);

	temprature_value = ((uint8)(((uint32)adc_value*SENSOR_MAX_TEMPRATURE*ADC_REF_VOLT_VALUE)/(SENSOR_MAX_VOLT_VALUE*ADC_MAXIMUM_VALUE)));

	return temprature_value;
}

