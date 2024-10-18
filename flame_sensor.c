 /******************************************************************************
 * flame_sensor.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Malak
 *******************************************************************************/

#include "flame_sensor.h"
#include "gpio.h"
#include "common_macros.h"

/*
 * Description :
 * Initialize the Flame Sensor:
 * Setup the Flame Sensor pins direction using GPIO driver.
 */
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FlameSensor_INPUT_PORT_ID, FlameSensor_INPUT_PIN_ID, PIN_INPUT);
}

/*
 * Description :
 * Read the Flame Sensor Pin using GPIO driver.
 */
uint8 FlameSensor_getValue(void)
{
	return (GPIO_readPin(FlameSensor_INPUT_PORT_ID, FlameSensor_INPUT_PIN_ID));
}
