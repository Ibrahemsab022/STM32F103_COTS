/********************************************************************************************************
 * file: RCC_Private.h
 * brief: This file contains the registers mapping, private definitions for the RCC peripheral
 * author: Ibrahim Saber
 * version: 1.0
 * date: 08-01-2024
 ********************************************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_






#define ENABLED 	1u
#define DISABLED 	0u


/***********************************
 * 	Enums for the Registers bits
 * **********************************/

/*CR Register*/
typedef enum
{
	HSI_ON,
	HSI_RDY,
	HSI_TRIM0 = 3,
	HSI_TRIM1,
	HSI_TRIM2,
	HSI_TRIM3,
	HSI_TRIM4,
	HSI_CAL0,
	HSI_CAL1,
	HSI_CAL2,
	HSI_CAL3,
	HSI_CAL4,
	HSI_CAL5,
	HSI_CAL6,
	HSI_CAL7,
	HSE_ON,
	HSE_RDY,
	HSE_BYP,
	CSS_ON,
	PLL_ON = 24,
	PLL_RDY,

}CR_REG_t;


/*CFGR_REG*/
typedef enum
{
	SW0,
	SW1,
	SWS0,
	SWS1,
	HPRE0,
	HPRE1,
	HPRE2,
	HPRE3,
	PPRE1_0,
	PPRE1_1,
	PPRE1_2,
	PPRE2_0,
	PPRE2_1,
	PPRE2_2,
	ADCPRE0,
	ADCPRE1,
	PLL_SRC,
	PLL_XTPRE,
	PLL_MUL0,
	PLL_MUL1,
	PLL_MUL2,
	PLL_MUL3,
	USB_PRE,
	MCO0 = 24,
	MCO1,
	MCO2,

}CFGR_REG_t;



typedef enum
{
	LSI_RDYF,
	LSE_RDYF,
	HSI_RDYF,
	HSE_RDYF,
	PLL_RDYF,
	CSSF = 7,
	LSI_RDYIE,
	LSE_RDYIE,
	HSI_RDYIE,
	HSE_RDYIE,
	PLL_RDYIE,
	LSI_RDYC,
	LSE_RDYC,
	HSI_RDYC,
	HSE_RDYC,
	PLL_RDYC,
	CSSC = 23,

}CIR_REG_t;



/**********************************
 * 		Error Status Enum
 **********************************/




/***************************
 * 			Masks
 * *************************/
#define CFGR_SW_BITS_MASK		3
#define CFGR_SWS_BITS_MASK  	12
#define CFGR_PLLMUL_BITS_MASK	0b1111



#endif
