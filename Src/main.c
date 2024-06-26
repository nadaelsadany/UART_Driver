/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include"Stm32_F103C6_UART_driver.h"


unsigned char ch;

void Clock_Init()
{
	//Enable Clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

void N_CallBack(void)
{
	UART_MCAL_Recieve_Data(USART1, &ch, Disable);
	UART_MCAL_Send_Data(USART1, &ch, Disable);

}




int main(void)
{



	USART_Config uartCFG;
	Clock_Init();
	uartCFG.BaudRate = USART_BaudRate_115200;
	uartCFG.HW_FlowCtrl = USART_HW_FlowCtrl_NONE;
	uartCFG.IRQ_Enable = USART_IRQ_Enable_RXNE;
	uartCFG.P_IRQ_Call_Back = N_CallBack;
	uartCFG.Parity = USART_Parity_NONE;
	uartCFG.PayLoad_Length = USART_PayLoad_Length_8B;
	uartCFG.Stop_Length = USART_StopBits_1;
	uartCFG.USART_MODE = USART_MODE_TX_RX;

	UART_MCAL_Init(USART1, &uartCFG);
	UART_MCAL_GPIO_Set_Pins(USART1);






	while(1)
	{

	}

	return 0;

}
