#include <stdio.h>
#include "main.h"
#include "SystemClock_Config.h"
#include "MX_GPIO_Init.h"
#include "MX_CAN2_Init.h"
#include "CAN_TX.h"
#include "filter_config.h"



CAN_HandleTypeDef hcan2;

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_CAN2_Init();
  filter_config();
  HAL_CAN_ActivateNotification(&hcan2, CAN_IT_TX_MAILBOX_EMPTY);
  HAL_CAN_Start(&hcan2);

  while (1)
  {

  }
}
void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
}

void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
}

void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	CAN_TX();
}
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
