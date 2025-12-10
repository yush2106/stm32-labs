/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "lcd.h"
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

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM2_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint8_t click_flag = 0;
char I2C_ADDRESS = 0xA0;    //write address is 0xA0
char read_data[5] = {0};    //read data
uint8_t SevenSegmentStep = 0;    //7 segment display step
char DigitNumberArray[] = "    ";    //7 segment digit array

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
  //click the onboard button
  if(GPIO_Pin == GPIO_PIN_13) {
	SevenSegmentStep = 0;    //reset 7 segment display step
	memset(DigitNumberArray, ' ', 4);    //reset 7 segment digit array
	click_flag = 1;    //click flag on
  }
}

//read EEPROM
void READ_EEPROM(uint16_t MemAddress, uint8_t *pData, uint16_t length) {
  uint8_t address[2];
  address[0] = (uint8_t)((MemAddress & 0xFF00) >> 8);    //move data to right
  address[1] = (uint8_t)(MemAddress & 0x00FF);    //retrieve the right data
  HAL_I2C_Master_Transmit(&hi2c1, I2C_ADDRESS, address, 2, HAL_MAX_DELAY);    //transmit read command
  HAL_I2C_Master_Receive(&hi2c1, I2C_ADDRESS, pData, length, HAL_MAX_DELAY);    //received data and storage data
}

//write EEPROM
void WRITE_EEPROM(uint16_t MemAddress, uint8_t *pData, uint16_t length) {
  uint8_t data[64];    //define the enough space for write address and write data
  data[0] = (uint8_t)((MemAddress & 0xFF00) >> 8);    //move data to right
  data[1] = (uint8_t)(MemAddress & 0x00FF);    //retrieve the right data
  memcpy(&data[2], pData, length);    //set the data to the new address
  HAL_I2C_Master_Transmit(&hi2c1, I2C_ADDRESS, data, length + 2, HAL_MAX_DELAY);    //transmit write command, the length should contain the address
  while(HAL_I2C_Master_Transmit(&hi2c1, I2C_ADDRESS, NULL, 0, HAL_MAX_DELAY) != HAL_OK);    //wait for transmit process
}

osThreadId_t EEPROMTaskHandle;
const osThreadAttr_t EEPROMTask_attributes = {
  .name = "EEPROMTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

osThreadId_t LCDTaskHandle;
const osThreadAttr_t LCDTask_attributes = {
  .name = "LCDTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

osThreadId_t SevenSegmentTaskHandle;
const osThreadAttr_t SevenSegmentTask_attributes = {
  .name = "SevenSegmentTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

uint8_t DisplayLCDText = 0;
int8_t LCD_Step = 0;

void EEPROMTask(void *argument) {
  while (1) {
	if(click_flag == 1) {
	  click_flag = 0;    //reset flag
	  DisplayLCDText = 0;    //do not display LCD

	  LCD_Clear();    //clear LCD
	  LCD_Write_Cmd(0x06);    //DB1 -> On, automatic increment, DB0 - > off, display shift off
	  osDelay(5);    //delay

	  char write_data[5];    //write data
	  uint32_t seed = HAL_GetTick();   //tick seed
	  srand(seed);    //random seed
	  uint32_t rand_value = rand() % 10000;   // 0 ~ 9999
	  snprintf(write_data, sizeof(write_data), "%4lu", rand_value);    //char length is 4
	  LCD_Puts("Generate Number:");    //write string
	  LCD_GoTo_Position(1, 0);    //move to row 1, column 0
	  LCD_Puts(write_data);    //write sting

	  osDelay(2000);    //delay

	  LCD_Clear();    //clear LCD
	  LCD_Puts("Write EEPROM");    //write string
	  //write data
	  WRITE_EEPROM(0x0100, (uint8_t *)write_data, strlen(write_data));

	  osDelay(2000);    //delay

	  LCD_Clear();    //clear LCD
	  LCD_Puts("Read EEPROM");    //write string
	  //read data
	  READ_EEPROM(0x0100, (uint8_t *)read_data, 4);

	  osDelay(2000);    //delay

	  LCD_Clear();    //clear LCD
	  LCD_GoTo_Position(0, 1);    //move to row 0, column 1
	  LCD_Puts("Random Number:");    //write string
	  LCD_GoTo_Position(1, 6);    //move to row 1, column 6
	  LCD_Puts(read_data);    //write string
	  osDelay(3500);    //delay

	  LCD_Clear();    //clear LCD
	  LCD_Write_Cmd(0x07);    //DB1 -> On, automatic increment, DB0 - > on, display shift
	  osDelay(5);    //delay
	  LCD_GoTo_Position(0, 15);    //move to row 0

	  LCD_Step = 0;    //set initial LCD step
	  DisplayLCDText = 1;    //display LCD text
	}
	osDelay(1);    //delay
  }
}

char Line1[] = "Random Number:";

void LCDTask(void *argument) {
  while (1) {
	uint8_t length_line1 = strlen(Line1);    //line1 length
	uint8_t length_num = strlen(read_data);    //read data length
	if(DisplayLCDText == 1) {
	  if(LCD_Step < length_line1) {
		LCD_PutCh(Line1[LCD_Step]);    //line1 text
	  }
	  else if(LCD_Step >= length_line1
          && LCD_Step < (length_line1 + length_num)){
	    LCD_PutCh(read_data[LCD_Step - length_line1]);    //read data
	  }
	  else {
	     LCD_Puts(" ");    //space
	  }
	  LCD_Step++;    //next step
	  if(LCD_Step > (length_line1 + length_num + 14)) {
	    LCD_Step = 0;    //reset step
	    LCD_Clear();    //clear LCD
	    LCD_GoTo_Position(0, 15);    //move to row 0
	  }
    }
	osDelay(300);    //delay
  }
}

//array of register hex number
int LED_Hex[] = {
  0x3F,    // 0
  0x06,    // 1
  0x5B,    // 2
  0x4F,    // 3
  0x66,    // 4
  0x6D,    // 5
  0x7D,    // 6
  0x07,    // 7
  0x7F,    // 8
  0x6F     // 9
};

void SevenSegmentTask(void *argument) {
  while (1) {
	if(DisplayLCDText == 1) {
	  //7 segment display step
	  uint8_t text_length = strlen(read_data);    //read data length
	  uint8_t digit_position = 0;    //digit position
	  //increasing char number
	  if (SevenSegmentStep < text_length) {
		//space char
		for(int j = 0; j < (text_length - SevenSegmentStep - 1); j++) {
		  DigitNumberArray[digit_position] = ' ';
		  digit_position++;
		}
		//read data number
		for(int j = 0; j < (SevenSegmentStep + 1); j++) {
		  DigitNumberArray[digit_position] = read_data[j];
		  digit_position++;
		}
	  }
	  //decreasing char number
	  else if (SevenSegmentStep >= text_length) {
		//read data number
		for(int j = 0; j < text_length - (SevenSegmentStep + 1 - text_length); j++) {
		  DigitNumberArray[digit_position] = read_data[j + 1 + (SevenSegmentStep - text_length)];
		  digit_position++;
		}
		//space char
		for(int j = 0; j < (SevenSegmentStep - text_length + 1); j++) {
		  DigitNumberArray[digit_position] = ' ';
		  digit_position++;
		}
      }

	  //next step
	  SevenSegmentStep++;
	  if(SevenSegmentStep > 6) {
	    SevenSegmentStep = 0;
	  }
	}
	osDelay(750);    //delay
  }
}

//uint8_t ArrayLength = 4;    //array length
//Digit Array
int DigitArray[] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3};

uint8_t DigitPosition = 0;    //digit position
void ProcessDisplayNumber() {
  uint8_t ArrayLength = strlen(DigitNumberArray);
  if(DisplayLCDText == 0) {
	HAL_GPIO_WritePin(GPIOC, DigitArray[DigitPosition], GPIO_PIN_RESET);    //disabled
	return;
  }
  //previous digit position
  uint8_t PreviousPosition = (DigitPosition == 0) ? (ArrayLength-1) : (DigitPosition-1);
  HAL_GPIO_WritePin(GPIOC, DigitArray[PreviousPosition], GPIO_PIN_RESET);    //disabled
  if(DigitNumberArray[DigitPosition] == ' ') {
	HAL_GPIO_WritePin(GPIOC, DigitArray[PreviousPosition], GPIO_PIN_RESET);    //disabled
  }
  else {
	uint8_t num = DigitNumberArray[DigitPosition] - '0';    //convert char to integer
    GPIOB -> ODR = LED_Hex[num];    //write to register
    HAL_GPIO_WritePin(GPIOC, DigitArray[DigitPosition], GPIO_PIN_SET);    //enabled
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  if(htim == &htim2) {
	uint8_t ArrayLength = strlen(DigitNumberArray);
    ProcessDisplayNumber();    //display 7 segment digit
    DigitPosition++;    //next digit position
    //reset to first digit position
    if(DigitPosition > ArrayLength-1) {
	  DigitPosition = 0;    //return to the first digit position
    }
  }
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
  MX_I2C1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  LCD_initial();    //initialize lcd
  HAL_TIM_Base_Start_IT(&htim2);    //start timer

  //EEPROM task handler
  EEPROMTaskHandle = osThreadNew(EEPROMTask, NULL, &EEPROMTask_attributes);
  //LCD task handler
  LCDTaskHandle = osThreadNew(LCDTask, NULL, &LCDTask_attributes);
  //SevenSegment task handler
  SevenSegmentTaskHandle = osThreadNew(SevenSegmentTask, NULL, &SevenSegmentTask_attributes);

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

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

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
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
  hi2c1.Init.Timing = 0x10909CEC;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
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
  htim2.Init.Prescaler = 39999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_DOWN;
  htim2.Init.Period = 7;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV2;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
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
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3
                           PC4 PC5 PC6 PC7
                           PC8 PC9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3
                           PB4 PB5 PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

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
#ifdef USE_FULL_ASSERT
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
