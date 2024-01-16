/*****************************************************
 * file: RCC_Program.c
 * brief: This file contains the implementation of RCC Peripheral functions
 * author: Ibrahim Saber
 * version: 1.0
 * date: 08-01-2024
 ****************************************************/

#include "stdint.h"

#include "RCC_Private.h"
#include "RCC_Config.h"
#include "RCC_Interface.h"



RCC_ErrorStates_t RCC_SetClkStatus(clockTypes_t type, clockStatus_t status)
{

	RCC_ErrorStates_t ErrorState = OK;
	uint32_t TimeOutCounter = 0;

	switch(status)
	{
		case ON:
		{
			switch (type)
			{
				case PLL:
				{
					/*setting PLLON bit: CR_bit24*/
					RCC -> CR |= (uint32_t)(1 << PLL_ON);

					/*wait on PLLRDY flag: CR_bit25*/
					while((!(1 & (RCC -> CR >> PLL_RDY))) && !(TimeOutCounter > TIME_OUT))
					{
						TimeOutCounter++;
					}

					break;
				}

				case HSE:
				{
					/*setting HSEON bit: CR_bit16*/
					RCC -> CR |= (uint32_t)(1 << HSE_ON);

					/*wait on HSERDY flag: CR_bit17*/
					while((!(1 & (RCC -> CR >> HSE_RDY))) && !(TimeOutCounter > TIME_OUT))
					{
						TimeOutCounter++;
					}

					break;
				}

				case HSI:
				{
					/*setting HSION bit: CR_bit0*/
					RCC -> CR |= (uint32_t)(HSI_ON);

					/*wait on HSIRDY flag: CR_bit1*/
					while((!(1 & (RCC -> CR >> HSI_RDY))) && !(TimeOutCounter > TIME_OUT))
					{
						TimeOutCounter++;
					}

					break;
				}


				default: ErrorState = WRONG_CLK_SRC_INPUT;

			}

			break;
		}

		case OFF:
		{
			switch(type)
			{
				case PLL:
				{
					/*you can't turn off a clk which is selected as a sysClk*/
					if(((RCC -> CFGR & ((uint32_t)CFGR_SW_BITS_MASK)) != PLL) || ((RCC -> CFGR & ((uint32_t)CFGR_SWS_BITS_MASK)) != PLL)) /*12 here means 0b00001100: bits3:2*/
					{
						/*Resetting PLLON bit: CR_bit24*/
						RCC -> CR &= (uint32_t)(~(1 << PLL_ON));
					}

					else
					{
						ErrorState = SWITCHING_OFF_SELECTED_CLK;
					}

					break;
				}

				case HSE:
				{

					if(((RCC -> CFGR & ((uint32_t)CFGR_SW_BITS_MASK)) != HSE) || ((RCC -> CFGR & ((uint32_t)CFGR_SWS_BITS_MASK)) != HSE)) /*12 here means 0b00001100: bits3:2*/

					{
						/*Resetting HSEON bit: CR_bit16*/
						RCC -> CR &= (uint32_t)(~(1 << HSE_ON));
					}

					else
					{
						ErrorState = SWITCHING_OFF_SELECTED_CLK;
					}

					break;

				}

				case HSI:
				{
					if(((RCC -> CFGR & ((uint32_t)CFGR_SW_BITS_MASK)) != HSI) || ((RCC -> CFGR & ((uint32_t)CFGR_SWS_BITS_MASK)) != HSI)) /*12 here means 0b00001100: bits3:2*/

					{
						/*Resetting HSION bit: CR_bit0*/
						RCC -> CR &= HSI_ON;
					}

					else
					{
						ErrorState = SWITCHING_OFF_SELECTED_CLK;
					}

					break;
				}

				default: ErrorState = WRONG_CLK_SRC_INPUT;
			}

		}
	}


	if (TimeOutCounter > TIME_OUT)
	{
		ErrorState = TIME_OUT_EXCEEDED;
	}


	return ErrorState;
}


void RCC_SetSysClk(clockTypes_t type)
{

	RCC -> CFGR &= ~(CFGR_SW_BITS_MASK);
	RCC -> CFGR |= type;
}

void RCC_HSEConfig(void)
{
	RCC -> CR |= (uint32_t)(HSE_BYPASS_STATE << HSE_BYP);
}


RCC_ErrorStates_t RCC_PLLCongfig(uint8_t u8_PLLSource, PLL_MUL_t u32_PLLmultipFactor)
{
	RCC_ErrorStates_t ErrorState = OK;

	/*Make sure PLLON bit in CR reg is 0; PLL is disabled*/
	if((1 & (RCC -> CR >> PLL_ON)) == 0)
	{
		/*Putting the value of the source clk to PLLSRC bit in CFGR Reg*/
		RCC -> CFGR &= ~(1 << PLL_SRC);
		RCC -> CFGR |= (u8_PLLSource << PLL_SRC);

		/*Putting the value of the Multiplication factor into CFGR Reg*/
		RCC -> CFGR &= ~(uint32_t)(CFGR_PLLMUL_BITS_MASK << PLL_MUL0);
		RCC -> CFGR |= (uint32_t)(u32_PLLmultipFactor << PLL_MUL0);
	}

	else
	{
		ErrorState = CONFIGING_PLL_WHILE_ON;
	}


	return ErrorState;
}



void RCC_AHBEnableClk(AHB_Peripheral_t Peripheral)
{
	RCC -> AHBENR &= (uint32_t)~(1 << Peripheral);
	RCC -> AHBENR |= (uint32_t)(1 << Peripheral);
}



void RCC_AHBDisableClk(AHB_Peripheral_t Peripheral)
{
	RCC -> AHBENR &= (uint32_t)~(1 << Peripheral);
}


void RCC_APB2EnableClk(APB2_Peripheral_t Peripheral)
{
	RCC -> APB2ENR &= (uint32_t)~(1 << Peripheral);
	RCC -> APB2ENR |= (uint32_t)(1 << Peripheral);
}


void RCC_APB2DisableClk(APB2_Peripheral_t Peripheral)
{
	RCC -> APB2ENR &= (uint32_t)~(1 << Peripheral);
}


void RCC_APB1EnableClk(APB1_Peripheral_t Peripheral)
{
	RCC -> APB1ENR &= (uint32_t)~(1 << Peripheral);
	RCC -> APB1ENR |= (uint32_t)(1 << Peripheral);
}




void RCC_APB1DisableClk(APB1_Peripheral_t Peripheral)
{
	RCC -> APB1ENR &= (uint32_t)~(1 << Peripheral);
}


