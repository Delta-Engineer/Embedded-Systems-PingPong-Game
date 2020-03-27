/*********************************************************************************
  @brief   Pingpong, functions for Pingpong-program
  @file    PingPong_functions.c
  @author  Harmon Singh
  @version 1.0
  @date    04-November-2019
  @brief   Functions and structures for program Pingpong
 * *******************************************************************************/

#include "stdbool.h"
#include "stdio.h"
#include "gpio.h"
#include "main.h"
#include "stm32l4xx_hal.h"

void Led_on(uint8_t Lednr);
bool L_hit(void);
bool R_hit(void);

void ScoreLeft(uint8_t LeftScore);
void ScoreRight(uint8_t RightScore);
void MissedBlink(void);
void TotalScore(uint8_t LScore,uint8_t RScore);


void Led_on(uint8_t Lednr)
{
	/**@brief Led_on, turn one of the pingpong leds on

	  @param uint8_t Lednr, number to the Led that is turned on
	  		Lednr can be 1-8, all other values turns all leds off
	  @return void
	  */

	uint8_t i;
	for (i=1; i<=8; i++)
	{
		switch(i){
		case 1 : // Led1
					if (Lednr==i) HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
					else HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
					break;
		case 2 : // Led2
					if (Lednr==i) HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
					else HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
					break;
		case 3 : // Led3
					if (Lednr==i) HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
					else HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
					break;
		case 4 : // Led4
					if (Lednr==i) HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
					else HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
					break;
		case 5 : // Led5
					if (Lednr==i) HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
					else HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
					break;
		case 6 : // Led6
					if (Lednr==i) HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
					else HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
					break;
		case 7 : // Led7
					if (Lednr==i) HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
					else HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
					break;
		case 8 : // Led8
					if (Lednr==i) HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
					else HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
					break;
		default :
			;
		} // end switch
	} // end for-loop

	return;
} // End of function Led_on

/**
 * @brief L_hit, check if L button is pressed
 * @param void
 * @return bool, true if L button pushed, false otherwise
 **/
bool L_hit(void)
{  if(HAL_GPIO_ReadPin(L_button_GPIO_Port, L_button_Pin) == 0) return true;
		else return false;
	}

/**
 * @brief R_hit, check if R button is pressed
 * @param void
 * @return bool, true if R button pushed, false otherwise
 **/
bool R_hit(void)
{  if(HAL_GPIO_ReadPin(R_button_GPIO_Port, R_button_Pin) == 0) return true;
		else return false;
	}

void ScoreLeft(uint8_t LeftScore){

	for(int j = 0; j<=LeftScore;j++){
			if (j==1||j==2||j==3||j==4)HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			if (j==2||j==3||j==4)HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
			if (j==3||j==4)HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
			if (j==4)HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
		}
	HAL_Delay(2000);
	return;
}

void ScoreRight(uint8_t RightScore){
	for(int i = 0; i<=RightScore;i++){

			if (i==1||i==2||i==3||i==4)HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
			if (i==2||i==3||i==4)HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
			if (i==3||i==4)HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
			if (i==4)HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
		}
	HAL_Delay(2000);

	return;
}


void MissedBlink(void){

	int blinker = 0;
		while(blinker != 3)
		{
		  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);  // Led 1 ON
		  HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET); // Led 2 ON
		  HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET); // Led 3 ON
		  HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);  // Led 4 ON
		  HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin,GPIO_PIN_SET);  // Led 5 ON
		  HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);  // Led 6 ON
		  HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);  // Led 7 ON
		  HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);  // Led 8 ON

		  HAL_Delay(300);

		  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);  //LED 1 OFF
		  HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);	//LED 2 OFF
		  HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET); 	//LED 3 OFF
		  HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);	//LED 4 OFF
		  HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);	//LED 5 OFF
		  HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);	//LED 6 OFF
		  HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);	//LED 7 OFF
		  HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);	//LED 8 OFF

		  HAL_Delay(300);
		  blinker++;
		}
		return;
		}


void TotalScore(uint8_t LScore ,uint8_t RScore){

	for(int j = 0; j<=LScore;j++){

		if (j==1||j==2||j==3||j==4)HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		if (j==2||j==3||j==4)HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		if (j==3||j==4)HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		if (j==4)HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);


		}

		for(int i = 0; i<=RScore;i++){

			if (i==1||i==2||i==3||i==4)HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
			if (i==2||i==3||i==4)HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
			if (i==3||i==4)HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
			if (i==4)HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);

		}
		HAL_Delay(2000);





}

