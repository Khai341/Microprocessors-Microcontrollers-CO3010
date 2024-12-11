/*
 * timer.h
 *
 *  Created on: Oct 6, 2024
 *      Author: DELL
 */
//#include "main.h"


#ifndef INC_TIMER_H_
#define INC_TIMER_H_

//int timer0_counter = 0;//Will cause error
//int timer0_flag = 0;
//int timer1_counter = 0;
//int timer1_flag = 0;
//int TIMER_CYCLE = 10;

int timer0_counter;
int timer0_flag;
int timer1_counter;
int timer1_flag;
int TIMER_CYCLE;

void setTimer0();
void setTimer1();
void timer_run();
#endif /* INC_TIMER_H_ */
