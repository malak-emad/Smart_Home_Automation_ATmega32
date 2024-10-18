 /******************************************************************************
 * adc.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Malak
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(void)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 11 to choose internal 2.56V reference voltage
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (1<<REFS1) | (1<<REFS0);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);
	SET_BIT(ADCSRA,ADSC); 	/* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));	/* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF);	/* Clear ADIF by write '1' to it :) */
	return ADC;	/* Read the digital value from the data register */
}
