/***************************************************************************************************
 * file: Stm32F103C8T6.h
 * brief: This file contains the base addresses and sturcuts for all the preipherals
 * author: Ibrahim Saber
 * version: 1.0
 * date: 16 - 10 -2024
 * Last Update:
 ***************************************************************************************************/
#ifndef STM32F103C8T6_H
#define STM32F103C8T6_H


/******************* Various Memories Base Addresses *******************/
#define FLASH_BASE_ADDRESS		0x20000000UL
#define SRAM_BASE_ADDRESS		0x08000000UL



/******************* AHB Peripherals Base Addresses *******************/
#define RCC_BASE_ADDRESS		0x40021000U



/******************* APB1 Peripheral Base Addresses *******************/




/******************* APB2 Peripheral Base Addresses *******************/
#define GPIOA_BASE_ADDRESS      0x40010800U
#define GPIOB_BASE_ADDRESS      0x40010C00U
#define GPIOC_BASE_ADDRESS      0x40011000U
#define GPIOD_BASE_ADDRESS      0x40011400U
#define GPIOE_BASE_ADDRESS      0x40011800U
#define GPIOF_BASE_ADDRESS      0x40011C00U
#define GPIOG_BASE_ADDRESS      0x40012000U



/******************* RCC Registers Definition Structures *******************/
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;

}RCC_Register_t;



/******************* GPIO Registers Definition Structures *******************/
typedef struct
{
	volatile uint32_t CR[2];                    /*Port config register Low(PIN0 - PIN7) & High(PIN8 - PIN15)*/
	volatile uint32_t IDR;                      /*Port Input data reg*/
	volatile uint32_t ODR;                      /*Port output data reg*/
	volatile uint32_t BSRR;                     /*Port bit set reset reg*/
	volatile uint32_t BRR;                      /*Port bit reset reg*/
	volatile uint32_t LCKR;                     /*Port Configuration LCK Register*/
	volatile uint32_t EVCR;                     /*Event control reg*/
	volatile uint32_t AFIO_MAPR;				/*AF remap and debug I/O config reg*/
	volatile uint32_t AFIO_EXTICR[4];			/*External Interrupt config reg1,2,3*/
	volatile uint32_t AFIO_MAPR2;				/*AF remap and debug I/O config reg2*/

}GPIO_RegDef_t;



/******************* RCC Peripheral Definitions *******************/
#define RCC		((RCC_Register_t *) RCC_BASE_ADDRESS)


/******************* GPIO Peripheral Definitions *******************/
#define GPIOA		((GPIO_RegDef_t *) GPIOA_BASE_ADDRESS)
#define GPIOB		((GPIO_RegDef_t *) GPIOB_BASE_ADDRESS)
#define GPIOC		((GPIO_RegDef_t *) GPIOC_BASE_ADDRESS)
#define GPIOD		((GPIO_RegDef_t *) GPIOD_BASE_ADDRESS)
#define GPIOE		((GPIO_RegDef_t *) GPIOE_BASE_ADDRESS)
#define GPIOF		((GPIO_RegDef_t *) GPIOF_BASE_ADDRESS)
#define GPIOG		((GPIO_RegDef_t *) GPIOG_BASE_ADDRESS)





















#endif
