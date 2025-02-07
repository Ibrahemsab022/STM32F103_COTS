/***************************************************************************************************
 * @file  	SevenSeg_Prog.c
 * @brief 	This file contains the function implementation of the 7-Segment display Driver
 * @author 	Ibrahim Saber
 * @version 1.0
 * @date 	27 - 1 -2025
 ***************************************************************************************************/
#include <stdint.h>

#include "Stm32F103C8T6.h"

#include "GPIO_Interface.h"

#include "SevenSeg_Prv.h"
#include "SevenSeg_Interface.h"





/****************************************************************************************************
 * 	@brief		 This Function is used to initialize the 7Segment display.
 * 	@param 		 SevSegConfigs_t* Copy_pConfigs: ptr to struct containing the configs.
 * 	@return 	 SevSegErrorStates_t: return errorState
 * 	@pre		 RCC is initialized and working
 * 				 Clk enabled for GPIO Peripheral
 * 				 Switch is enabled for this component on the Kit(if exists)

 * 	@post 		 7seg is initailized and ready to display numbers
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
SevSegErrorStates_t SevSeg_Init(const SevSegConfigs_t * Copy_pConfigs)
{
	SevSegErrorStates_t Local_u8ErrorState = SevSegExit_Ok;

	if(Copy_pConfigs != NULL)
	{

		GPIO_PinConfig_t LedA = {
									.Mode = OUTPUT_10MHz,
									.OutputType = OUTPUT_PUSH_PULL,
									.Port = Copy_pConfigs -> DigA_port,
									.PinNum = Copy_pConfigs -> DigA_pin
		};

		GPIO_PinConfig_t LedB = {
									.Mode = OUTPUT_10MHz,
									.OutputType = OUTPUT_PUSH_PULL,
									.Port = Copy_pConfigs -> DigB_port,
									.PinNum = Copy_pConfigs -> DigB_pin
		};


		GPIO_PinConfig_t LedC = {
									.Mode = OUTPUT_10MHz,
									.OutputType = OUTPUT_PUSH_PULL,
									.Port = Copy_pConfigs -> DigC_port,
									.PinNum = Copy_pConfigs -> DigC_pin
		};


		GPIO_PinConfig_t LedD = {
									.Mode = OUTPUT_10MHz,
									.OutputType = OUTPUT_PUSH_PULL,
									.Port = Copy_pConfigs -> DigD_port,
									.PinNum = Copy_pConfigs -> DigD_pin
		};


		GPIO_PinConfig_t LedE = {
									.Mode = OUTPUT_10MHz,
									.OutputType = OUTPUT_PUSH_PULL,
									.Port = Copy_pConfigs -> DigE_port,
									.PinNum = Copy_pConfigs -> DigE_pin
		};

		GPIO_PinConfig_t LedF = {
									.Mode = OUTPUT_10MHz,
									.OutputType = OUTPUT_PUSH_PULL,
									.Port = Copy_pConfigs -> DigF_port,
									.PinNum = Copy_pConfigs -> DigF_pin
		};

		GPIO_PinConfig_t LedG = {
									.Mode = OUTPUT_10MHz,
									.OutputType = OUTPUT_PUSH_PULL,
									.Port = Copy_pConfigs -> DigG_port,
									.PinNum = Copy_pConfigs -> DigG_pin
		};

		GPIO_PinConfig_t LedDot = {
									.Mode = OUTPUT_10MHz,
									.OutputType = OUTPUT_PUSH_PULL,
									.Port = Copy_pConfigs -> DigDot_port,
									.PinNum = Copy_pConfigs -> DigDot_pin
		};

		GPIO_PinConfig_t SevSegCommonPole = {
									.Mode = OUTPUT_10MHz,
									.OutputType = OUTPUT_PUSH_PULL,
									.Port = Copy_pConfigs -> ControlPin_port,
									.PinNum = Copy_pConfigs -> ControlPin_pin
};

		/*init the sevSeg gpio pins*/
		GPIO_u8PinInit((const GPIO_PinConfig_t *) &LedA);
		GPIO_u8PinInit((const GPIO_PinConfig_t *) &LedB);
		GPIO_u8PinInit((const GPIO_PinConfig_t *) &LedC);
		GPIO_u8PinInit((const GPIO_PinConfig_t *) &LedD);
		GPIO_u8PinInit((const GPIO_PinConfig_t *) &LedE);
		GPIO_u8PinInit((const GPIO_PinConfig_t *) &LedF);
		GPIO_u8PinInit((const GPIO_PinConfig_t *) &LedG);
		GPIO_u8PinInit((const GPIO_PinConfig_t *) &LedDot);
		GPIO_u8PinInit((const GPIO_PinConfig_t *) &SevSegCommonPole);


		/*confirm that the seg is switched off */
		if((Copy_pConfigs -> commonType) == commonAnode)
		{
			GPIO_u8SetPinValue((Copy_pConfigs -> ControlPin_port), (Copy_pConfigs -> ControlPin_pin), PIN_LOW);

		}

		else if((Copy_pConfigs -> commonType) == commonCathode)
		{
			GPIO_u8SetPinValue((Copy_pConfigs -> ControlPin_port), (Copy_pConfigs -> ControlPin_pin), PIN_HIGH);

		}

		else
		{
			Local_u8ErrorState = SevSeg_InvalidCommonType;
		}



	}

	else
	{
		Local_u8ErrorState = SevSeg_NullPtrError;
	}



	return Local_u8ErrorState;


}




/****************************************************************************************************
 * 	@brief		 This Function is used to display a number on the 7Segment display.
 * 	@param 		 uint8_t Copy_u8Num: a number between 0-9 to be displayed.
 * 	@return 	 SevSegErrorStates_t: return errorState
 * 	@pre		 7Seg is initialized usint SevSeg_Init()
 *
 * 	@post 		 Number is displayed
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
SevSegErrorStates_t SevSeg_DisplayNum(const SevSegConfigs_t * Copy_pSevSeg, uint8_t Copy_u8Num)
{

	SevSegErrorStates_t Local_u8ErrorState = SevSegExit_Ok;

	if(Copy_pSevSeg != NULL)
	{
		if((Copy_u8Num >= 0) && (Copy_u8Num <= 9))
		{

			GPIO_u8SetPinValue((Copy_pSevSeg -> DigA_port),   (Copy_pSevSeg -> DigA_pin),     (GET_BIT(BinaryCodedDecimal[Copy_u8Num], 7)));
			GPIO_u8SetPinValue((Copy_pSevSeg -> DigB_port),   (Copy_pSevSeg -> DigB_pin),     (GET_BIT(BinaryCodedDecimal[Copy_u8Num], 6)));
			GPIO_u8SetPinValue((Copy_pSevSeg -> DigC_port),   (Copy_pSevSeg -> DigC_pin),     (GET_BIT(BinaryCodedDecimal[Copy_u8Num], 5)));
			GPIO_u8SetPinValue((Copy_pSevSeg -> DigD_port),   (Copy_pSevSeg -> DigD_pin),     (GET_BIT(BinaryCodedDecimal[Copy_u8Num], 4)));
			GPIO_u8SetPinValue((Copy_pSevSeg -> DigE_port),   (Copy_pSevSeg -> DigE_pin),     (GET_BIT(BinaryCodedDecimal[Copy_u8Num], 3)));
			GPIO_u8SetPinValue((Copy_pSevSeg -> DigF_port),   (Copy_pSevSeg -> DigF_pin),     (GET_BIT(BinaryCodedDecimal[Copy_u8Num], 2)));
			GPIO_u8SetPinValue((Copy_pSevSeg -> DigG_port),   (Copy_pSevSeg -> DigG_pin), 	  (GET_BIT(BinaryCodedDecimal[Copy_u8Num], 1)));
			GPIO_u8SetPinValue((Copy_pSevSeg -> DigDot_port), (Copy_pSevSeg -> DigDot_pin),   (GET_BIT(BinaryCodedDecimal[Copy_u8Num], 0)));

		}

		else
		{
			Local_u8ErrorState = SevSeg_DisplayNumberIsOutofRange;
		}
	}

	else
	{
		Local_u8ErrorState = SevSeg_NullPtrError;
	}


	return Local_u8ErrorState;

}




/****************************************************************************************************
 * 	@brief		 This Function is used to ON/OFF the 7Segment controlling the common pole.
 * 	@param 		 SevSegPowerState_t Copy_u8Power: required power state On/Off.
 * 	@return 	 SevSegErrorStates_t: return errorState
 * 	@pre		 7Seg is initialized usint SevSeg_Init()
 * 				 Switch is enabled for this component on the Kit(if exists)
 *
 *
 * 	@post 		 7Sef is on/off
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
SevSegErrorStates_t SevSeg_PowerState(const SevSegConfigs_t * Copy_pSevSeg, SevSegPowerState_t Copy_u8Power)
{
	SevSegErrorStates_t Local_u8ErrorState = SevSegExit_Ok;

	if(Copy_pSevSeg != NULL)
	{
		if(Copy_u8Power == PowerOn)
		{
			if((Copy_pSevSeg -> commonType) == commonAnode)
			{
				GPIO_u8SetPinValue((Copy_pSevSeg -> ControlPin_port), (Copy_pSevSeg -> ControlPin_pin), PIN_HIGH);

			}

			else if((Copy_pSevSeg -> commonType) == CommonCathodeDrivenByBJT)
			{
				GPIO_u8SetPinValue((Copy_pSevSeg -> ControlPin_port), (Copy_pSevSeg -> ControlPin_pin), PIN_HIGH);

			}

			else if((Copy_pSevSeg -> commonType) == commonCathode)
			{
				GPIO_u8SetPinValue((Copy_pSevSeg -> ControlPin_port), (Copy_pSevSeg -> ControlPin_pin), PIN_LOW);

			}


		}

		else if(Copy_u8Power == PowerOff)
		{
			if((Copy_pSevSeg -> commonType) == commonAnode)
			{
				GPIO_u8SetPinValue((Copy_pSevSeg -> ControlPin_port), (Copy_pSevSeg -> ControlPin_pin), PIN_LOW);

			}

			else if((Copy_pSevSeg -> commonType) == CommonCathodeDrivenByBJT)
			{
				GPIO_u8SetPinValue((Copy_pSevSeg -> ControlPin_port), (Copy_pSevSeg -> ControlPin_pin), PIN_LOW);

			}

			else if((Copy_pSevSeg -> commonType) == commonCathode)
			{
				GPIO_u8SetPinValue((Copy_pSevSeg -> ControlPin_port), (Copy_pSevSeg -> ControlPin_pin), PIN_HIGH);

			}


		}

		else
		{
			Local_u8ErrorState = SevSeg_InvalidPowerState;
		}

	}

	else
	{
		Local_u8ErrorState = SevSeg_NullPtrError;
	}


	return Local_u8ErrorState;
}








