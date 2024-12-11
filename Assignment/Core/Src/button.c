/*
 * button.c
 *
 *  Created on: Oct 3, 2024
 *      Author: DELL
 */

#include "button.h"

GPIO_PinState Per1 = SET;
GPIO_PinState Per2 = SET;

GPIO_PinState Per1_2 = SET;
GPIO_PinState Per2_2 = SET;

GPIO_PinState Per1_3 = SET;
GPIO_PinState Per2_3 = SET;

int Per_flag=0;
int Per_flag2=0;
int Per_flag3=0;


int Key0 = NORMAL_STATE;
int Key1 = NORMAL_STATE;
int Key2 = NORMAL_STATE;

int Key3 = NORMAL_STATE;
int timer = 100;

int Key_button1[5]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,100};
int Key_button2[5]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,100};
int Key_button3[5]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,100};
int* Key_button[3] = {Key_button1,Key_button2,Key_button3};
//void Update_Buttons_TODO (){
	//if (Key3==PRESSED_STATE){
		//timer=100;
		//HAL_GPIO_TogglePin(GPIOA, LED_Pin);
		//TODO
	//}
	//return;
//}
int button_flag = 0;

int Button_flag [] = {0,0,0};
int GetButtonFlag(int index){
	if (index<0||index>=3) return 0;
	return Button_flag[index];
}
void ResetButtonFlag(int index){
	if (index<0||index>=3) return ;
	Button_flag[index] = 0;
	return;
}
void Update_Buttons2 (int index){
	GPIO_PinState temp = HAL_GPIO_ReadPin(GPIOA, Button_Pin);
	if (temp==GPIO_PIN_SET){
		Button_flag[index]=1;////////////////
	}
	return;
}
void Update_Buttons(int index){
	int* Key_button0 = Key_button[index];
	int* Button_flag0 = Button_flag;
	Key_button0[0] = Key_button0[1];
	Key_button0[1] = Key_button0[2];
	switch (index){
	case 0:
		Key_button0[2] = HAL_GPIO_ReadPin(GPIOB, Button_Pin);
		break;
	case 1:
		Key_button0[2] = HAL_GPIO_ReadPin(GPIOB, Button_1_Pin);
		break;
	case 2:
		Key_button0[2] = HAL_GPIO_ReadPin(GPIOB, Button_2_Pin);
		break;
	default:
		break;
	}






	//Key_button0[2] = HAL_GPIO_ReadPin(GPIOA, Button_Pin);
	if (Key_button0[0]==Key_button0[1] && Key_button0[1]==Key_button0[2]){

		if (Key_button0[2]==Key_button0[3]){
			if (Key_button0[2]==NORMAL_STATE){
				Key_button0[4] = 100;
			}
			else{

				Key_button0[4]--;
				//Button_flag0[index]=1;
				if (Key_button0[4]<=0){
					Key_button0[4]=100;
					Button_flag0[index]=1;////////////////
					button_flag=2;

				}
			}
		}
		else{
			Key_button0[3]=Key_button0[2];
			if (Key_button0[2]==NORMAL_STATE){
				//Button_flag0[index]=1;
				Key_button0[4] = 100;
			}
			else{
				Button_flag0[index]=1;
				Key_button0[4]--;
			}
		}






/*
		if (Key_button0[3]!=Key_button0[1]){
			Key_button0[3] = Key_button0[1];
			//Update_Buttons_TODO();//Short pressed / flag
			//Button_flag[0]=1;
			Button_flag0[index]=1;
			button_flag=1;

		}
		else{
			Key_button0[4]--;
			if (Key_button0[4]<=0){
				Key_button0[4]=100;
				//Update_Buttons_TODO();//Long pressed
				//button_flag = 2;
				//Button_flag[0]=2;
				Button_flag0[index]=1;////////////////
				button_flag=2;
			}
		}
*/





		//if (Key_button0[3] == NORMAL_STATE){
			//Button_flag0[index]=0;//Button_flag[0]=0;//button_flag = 0;
			//button_flag = 0;
		//}
		//else Key_button0[4]=100;
	}








	return;
}



/*void Update_Buttons(){
	Key0 = Key1;
	Key1 = Key2;
	Key2 = HAL_GPIO_ReadPin(GPIOA, Button_Pin);
	if (Key0==Key1 && Key1==Key2){
		if (Key3!=Key1){
			Key3 = Key1;
			//Update_Buttons_TODO();//Short pressed / flag
			button_flag = 1;

		}
		else{
			timer--;
			if (timer<=0){
				timer=100;
				//Update_Buttons_TODO();//Long pressed
				button_flag = 2;
			}
		}
		if (Key3 == NORMAL_STATE) button_flag = 0;
		else timer=100;
	}
	return;
}*/
void Check_button(GPIO_PinState Per_state){
	if (Per_state==Per1 && Per2==Per1){
		  if ( Per1==GPIO_PIN_RESET) {// && Button_flag[0]!=1
			  if (Button_flag[0]==0){
				  /*HAL_GPIO_WritePin(GPIOB, RED0_Pin|GREEN0_Pin|YELLOW0_Pin|RED1_Pin|GREEN1_Pin|YELLOW1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOA, PA9_Pin|PA10_Pin|PA11_Pin|PA12_Pin|PA13_Pin|PA14_Pin|PA15_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, PB9_Pin|PB10_Pin|PB11_Pin|PB12_Pin|PB13_Pin|PB14_Pin|PB15_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, EN0_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, EN1_Pin, RESET);*/


				  Per_flag++;
				  //FSM_counter=-1;
			  }
			  Button_flag[0]=1;
		  }
		  else Button_flag[0]=0;
	  }
		Per2=Per1;
	  Per1 = Per_state;
}
void Check_button2(GPIO_PinState Per_state){
	if (Per_state==Per1_2 && Per2_2==Per1_2){
		  if ( Per1_2==GPIO_PIN_RESET) {// && Button_flag[0]!=1
			  if (Button_flag[1]==0){
				  /*HAL_GPIO_WritePin(GPIOB, RED0_Pin|GREEN0_Pin|YELLOW0_Pin|RED1_Pin|GREEN1_Pin|YELLOW1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOA, PA9_Pin|PA10_Pin|PA11_Pin|PA12_Pin|PA13_Pin|PA14_Pin|PA15_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, PB9_Pin|PB10_Pin|PB11_Pin|PB12_Pin|PB13_Pin|PB14_Pin|PB15_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, EN0_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, EN1_Pin, RESET);*/
				  Per_flag2++;
				  //HAL_GPIO_TogglePin(GPIOA,Debug_Pin);
				  //FSM_counter=-1;
			  }
			  Button_flag[1]=1;
		  }
		  else Button_flag[1]=0;
	  }
		Per2_2=Per1_2;
	  Per1_2 = Per_state;
}
void Check_button3(GPIO_PinState Per_state){
	if (Per_state==Per1_3 && Per2_3==Per1_3){
		  if ( Per1_3==GPIO_PIN_RESET) {// && Button_flag[0]!=1
			  if (Button_flag[2]==0){
				  /*HAL_GPIO_WritePin(GPIOB, RED0_Pin|GREEN0_Pin|YELLOW0_Pin|RED1_Pin|GREEN1_Pin|YELLOW1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOA, PA9_Pin|PA10_Pin|PA11_Pin|PA12_Pin|PA13_Pin|PA14_Pin|PA15_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, PB9_Pin|PB10_Pin|PB11_Pin|PB12_Pin|PB13_Pin|PB14_Pin|PB15_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, EN0_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, EN1_Pin, RESET);*/
				  Per_flag3++;
				  //FSM_counter=-1;
			  }
			  Button_flag[2]=1;
		  }
		  else Button_flag[2]=0;
	  }
		Per2_3=Per1_3;
	  Per1_3 = Per_state;
}
