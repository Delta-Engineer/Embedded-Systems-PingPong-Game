/*********************************************************************************
  @brief   Pingpong
  @file    PingPong.c
  @author  Harmon Singh
  @version 1.0
  @date    04-November-2019
  @brief   Functions and structures for program Pingpong
 * *******************************************************************************/


#include "stdbool.h"
#include "stdio.h"
#include "gpio.h"
#include "PingPong_functions.h"

/* Includes ------------------------------------------------------------------*/
#include"PingPong.h"

/*Define states for state machine*/
typedef enum
{	Start,
	MoveRight,
	MoveLeft
} states;

static states State, NextState;

void PingPong(void);


void PingPong(void)
{
	bool ButtonPressed; //To remember that button is pressed

	uint32_t Varv, Speed; // BALL SPEED
	uint8_t Led; // LED NR
	uint8_t R_Score = 0; // RIGHT SCORE
	uint8_t L_Score = 0; // LEFT SCORE
	uint8_t LSTART = 0;
	uint8_t RSTART = 0;

	State = Start; //INITIATE STATE TO START
	NextState = Start;

	Speed = 500000; // Number of loops

	while(1)
	{
		State = NextState;

		switch(State) // State Machine
		{
		case Start:
			//Varv=Speed;
			Led_on(0); //Turn off All LEDS
			Speed = 500000;

			if(R_Score >=4 || L_Score >=4){  //SCORE RESET FUNCTION && RESTORATION OF START LOCK
				TotalScore(L_Score,R_Score);
				R_Score=0;
				L_Score=0;
				RSTART = 0;
				LSTART = 0;
			}

			if( L_hit() == true && LSTART == 0) //L serve
			{
				LSTART = 1;  //STARTING HAND; 1 = START LOCK
				Led = 1;
				NextState= MoveRight;
				while( L_hit() == true); //wait until button is released
			}
			else if(R_hit() == true && RSTART == 0) //R_ serve
			{
				RSTART = 1; //STARTING HAND; 1 = START LOCK
				Led = 8;
				NextState = MoveLeft;
				while(R_hit() == true); // wait until button is released
			}
			else
				NextState = Start; //Stay in Start State
			break;

		case MoveRight:
		{
			Led_on(Led);
			Varv = Speed;
			if(LSTART == 1)
			{
				LSTART = 1; //RESETING STARTING HAND = LSTART UNLOCK
				RSTART = 0; //RESETING STARTING HAND = RSTART LOCK
			}

			while( Varv != 0)
			{
				if (R_hit()) ButtonPressed = true; //R hit
				Varv--;


			}

			if (ButtonPressed) // R pressed
			{
				if(Led == 8) // AND LED8 ACTIVATE
				{
					NextState=MoveLeft; //RETURN BALL
					Led=7;
					Speed = Speed-50000;

				}
				else
				{
					MissedBlink();
					L_Score++;
					ScoreLeft(L_Score);
					NextState = Start; // hit to early SHOW SCORE STATE!!

				}
				}
			else
			{
				if (Led == 9) //no hit or to late
					{L_Score++;
					MissedBlink();
					ScoreLeft(L_Score);
					NextState = Start; // SHOW SCORE STATE !!

					}
					else
					NextState = MoveRight; // BALL continues to move right
			}
			if (!ButtonPressed) Led++; //PREPARE TO TURN ON NEXT LED
			ButtonPressed = false;
		}
		break;

		case MoveLeft:
		{
			Led_on(Led);
			Varv = Speed;
			if(RSTART == 1)
			{
				LSTART = 0; //RESETING STARTING HAND = LSTART LOCK
				RSTART = 1; //RESETING STARTING HAND = START UNLOCK
			}

			while(Varv!=0)
			{
				if ( L_hit()) ButtonPressed = true; // L hit
				Varv--;

			}

			if(ButtonPressed) // L PRESSED
			{
				if (Led == 1) // and LED1 Active
				{
					NextState = MoveRight;
					Led=2;
					Speed = Speed-50000;

				}
				else
				{
					MissedBlink();
					R_Score++;
					ScoreRight(R_Score);
					NextState = Start; // hit to early

				}
				}
			else
			{
					if ( Led==0) // no hit or late hit
						{R_Score++;
						MissedBlink();
						ScoreRight(R_Score);
						NextState=Start;

						}
						else
						NextState = MoveLeft; // Ball continues to move left
				}
				if(!ButtonPressed) Led--; // Prepare to turn next LED on
				ButtonPressed = false;
			}
			break;

		default:
			break;
		}

	}

} // End of function PingPong
