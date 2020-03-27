#include "stdbool.h"
#include "stdio.h"
#include "gpio.h"
#include "main.h"
#include "stm32l4xx_hal.h"

void Led_on(uint8_t Lednr);
void ScoreLeft(uint8_t LeftScore);
void ScoreRight(uint8_t RightScore);
void MissedBlink(void);
void TotalScore(uint8_t LScore,uint8_t RScore);
