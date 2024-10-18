 /******************************************************************************
 * ldr_sensor.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Malak
 *******************************************************************************/

#include "ldr_sensor.h"
#include "adc.h"

/*
 * Description :
 * Function responsible for calculate the light intensity from the ADC digital value.
 */
uint16 LDR_getLightIntensity(void)
{
	uint8 light_value = 0;
	static uint16 adc_value = 0;

	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);
	light_value = ((uint16)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(LDR_SENSOR_MAX_VOLT_VALUE*ADC_MAXIMUM_VALUE)));
	return light_value;
}
