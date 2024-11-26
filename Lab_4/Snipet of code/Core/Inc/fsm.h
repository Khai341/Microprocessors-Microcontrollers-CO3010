/*
 * fsm.h
 *
 *  Created on: Nov 10, 2024
 *      Author: DELL
 */
#include "main.h"
#ifndef INC_FSM_H_
#define INC_FSM_H_

void SCH_Update();
void SCH_Dispatch_Tasks();
uint32_t SCH_Add_Task();
uint8_t SCH_Delete_Task(uint32_t taskID);

#endif /* INC_FSM_H_ */
