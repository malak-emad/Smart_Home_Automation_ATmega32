 /******************************************************************************
 * led.h
 *
 *  Created on: Oct 3, 2024
 *      Author: Malak
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "common_macros.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LED_CONFIGURATION 			POSITIVE_LOGIC
#define LED_PORT_ID					PORTB_ID
typedef enum {
	RED_LED_ID 	 = PIN5_ID,
	GREEN_LED_ID = PIN6_ID,
	BLUE_LED_ID  = PIN7_ID
}LED_ID;

#if (LED_CONFIGURATION == POSITIVE_LOGIC)
#define LED_OFF 			LOGIC_LOW
#define LED_ON				LOGIC_HIGH

#elif (LED_CONFIGURATION == NEGATIVE_LOGIC)
#define LED_OFF				LOGIC_HIGH
#define LED_ON				LOGIC_LOW
#endif


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the LED driver.
 */
void LEDS_init(void);

/*
 * Description :
 * Function responsible for turning the LED On.
 */
void LED_on(LED_ID id);

/*
 * Description :
 * Function responsible for turning the LED Off.
 */
void LED_off(LED_ID id);

#endif /* LED_H_ */
