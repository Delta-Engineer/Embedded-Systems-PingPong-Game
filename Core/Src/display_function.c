/*
 * display_function.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Harmon
 */

#include "stdio.h"
#include "gpio.h"
#include "main.h"
#include "tim.h"
#include "adc.h"

void ScreenBacklight(void);
void DisplayInfo(void);
void ScreenBoot(void);


void ScreenBacklight(void){
		uint16_t analogInput;

		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 10);
		analogInput = HAL_ADC_GetValue(&hadc1);
		HAL_Delay(100);

		// Set duty cycle depending on the read value [analogInput]
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, analogInput);
}

void DisplayInfo(uint8_t RW, uint8_t RS, uint8_t data){
	uint8_t SendStore[SPI_SEND_LENGTH];

	SendStore[0] = 0x1F;
	SendStore[0] |= RW ? 0x20 : 0x00;
	SendStore[0] |= RS ? 0x40 : 0x00;

	SendStore[1] = 0x00;
	SendStore[1] |= (data & 0x0F);

	SendStore[2] = 0x00;
	SendStore[2] |= (data & 0xF0) >> 4;

	HAL_GPIO_WritePin(GPIO8,GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2,SendStore,3,100);
	HAL_GPIO_WritePin(GPIO8,GPIO_PIN_12, GPIO_PIN_SET);

}

void ScreenBoot(void){

	DisplayInfo(0,0,0x06);

	DisplayInfo(0,0,0x1E);

	DisplayInfo(0,0,0x39);

	DisplayInfo(0,0,0x1B);

	DisplayInfo(0,0,0x6E);

	DisplayInfo(0,0,0x56);

	DisplayInfo(0,0,0x7A);

	DisplayInfo(0,0,0x38);

	DisplayInfo(0,0,0x8F);

	DisplayInfo(0,0,0x01);
	DisplayInfo(0,0,0x02);

}


