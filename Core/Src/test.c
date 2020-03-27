#include "stdbool.h"
#include "stdio.h"
#include "gpio.h"
#include "PingPong_functions.h"

void Test_program(void);
void Test_Led(void);
void Show_points(uint8_t L_points, uint8_t R_points);
void Test_buttons(void);
/*********************************************************************************
  @brief   test program for functional testing
  @file    test.c
  @author  Harmon Singh
  @version 1.0
  @date    04-November-2019
  @brief   Functions and structures for program testing
 * *******************************************************************************/



void Test_program(void)
{
	uint8_t LeftPoint=2;
	uint8_t RightPoint=1;
	//Test_Led();
	Show_points(LeftPoint, RightPoint);
	Test_buttons();
}

void Test_Led(void)
{
	/**@brief Led_on, turn one of the pingpong leds on

	  @paramu int8_t Lednr, number to the Led that is turned on
	  		Lednr can be 1-8, all other values turns all leds off
	  @return void
	  */

	int8_t Lednr;
	/*Loop checking that all leds can be turned on*/
	for(Lednr=1; Lednr<=8; Lednr++){
		Led_on(Lednr);
		HAL_Delay(500);
	}
	Led_on(9); //turn off led 8
	HAL_Delay(1000); // 1000 ms
	return;
}

void Show_points(uint8_t L_points, uint8_t R_points)
{
	for(int i = 0; i<=L_points;i++){

		if (i==1||i==2||i==3||i==4)HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
		if (i==2||i==3||i==4)HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
		if (i==3||i==4)HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
		if (i==4)HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);


	}
	HAL_Delay(2000);

	for(int j = 0; j<=R_points;j++){
		if (j==1||j==2||j==3||j==4)HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		if (j==2||j==3||j==4)HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		if (j==3||j==4)HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		if (j==4)HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
	}
	HAL_Delay(2000);


	return;
}

void Test_buttons(void)
{
	int8_t j;
	/* Checking buttons */
	j=4;
	Led_on(j); // Light on

	while(j<9 && j>0)
	{
		if( L_hit() == true ) // Wait for left button hit
			{
			j++;     // next led to the right
			Led_on(j); // Light on
			HAL_Delay(100); // 100 ms
			while( L_hit() == true ); // Wait for button release
			HAL_Delay(100); // 100 ms
			}
		if( R_hit() == true ) // Wait for right button hit
			{
			j--;     // next led to the left
			Led_on(j); // Light on
			HAL_Delay(100); // 100 ms
			while( R_hit() == true ); // Wait for button release
			HAL_Delay(100); // 100 ms
			if(j<1) j=0; // Start again from left
			}

	}
	return;

}
