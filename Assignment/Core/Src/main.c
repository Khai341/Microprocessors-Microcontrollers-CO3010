/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "button.h"
#include "timer.h"
#include "i2c-lcd.h"
#include <string.h>
//#include "process.h"
//#include "button.c"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int modes = 1;
int LED_Timer[] = {10,6,4};
int mode_1_counter=0;

int mode_1_modes0 = 0;
int mode_1_modes1 = 1;


int temp2;
int temp3;
int temp4;
//int LED_Buffer[2]={0,0};

int Per_flag1_buffer=0;
int Per_flag2_buffer=0;
int Per_flag3_buffer=0;
GPIO_PinState Per_state = SET;

//GPIO_PinState Per2 = RESET;


int LED0 = 0;
int GetLEDBuffer(){
	return LED0;
}
void UpdateLedBuffer(int in){
	LED0 = in;
}
int LED1 = 0;
int GetLEDBuffer2(){
	return LED1;
}
void UpdateLedBuffer2(int in){
	LED1 = in;
}


void To_char2(char* in1, int in2){
	switch(in2){
	case 0:
		*in1 = '0';
		break;
	case 1:
		*in1 = '1';
			break;
	case 2:
		*in1 = '2';
			break;
	case 3:
		*in1 = '3';
			break;

	case 4:
		*in1 = '4';
			break;
	case 5:
		*in1 = '5';
			break;
	case 6:
		*in1 = '6';
			break;
	case 7:
		*in1 = '7';
			break;
	case 8:
		*in1 = '8';
			break;
	case 9:
		*in1 = '9';
			break;

	default:
		*in1 = '0';
			break;
	}
}
//void string_to_char(int input){
	//string output="";
	//output = "0"+(input/10);
	//return output;
//}
//int Per_Toggle_LED=0;

//int dummy=2002;//3000
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){





	timer_run();

	//Per_state = HAL_GPIO_ReadPin(GPIOA, Button_Pin);
	Per_state = HAL_GPIO_ReadPin(Button_1_GPIO_Port, Button_1_Pin);
	Check_button(Per_state);

	//Per_state = HAL_GPIO_ReadPin(GPIOB, Button_1_Pin);
	Per_state = HAL_GPIO_ReadPin(Button_2_GPIO_Port, Button_2_Pin);
	Check_button2(Per_state);

	//Per_state = HAL_GPIO_ReadPin(GPIOB, Button_2_Pin);
	Per_state = HAL_GPIO_ReadPin(Button_3_GPIO_Port, Button_3_Pin);
	Check_button3(Per_state);


}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 );
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	setTimer0(250);
	int Per_Toggle_LED=0;
  while (1)
  {

  if (timer0_flag!=1) continue;
  setTimer0(250);
			  if (Per_flag!= Per_flag1_buffer){
				  Per_flag1_buffer=Per_flag;
				  mode_1_counter=0;
								//HAL_GPIO_WritePin(GPIOA, Debug2_Pin, SET);
									  modes++;
									  if (modes>=5 || modes<=0)modes=1;
									  temp2 = LED_Timer[0];
									  temp3 = LED_Timer[2];
									  temp4 = LED_Timer[1];
								  }

	char* row1;
	//char row1[100];
	char* row2;
	char temp1_array[9]="A =      ";
	char temp2_array[12]="B =       \0";
	char temp3_array[12]="Var =    \0";
	  		  switch (modes){
	  		  case 1:
	  			  //row1 = "Mode: 1";
				  //row2 = "Counter = ";
	  			  if (mode_1_counter==0){
	  				  mode_1_modes0 = 0;
	  				  mode_1_modes1 = 1;
					  UpdateLedBuffer(LED_Timer[0]);
					  UpdateLedBuffer2(LED_Timer[1]);
					  /////////////////////////////HAL_GPIO_WritePin(GPIOB, RED0_Pin, SET);
					  HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, SET);
					  HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, SET);
					  /////////////////////////////HAL_GPIO_WritePin(GPIOB, GREEN1_Pin, SET);
					  HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, RESET);
					  HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, SET);
	  				//HAL_GPIO_TogglePin(GPIOA,Debug_Pin);//////////////////////////
	  			  }
	  			  if (mode_1_counter<4){//250*4=1000
	  				  mode_1_counter++;
	  				  break;
	  			  }
	  			  mode_1_counter=1;


	  			  int temp_var = 0;
	  			temp_var = GetLEDBuffer();
	  			temp_var--;
	  			  if (temp_var<=0){
	  				  mode_1_modes0++;
	  				  if (mode_1_modes0>=3||mode_1_modes0<0) mode_1_modes0=0;
	  				temp_var = LED_Timer[mode_1_modes0];
	  			  }
	  			  switch (mode_1_modes0){
	  			  case 0:
	  				/////////////////////////////HAL_GPIO_WritePin(GPIOB, RED0_Pin, SET);
	  				HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, SET);
	  				HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, SET);
	  				  break;
	  			  case 1:
	  				/////////////////////////////HAL_GPIO_WritePin(GPIOB, GREEN0_Pin, SET);
	  				HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, SET);
					HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, RESET);
	  				  break;
	  			  case 2:
	  				/////////////////////////////HAL_GPIO_WritePin(GPIOB, YELLOW0_Pin, SET);
	  				HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, RESET);
					HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, SET);
	  				  break;
	  			  default:
	  				  break;
	  			  }
	  			  UpdateLedBuffer(temp_var);
	  			  To_char2(&temp1_array[3],temp_var/10);
	  			  To_char2(&temp1_array[4],temp_var%10);
	  			  row1 = &temp1_array[0];


///////////////////////////////////////////////////
	  			temp_var = GetLEDBuffer2();
	  			temp_var--;
	  			  if (temp_var<=0){
	  				  mode_1_modes1++;
	  				  if (mode_1_modes1>=3||mode_1_modes1<0) mode_1_modes1=0;
	  				temp_var = LED_Timer[mode_1_modes1];
	  			  }
	  			  switch (mode_1_modes1){
	  			  case 0:
	  				/////////////////////////////HAL_GPIO_WritePin(GPIOB, RED1_Pin, SET);
	  				HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, SET);
	  				HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, SET);
	  				  break;
	  			  case 1:
	  				/////////////////////////////HAL_GPIO_WritePin(GPIOB, GREEN1_Pin, SET);
	  				HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, RESET);
	  				HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, SET);
	  				  break;
	  			  case 2:
	  				/////////////////////////////HAL_GPIO_WritePin(GPIOB, YELLOW1_Pin, SET);
	  				HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, SET);
					HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, RESET);
	  				  break;
	  			  default:
	  				  break;
	  			  }
	  			UpdateLedBuffer2(temp_var);

	  			  //row2=temp1;/////////////////////////////
	  			  //To_char(temp1);
				  //strcpy(row2,global_str);

	  			To_char2(&temp2_array[3],temp_var/10);
	  			To_char2(&temp2_array[4],temp_var%10);
	  			row2 = &temp2_array[0];
	  			  break;
	  		  case 2:
	  			  if (Per_Toggle_LED==0){
	  				Per_Toggle_LED=1;
	  				HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, SET);
					HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, SET);
					HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, SET);
					HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, SET);
	  			  }
	  			  else{
	  				Per_Toggle_LED=0;
	  				HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, RESET);
					HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, RESET);
					HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, RESET);
					HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, RESET);
	  			  }
	  			row1 = "Mode: 2";
	  			row2 = "Counter = ";
	  			//////////code//////////HAL_GPIO_WritePin(GPIOB, GREEN0_Pin|YELLOW0_Pin|GREEN1_Pin|YELLOW1_Pin, RESET);
	  			//////////code//////////HAL_GPIO_TogglePin(GPIOB, RED0_Pin|RED1_Pin);

	  			  if (Per_flag2 != Per_flag2_buffer ){
	  				Per_flag2_buffer = Per_flag2;
	  				  temp2++;
	  				  if (temp2>=100)temp2=0;

	  			  	  }

	  			  if (Per_flag3_buffer != Per_flag3 ){
	  				  Per_flag3_buffer = Per_flag3;
	  				  //Button_flag[2]=0;
	  				  LED_Timer[2] = LED_Timer[2] + (temp2-LED_Timer[0]);
	  				  LED_Timer[0] = temp2;
	  				//HAL_GPIO_TogglePin(GPIOA,Debug_Pin);
	  			  	  }



	  			To_char2(&temp3_array[5],temp2/10);
				To_char2(&temp3_array[6],temp2%10);
				row2 = &temp3_array[0];
	  			  break;
	  		  case 3:
	  			if (Per_Toggle_LED==0){
				Per_Toggle_LED=1;
				HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, RESET);
				HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, SET);
				HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, SET);
				HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, RESET);
			  }
			  else{
				Per_Toggle_LED=0;
				HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, RESET);
				HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, RESET);
				HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, RESET);
				HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, RESET);
			  }
	  			row1 = "Mode: 3";
	  			row2 = "Counter = ";
	  			//////////code//////////HAL_GPIO_WritePin(GPIOB, RED0_Pin|GREEN0_Pin|RED1_Pin|GREEN1_Pin, RESET);
	  			//////////code//////////HAL_GPIO_TogglePin(GPIOB, YELLOW0_Pin|YELLOW1_Pin);

	  			  if (Per_flag2 != Per_flag2_buffer){
	  				Per_flag2_buffer = Per_flag2;
	  				  temp3++;
	  				  if (temp3>=100)temp3=0;
	  			  	  }

	  			  if (Per_flag3_buffer != Per_flag3 ){
	  				  Per_flag3_buffer = Per_flag3;
	  				  LED_Timer[3] = LED_Timer[3] + (temp3-LED_Timer[2]);
	  				  LED_Timer[2] = temp3;
	  				//HAL_GPIO_TogglePin(GPIOA,Debug_Pin);
	  			  	  }


	  			To_char2(&temp3_array[5],temp3/10);
				To_char2(&temp3_array[6],temp3%10);
				row2 = &temp3_array[0];
	  			  break;
	  		  case 4:
	  			if (Per_Toggle_LED==0){
				Per_Toggle_LED=1;
				HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, SET);
				HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, RESET);
				HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, RESET);
				HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, SET);
			  }
			  else{
				Per_Toggle_LED=0;
				HAL_GPIO_WritePin(OUTPUT_1_GPIO_Port, OUTPUT_1_Pin, RESET);
				HAL_GPIO_WritePin(OUTPUT_2_GPIO_Port, OUTPUT_2_Pin, RESET);
				HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, RESET);
				HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, RESET);
			  }
	  			//////////code//////////HAL_GPIO_WritePin(GPIOB, RED0_Pin|YELLOW0_Pin|RED1_Pin|YELLOW1_Pin, RESET);
	  			//////////code//////////HAL_GPIO_TogglePin(GPIOB, GREEN0_Pin|GREEN1_Pin);


	  			  if (Per_flag2 != Per_flag2_buffer){
	  				Per_flag2_buffer = Per_flag2;
	  				  temp4++;
	  				  if (temp4>=100)temp4=0;
	  				  //HAL_GPIO_TogglePin(GPIOA,Debug_Pin);
	  			  	  }

	  			  if (Per_flag3_buffer != Per_flag3  ){
	  				  Per_flag3_buffer = Per_flag3;
	  				LED_Timer[2] = LED_Timer[2] + (temp4-LED_Timer[1]);
	  				  LED_Timer[1] = temp4;
	  				  //HAL_GPIO_TogglePin(GPIOA,Debug_Pin);
	  			  	  }

	  			  row1 = "Mode: 4";
	  			  row2 = "Counter = ";

	  			  row2 = row2 + 'f';

	  			To_char2(&temp3_array[5],temp4/10);
				To_char2(&temp3_array[6],temp4%10);
				row2 = &temp3_array[0];
	  			  break;
	  		  default:
	  			  break;
	  		  }
	  ////////////////////////////////////////////////////////////////////////////////////////////

	  		  lcd_goto_XY(0, 0);
	  		  lcd_send_string(row1);
	  		lcd_goto_XY(1, 0);
			  lcd_send_string(row2);
	  		  setTimer0(250);






    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 9;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 7999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OUTPUT_4_GPIO_Port, OUTPUT_4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, OUTPUT_1_Pin|OUTPUT_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OUTPUT_3_GPIO_Port, OUTPUT_3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Buttonx_Pin Button1x_Pin Button2x_Pin */
  GPIO_InitStruct.Pin = Buttonx_Pin|Button1x_Pin|Button2x_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Button3x_Pin Button_Pin */
  GPIO_InitStruct.Pin = Button3x_Pin|Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : OUTPUT_4_Pin */
  GPIO_InitStruct.Pin = OUTPUT_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OUTPUT_4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : OUTPUT_1_Pin OUTPUT_2_Pin */
  GPIO_InitStruct.Pin = OUTPUT_1_Pin|OUTPUT_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Button_1_Pin Button_3_Pin Button_2_Pin */
  GPIO_InitStruct.Pin = Button_1_Pin|Button_3_Pin|Button_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : OUTPUT_3_Pin */
  GPIO_InitStruct.Pin = OUTPUT_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OUTPUT_3_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
