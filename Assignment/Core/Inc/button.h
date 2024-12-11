/*
 * button.h
 *
 *  Created on: Oct 3, 2024
 *      Author: DELL
 */

#include "main.h"// So that yin key = NORMAL on button.c not error
//#include "timer.h"
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int Button_flag [3];
int Key_button1[5];
int Key_button2[5];
int Key_button3[5];
//int Button_flag [] = {0,0,0};
//int Button_flag[3];
//int button_flag;
int GetButtonFlag();
void ResetButtonFlag();
void Update_Buttons();

void Check_button(GPIO_PinState Per_state);
void Check_button2(GPIO_PinState Per_state);
void Check_button3(GPIO_PinState Per_state);

int Per_flag;
int Per_flag2;
int Per_flag3;
#endif /* INC_BUTTON_H_ */
