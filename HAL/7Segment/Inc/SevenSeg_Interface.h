/***************************************************************************************************
 * @file  	SevenSeg_Interface.h
 * @brief 	This file contains the function prototypes & public interfaces components of the 7-Segment display Driver
 * @author 	Ibrahim Saber
 * @version 1.0
 * @date 	26 - 1 -2025
 ***************************************************************************************************/
#ifndef SEVENSEG_INTERFACE_H
#define SEVENSEG_INTERFACE_H

		/********************************** Enums **********************************/
typedef enum
{
	SevSegExit_Ok,
	SevSeg_NullPtrError,
	SevSeg_InvalidCommonType,
	SevSeg_DisplayNumberIsOutofRange,
	SevSeg_InvalidPowerState


}SevSegErrorStates_t;


/*Initialization struct configs: common pole type*/
typedef enum
{
	commonCathode,
	commonAnode,
	CommonCathodeDrivenByBJT,
	noCommon

}SevSegCommonPole_t;

typedef enum
{
	PowerOn,
	PowerOff

}SevSegPowerState_t;


						/********************************** Structs **********************************/
typedef struct
{
	SevSegCommonPole_t commonType;

	Pin_t	ControlPin_pin;
	Port_t	ControlPin_port;

	Pin_t	DigA_pin;
	Port_t	DigA_port;

	Pin_t	DigB_pin;
	Port_t	DigB_port;

	Pin_t	DigC_pin;
	Port_t	DigC_port;

	Pin_t	DigD_pin;
	Port_t	DigD_port;

	Pin_t	DigE_pin;
	Port_t	DigE_port;

	Pin_t	DigF_pin;
	Port_t	DigF_port;

	Pin_t	DigG_pin;
	Port_t	DigG_port;

	Pin_t	DigDot_pin;
	Port_t	DigDot_port;

}SevSegConfigs_t;



							/********************************** Functions Prototypes **********************************/

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
SevSegErrorStates_t SevSeg_Init(const SevSegConfigs_t * Copy_pConfigs);




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
SevSegErrorStates_t SevSeg_DisplayNum(const SevSegConfigs_t * Copy_pSevSeg, uint8_t Copy_u8Num);



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
SevSegErrorStates_t SevSeg_PowerState(const SevSegConfigs_t * Copy_pSevSeg, SevSegPowerState_t Copy_u8Power);

#endif
