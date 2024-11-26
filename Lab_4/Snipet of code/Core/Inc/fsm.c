/*
 * fsm.c
 *
 *  Created on: Nov 10, 2024
 *      Author: DELL
 */

#include "fsm.h"
#include <stdlib.h>
/*struct SCH_struct{
	void (*pTask)(void);
	struct SCH_struct* next;
	void SCH_struct(){
		pTask = NULL;
		next = NULL;
	}
	SCH_struct(void (*pTask)(void)){
		this->pTask = pTask;
		next = NULL;
	}
};*/

/*struct SCH_list{
	struct SCH_struct* Executed_head;
	struct SCH_struct* Add_head;
	void SCH_list(void){
		Executed_head = NULL;
		Add_head = NULL;
	}
};*/
void per_function(){
	return;
}
typedef struct node {
	void (*pTask)(void);
	uint32_t DELAY;
	uint32_t PERIOD;
    struct node * next;
} node_t;

typedef struct LL {
    struct node * exe_head;
    struct node * exe_tail;
    struct node * update_head;
} LL_t;
struct LL Linked_List;
void LL_init(){
	Linked_List.exe_head = NULL;
	Linked_List.exe_tail = NULL;
	Linked_List.update_head = NULL;
}
uint32_t LL_add (void (* pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	if (pFunction==NULL || DELAY<0 || PERIOD<0) return -1;

	    struct node* temp = malloc(sizeof(node_t));
	    temp->pTask = pFunction;
	    temp->DELAY = DELAY;
	    temp->PERIOD = PERIOD;
	    temp->next = NULL;

	    if (Linked_List.update_head==NULL){//add_head
	    	//HAL_GPIO_WritePin(GPIOA, OUT_1_Pin, SET);
	        Linked_List.update_head = malloc(sizeof(node_t));
	        Linked_List.update_head = temp;
	        return 0;
	    }

	    if (DELAY<Linked_List.update_head->DELAY){
	        Linked_List.update_head->DELAY = Linked_List.update_head->DELAY - DELAY;
	        temp->next = Linked_List.update_head;

	        if (Linked_List.update_head==Linked_List.exe_head)Linked_List.exe_head = temp;
	        Linked_List.update_head = temp;
	        return 1;
	    }
	    temp->DELAY -= Linked_List.update_head->DELAY;

	    int temp_out = 1;
	    struct node * runner = Linked_List.update_head;
	    while (1){
	        if (runner==NULL) {free(temp);return 0;}
	        if (runner->next==NULL){
	            runner->next = temp;
	            return temp_out;
	        }
	        if (temp->DELAY >= runner->next->DELAY){
	            temp->DELAY -= runner->next->DELAY;
	            runner = runner->next;
	        }
	        else{
	            runner->next->DELAY-=temp->DELAY;
	            temp->next = runner->next;
	            runner->next = temp;
	            return temp_out;
	            break;
	        }
	    }

	    return -1;
}
void SCH_Update(){
	if (Linked_List.update_head==NULL) return;
	if (Linked_List.update_head->DELAY>0){
	    Linked_List.update_head->DELAY--;}
	    if (Linked_List.update_head->DELAY>0){
	      return;
	    }

	    	if (Linked_List.exe_head==NULL)
				Linked_List.exe_head = Linked_List.update_head;
	        while (Linked_List.update_head->next != NULL){
	          if (Linked_List.exe_tail!=NULL)
	            Linked_List.exe_tail->next = Linked_List.update_head;
	          //if (Linked_List.exe_head==NULL)
	            //Linked_List.exe_head = Linked_List.update_head;
	          Linked_List.exe_tail = Linked_List.update_head;
	          Linked_List.update_head = Linked_List.update_head->next;
	          if (Linked_List.update_head->DELAY>0) return;
	        }
	    Linked_List.update_head=NULL;
	    return;
}
void SCH_Dispatch_Tasks(){
	//HAL_GPIO_WritePin(GPIOA, OUT_1_Pin, SET);
	if (Linked_List.exe_head==NULL) return;
	//if (Linked_List.exe_head==Linked_List.update_head) return;
	//HAL_GPIO_WritePin(GPIOA, OUT_3_Pin, SET);
	SCH_Add_Task(Linked_List.exe_head->pTask,Linked_List.exe_head->PERIOD,Linked_List.exe_head->PERIOD);
	// NOTE: Period will become new delay
	Linked_List.exe_head->pTask();
	//HAL_GPIO_WritePin(GPIOA, OUT_1_Pin, SET);
	struct node* temp = Linked_List.exe_head;



	if (Linked_List.exe_head==Linked_List.exe_tail){
		Linked_List.exe_head = NULL;
		Linked_List.exe_tail = NULL;
		free(temp);
		return;
	}
	Linked_List.exe_head = Linked_List.exe_head->next;
	free(temp);
	return;
}
uint32_t SCH_Add_Task(void (* pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	//Temp = new SCH_struct(pFunction);
	//LL_add(per_function,DELAY,PERIOD);

	//if (Linked_List.add_head==NULL) return;
	return LL_add(pFunction,DELAY,PERIOD);
	return 0;
}
uint8_t SCH_Delete_Task(uint32_t taskID){
	if (taskID<0) return -1;
	if (Linked_List.update_head==NULL) return -1;
	if (taskID==0){
		struct node* temp = Linked_List.update_head;
		Linked_List.update_head = Linked_List.update_head->next;
		free(temp);
	}
	struct node* runner =  Linked_List.update_head;
	struct node* runner2 =  Linked_List.update_head;
	runner = runner->next;
	taskID--;
	while (runner!=NULL){
		if (taskID==0){
			runner2->next = runner->next;
			free(runner);
			return 0;
		}
	}
	return 0;
}
