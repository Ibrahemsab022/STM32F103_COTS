/*****************************************************
 * file: RCC_Interface.h
 * brief: This file contains the interfaces & func prototypes for the RCC peripheral
 * author: Ibrahim Saber
 * version: 1.0
 * date: 08-01-2024
 ****************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/******************************

      Interfacing Macros

******************************/









/******************************

      Interfacing Enums

******************************/

/*PLL multiplication factors enum*/
typedef enum
{
      PLL_MUL_x2,
	  PLL_MUL_x3,
	  PLL_MUL_x4,
	  PLL_MUL_x5,
	  PLL_MUL_x6,
	  PLL_MUL_x7,
	  PLL_MUL_x8,
	  PLL_MUL_x9,
	  PLL_MUL_x10,
	  PLL_MUL_x11,
	  PLL_MUL_x12,
	  PLL_MUL_x13,
	  PLL_MUL_x14,
	  PLL_MUL_x15,
	  PLL_MUL_x16,

}PLL_MUL_t;

/*Error State Enum*/
typedef enum
{
	TIME_OUT_EXCEEDED,
	OK,
	WRONG_CLK_SRC_INPUT,
	SWITCHING_OFF_SELECTED_CLK,
	CONFIGING_PLL_WHILE_ON,


}RCC_ErrorStates_t;


/*This enum used for indicating the clk sources*/
typedef enum
{
	HSI,
	HSE,
	PLL,

}clockTypes_t;


/*This enum is used for indicating the state of a clk src*/
typedef enum
{
	ON,
	OFF,

}clockStatus_t;



/*this enum contains the Peripherals on the AHB bus*/
typedef enum
{
	AHB_DMA1,
	AHB_DMA2,
	AHB_SRAM,
	AHB_FLITF = 4,
	AHB_CRC = 6,
	AHB_FSMC = 8,
	AHB_SDIO = 10,

}AHB_Peripheral_t;



/*This enum contains the peripherals on the APB2 bus*/
typedef enum
{
	APB2_AlternateFunction,
	APB2_GPIOA = 2,
	APB2_GPIOB,
	APB2_GPIOC,
	APB2_GPIOD,
	APB2_GPIOE,
	APB2_GPIOF,
	APB2_GPIOG,
	APB2_ADC1,
	APB2_ADC2,
	APB2_TIMER1,
	APB2_SPI1,
	APB2_TIMER8,
	APB2_USART1,
	APB2_ADC3,
	APB2_TIMER9 = 19,
	APB2_TIEMR10,
	APB2_TIMER11,

}APB2_Peripheral_t;


/*This enum contains the peripherals on the APB1 bus*/
typedef enum
{
	APB1_TIMER2,
	APB1_TIMER3,
	APB1_TIMER4,
	APB1_TIMER5,
	APB1_TIMER6,
	APB1_TIMER7,
	APB1_TIMER12,
	APB1_TIMER13,
	APB1_TIMER14,
	APB1_WWDG = 11,
	APB1_SPI2 = 14,
	APB1_SPI3,
	APB1_USART2 = 17,
	APB1_USART3,
	APB1_UART4,
	APB1_UART5,
	APB1_I2C1,
	APB1_I2C2,
	APB1_CAN = 25,
	APB1_BKP = 27,
	APB1_PWR,
	APB1_DAC,

}APB1_Peripheral_t;





/******************************

      Configs Structs

******************************/



/******************************

      Functions Prototypes

******************************/

/****************************************************************************************************
 * 	Decription: This Function is used to set the status of the different clk sources 			 	*
 * 	Parameters: - clockTypes_t type: expecting an enum indicating wether it's HSI, HES, of PLL	    *
 * 				- clockStatus_t status: expecting an enum indicating wether it's On or off			*
 * 	Returns: RCC_ErrorStates_t																					*
 * 	Preconditions: -                                                                                *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
RCC_ErrorStates_t RCC_SetClkStatus(clockTypes_t type, clockStatus_t status);


/****************************************************************************************************
 * 	Decription: This Function is used to set the sys clk to a given clk source 			 	        *
 * 	Parameters: - clockTypes_t type: expecting an enum indicating wether it's HSI, HSE, of PLL	    *
 * 	Returns: void																					*
 * 	Preconditions: - The Source clk is off while switching                                                                               *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: Sys clk is set succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
void RCC_SetSysClk(clockTypes_t type);


/****************************************************************************************************
 * 	Decription: This Function is used to configure the HSE clk 			 	*
 * 	Parameters: - HSE_Configs_t *configs:a ptr to sutruct containing the configs	    *
 * 	Returns: void																					*
 * 	Preconditions: -                                                                                *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
void RCC_HSEConfig(void);


/****************************************************************************************************
 * 	Decription: This Function is used to configure the PLL clk 			 	*
 * 	Parameters: - PLL_Configs_t *configs:a ptr to sutruct containing the configs	    *
 * 	Returns: void																					*
 * 	Preconditions: -                                                                                *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
RCC_ErrorStates_t RCC_PLLCongfig(uint8_t u8_PLLSource, PLL_MUL_t u32_PLLmultipFactor);



/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the AHB bus 			 	*
 * 	Parameters: - AHB_Peripheral_t Peripheral: an enum value indicating the required peripheral	    *
 * 	Returns: void																					*
 * 	Preconditions: -                                                                              *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
void RCC_AHBEnableClk(AHB_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the AHB bus 			 	*
 * 	Parameters: - AHB_Peripheral_t Peripheral: an enum value indicating the required peripheral	    *
 * 	Returns: void																					*
 * 	Preconditions: -                                                                              *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
void RCC_AHBDisableClk(AHB_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the APB2 bus 			 	*
 * 	Parameters: - APB2_Peripheral_t Peripheral: an enum value indicating the required peripheral	    *
 * 	Returns: void																					*
 * 	Preconditions: -                                                                              *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
void RCC_APB2EnableClk(APB2_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the APB2 bus 			 	*
 * 	Parameters: - APB2_Peripheral_t Peripheral: an enum value indicating the required peripheral	    *
 * 	Returns: void																					*
 * 	Preconditions: -                                                                              *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
void RCC_APB2DisableClk(APB2_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to enable the clk for given peripheral on the APB1 bus 			 	*
 * 	Parameters: - APB1_Peripheral_t Peripheral: an enum value indicating the required peripheral	    *
 * 	Returns: void																					*
 * 	Preconditions: -                                                                              *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
void RCC_APB1EnableClk(APB1_Peripheral_t Peripheral);



/****************************************************************************************************
 * 	Decription: This Function is used to disable the clk for given peripheral on the APB1 bus 			 	*
 * 	Parameters: - APB1_Peripheral_t Peripheral: an enum value indicating the required peripheral	    *
 * 	Returns: void																					*
 * 	Preconditions: -                                                                              *
 * 				   - 									                                           	*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a clk source state is indicated succesfully				                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Non                                                					*
 ***************************************************************************************************/
void RCC_APB1DisableClk(APB1_Peripheral_t Peripheral);



#endif
