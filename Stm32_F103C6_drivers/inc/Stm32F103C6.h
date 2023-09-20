/*
 * Stm32F103C6.h
 *
 *  Created on: Dec 27, 2022
 *      Author: Eng. Nada Elsadany
 */

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H
//-----------------------------
//Includes

#include"stdlib.h"
#include<stdint.h>
//-----------------------------


//-----------------------------
//Base addresses for Memories
//-----------------------------
#define SRAM_Memory_Base        			0x20000000UL
#define Flash_Memory_Base        			0x08000000UL
#define System_Memory_Base					0x1FFFF000UL
#define Peripherals_Base        			0x40000000UL
#define Cortex_M3_Peripherals_Base        	0xE0000000UL


//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_Base        			  0x40021000


//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//GPIO
//-----------------------------

//GPIO A&B FULly include
#define GPIOA_Base   				0x40010800UL
#define GPIOB_Base   				0x40010C00UL

//GPIO C&D partial include
#define GPIOC_Base   				0x40011000UL
#define GPIOD_Base    				0x40011400UL

//GPIO E not include
#define GPIOE_Base   				0x40011800UL
//-------------------------------

//EXIT
#define EXTI_Base  					0x40010400UL

//-------------------------------
//AFIO
#define AFIO_Base  				 	0x40010000UL

//-------------------------------
//NVIC
#define NVIC_Base  				 	0xE000E100UL

//-------------------------------
//USART
#define USART1_Base        			0x40013800UL


//NVIC REGISTERS MAP
#define NVIC_ISER0                              *( volatile uint32_t *)(NVIC_Base+0x0000)
#define NVIC_ISER1                              *( volatile uint32_t *)(NVIC_Base+0x0004)
#define NVIC_ISER2                              *( volatile uint32_t *)(NVIC_Base+0x0008)
#define NVIC_ICER0                              *( volatile uint32_t *)(NVIC_Base+0x0080)
#define NVIC_ICER1                              *( volatile uint32_t *)(NVIC_Base+0x0084)
#define NVIC_ICER2                              *( volatile uint32_t *)(NVIC_Base+0x0088)

/************************************************************************************/



//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

//-------------------------------
//USART
#define USART2_Base        			0x40004400UL
#define USART3_Base        			0x40004800UL

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

//GPIO
 typedef struct{

	volatile uint32_t CRL ;
	volatile uint32_t CRH ;
	volatile uint32_t IDR ;
	volatile uint32_t ODR ;
	volatile uint32_t BSRR ;
	volatile uint32_t BRR ;
	volatile uint32_t LCKR ;

}GPIO_Typedef;
//-------------------------------
//RCC
typedef struct{

	volatile uint32_t CR ;
	volatile uint32_t CFGR ;
	volatile uint32_t CIR ;
	volatile uint32_t APB2RSTR ;
	volatile uint32_t APB1RSTR ;
	volatile uint32_t AHBENR ;
	volatile uint32_t APB2ENR ;
	volatile uint32_t APB1ENR ;
	volatile uint32_t BDCR ;
	volatile uint32_t CSR ;


}RCC_Typedef;

//-------------------------------
//EXIT
typedef struct{

	volatile uint32_t IMR ;
	volatile uint32_t EMR ;
	volatile uint32_t RTSR ;
	volatile uint32_t FTSR ;
	volatile uint32_t SWIER ;
	volatile uint32_t PR ;



}EXTI_Typedef;

//-------------------------------
//AFIO
typedef struct{

	volatile uint32_t EVCR ;
	volatile uint32_t MAPR ;
	volatile uint32_t EXTICR[4] ;
	uint32_t RESERVED0 ;
	volatile uint32_t MAPR2 ;



}AFIO_Typedef;

//-------------------------------

//UART
 typedef struct{

	volatile uint32_t SR ;
	volatile uint32_t DR ;
	volatile uint32_t BRR ;
	volatile uint32_t CR1 ;
	volatile uint32_t CR2 ;
	volatile uint32_t CR3 ;
	volatile uint32_t GTPR ;

}USART_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA 		 ((GPIO_Typedef*)(GPIOA_Base))
#define GPIOB 		 ((GPIO_Typedef*)(GPIOB_Base))
#define GPIOC 		 ((GPIO_Typedef*)(GPIOC_Base))
#define GPIOD 		 ((GPIO_Typedef*)(GPIOD_Base))
#define GPIOE 		 ((GPIO_Typedef*)(GPIOE_Base))

#define RCC 		 ((RCC_Typedef*)(RCC_Base))

#define EXTI 		 ((EXTI_Typedef*)(EXTI_Base))

#define AFIO 		 ((AFIO_Typedef*)(AFIO_Base))


#define USART1 		 ((USART_Typedef*)(USART1_Base))
#define USART2 		 ((USART_Typedef*)(USART2_Base))
#define USART3 		 ((USART_Typedef*)(USART3_Base))

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN()   (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()   (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()   (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()   (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()   (RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_CLK_EN()   	 (RCC->APB2ENR |= 1<<0)

#define RCC_USART1_CLK_EN()   (RCC->APB2ENR |= 1<<14)
#define RCC_USART2_CLK_EN()   (RCC->APB1ENR |= 1<<17)
#define RCC_USART3_CLK_EN()   (RCC->APB1ENR |= 1<<18)


// UART RESET
#define RCC_USART1_RESET()   (RCC->APB2RSTR |= 1<<14)
#define RCC_USART2_RESET()   (RCC->APB1RSTR |= 1<<17)
#define RCC_USART3_RESET()   (RCC->APB1RSTR |= 1<<18)

//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI_IRQ Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define EXTI0_IRQ                         6
#define EXTI1_IRQ                         7
#define EXTI2_IRQ                         8
#define EXTI3_IRQ                         9
#define EXTI4_IRQ                         10
#define EXTI5_IRQ                         23
#define EXTI6_IRQ                         23
#define EXTI7_IRQ                         23
#define EXTI8_IRQ                         23
#define EXTI9_IRQ                         23
#define EXTI10_IRQ                        40
#define EXTI11_IRQ                        40
#define EXTI12_IRQ                        40
#define EXTI13_IRQ                        40
#define EXTI14_IRQ                        40
#define EXTI15_IRQ                        40

#define USART1_IRQ                        37
#define USART2_IRQ                        38
#define USART3_IRQ                        39
/*==========================================================*/
/*NVIC IRQ ENABLE/DISABLE MACROS*/
/*==========================================================*/
//ENABLE
#define NVIC_IRQ6_EXTI0_ENABLE()             (NVIC_ISER0 |=(1<<6))
#define NVIC_IRQ7_EXTI1_ENABLE()             (NVIC_ISER0 |=(1<<7))
#define NVIC_IRQ8_EXTI2_ENABLE()             (NVIC_ISER0 |=(1<<8))
#define NVIC_IRQ9_EXTI3_ENABLE()             (NVIC_ISER0 |=(1<<9))
#define NVIC_IRQ10_EXTI4_ENABLE()            (NVIC_ISER0 |=(1<<10))
#define NVIC_IRQ23_EXTI5_ENABLE()            (NVIC_ISER0 |=(1<<23))
#define NVIC_IRQ23_EXTI6_ENABLE()            (NVIC_ISER0 |=(1<<23))
#define NVIC_IRQ23_EXTI7_ENABLE()            (NVIC_ISER0 |=(1<<23))
#define NVIC_IRQ23_EXTI8_ENABLE()            (NVIC_ISER0 |=(1<<23))
#define NVIC_IRQ23_EXTI9_ENABLE()            (NVIC_ISER0 |=(1<<23))
#define NVIC_IRQ40_EXTI10_ENABLE()           (NVIC_ISER1 |=(1<<8)) //40-32=8
#define NVIC_IRQ40_EXTI11_ENABLE()           (NVIC_ISER1 |=(1<<8))
#define NVIC_IRQ40_EXTI12_ENABLE()           (NVIC_ISER1 |=(1<<8))
#define NVIC_IRQ40_EXTI13_ENABLE()           (NVIC_ISER1 |=(1<<8))
#define NVIC_IRQ40_EXTI14_ENABLE()           (NVIC_ISER1 |=(1<<8))
#define NVIC_IRQ40_EXTI15_ENABLE()           (NVIC_ISER1 |=(1<<8))

//DISABLE
#define NVIC_IRQ6_EXTI0_DISABLE()             (NVIC_ICER0 &=~(1<<6))
#define NVIC_IRQ7_EXTI1_DISABLE()             (NVIC_ICER0 &=~(1<<7))
#define NVIC_IRQ8_EXTI2_DISABLE()             (NVIC_ICER0 &=~(1<<8))
#define NVIC_IRQ9_EXTI3_DISABLE()             (NVIC_ICER0 &=~(1<<9))
#define NVIC_IRQ10_EXTI4_DISABLE()            (NVIC_ICER0 &=~(1<<10))
#define NVIC_IRQ23_EXTI5_DISABLE()            (NVIC_ICER0 |=(1<<23))
#define NVIC_IRQ23_EXTI6_DISABLE()            (NVIC_ICER0 |=(1<<23))
#define NVIC_IRQ23_EXTI7_DISABLE()            (NVIC_ICER0 |=(1<<23))
#define NVIC_IRQ23_EXTI8_DISABLE()            (NVIC_ICER0 |=(1<<23))
#define NVIC_IRQ23_EXTI9_DISABLE()            (NVIC_ICER0 |=(1<<23))
#define NVIC_IRQ40_EXTI10_DISABLE()           (NVIC_ICER1 |=(1<<8)) //40-32=8
#define NVIC_IRQ40_EXTI11_DISABLE()           (NVIC_ICER1 |=(1<<8))
#define NVIC_IRQ40_EXTI12_DISABLE()           (NVIC_ICER1 |=(1<<8))
#define NVIC_IRQ40_EXTI13_DISABLE()           (NVIC_ICER1 |=(1<<8))
#define NVIC_IRQ40_EXTI14_DISABLE()           (NVIC_ICER1 |=(1<<8))
#define NVIC_IRQ40_EXTI15_DISABLE()           (NVIC_ICER1 |=(1<<8))


//UART
#define NVIC_IRQ37_USART1_ENABLE()           (NVIC_ISER1 |=(1<<(USART1_IRQ -32)))
#define NVIC_IRQ38_USART2_ENABLE()           (NVIC_ISER1 |=(1<<(USART2_IRQ -32)))
#define NVIC_IRQ39_USART3_ENABLE()           (NVIC_ISER1 |=(1<<(USART3_IRQ -32)))

#define NVIC_IRQ37_USART1_DISABLE()           (NVIC_ICER1 |=(1<<(USART1_IRQ -32)))
#define NVIC_IRQ38_USART2_DISABLE()           (NVIC_ICER1 |=(1<<(USART2_IRQ -32)))
#define NVIC_IRQ39_USART3_DISABLE()           (NVIC_ICER1 |=(1<<(USART3_IRQ -32)))
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*



#endif /* INC_STM32F103C6_H_ */
