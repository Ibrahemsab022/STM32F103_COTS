/***************************************************************************************************
 * file: GPIO_Prog.c
 * brief: This file contains the Implementation of the GPIO driver functions
 * author: Ibrahim Saber
 * version: 1.0
 * date: 16 - 10 -2024
 ***************************************************************************************************/

#include "stdint.h"

#include "Stm32F103C8T6.h"

#include "GPIO_Prv.h"
#include "GPIO_Interface.h"


/****************************************************************************************************
 * 	Decription: This Function is used to init a GPIO pin.
 * 	Parameters: - const PinConfig_t * PinConfigs: is a pointer to a struct contain the configs.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Pin is configed
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/




static GPIO_RegDef_t * GPIO_PORTS[GPIO_PORTS_NUM] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG};




GPIOErrorStates_t GPIO_u8PinInit(const GPIO_PinConfig_t * PinConfigs)
{

	GPIOErrorStates_t Local_u8ErrorState = Exit_Ok;

	if (PinConfigs != NULL)
	{
		if((PinConfigs -> Port <= PORTG) && (PinConfigs -> PinNum <= PIN15))
		{

			/*Retrieving correct pin Num and retrieving the CR register accordingly CRl(0-7) CRh(8-15)*/
			uint8_t Local_u8RegNum = (PinConfigs -> PinNum) / CR_PIN_SHIFTINTG;
			uint8_t Local_u8BitNum = (PinConfigs -> PinNum) % CR_PIN_SHIFTINTG;

			/*Holding all the cnfs togerher*/
			uint8_t Local_u8PinFullCnf = 0;


			/*Combining Mode & cnfs together for it to be easier in Oring with the CR register*/
			if ((PinConfigs -> Mode) == INPUT)
			{
				/*Combining Mode & cnfs together for it to be easier in Oring with the CR register*/
				Local_u8PinFullCnf = (((PinConfigs -> InputType) << GPIO_2BIT_PIN_REG) | (PinConfigs -> Mode));
			}

			else
			{
				Local_u8PinFullCnf = (((PinConfigs -> OutputType) << GPIO_2BIT_PIN_REG) | (PinConfigs -> Mode));

			}



			/*Implementing the configs*/
			(GPIO_PORTS[PinConfigs -> Port] -> CR[Local_u8RegNum]) &= ~(GPIO_4BIT_MASK << (Local_u8BitNum * GPIO_4BIT_PIN_REG));
			(GPIO_PORTS[PinConfigs -> Port] -> CR[Local_u8RegNum]) |= (Local_u8PinFullCnf << (Local_u8BitNum * GPIO_4BIT_PIN_REG));



		}

		else
		{
			Local_u8ErrorState = InvalidPinOrPortNum;
		}

	}

	else
	{
		Local_u8ErrorState = NullPtr;
	}


	return Local_u8ErrorState;


}




/****************************************************************************************************
 * 	Decription: This Function is used to init a GPIO Port (use it when all pins have same configs)
 * 	Parameters: - const PinConfig_t * PinConfigs: is a pointer to a struct contain the configs.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Port is configed
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
GPIOErrorStates_t GPIO_u8PortInit(const GPIO_PinConfig_t * PinConfigs)
{
	GPIOErrorStates_t Local_u8ErrorState = Exit_Ok;





	return Local_u8ErrorState;
}





/****************************************************************************************************
 * 	Decription: This Function is used to set a GPIO pin.
 * 	Parameters: - port_t Port: is an enum holding the port.
 *				- Pin_t PinNum: is an enum holding the pin number.
 *				- PinVal_t PinVal: is an enum holding the pin value.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 *				   - Pin is Configed usin GPIO_u8PinInit as OUTPUT
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Pin is set to a value
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
GPIOErrorStates_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal)
{
	uint8_t Local_u8ErrorState = Exit_Ok;


	if((Port <= PORTG) && (PinNum <= PIN15))
	{
		if(PinVal == PIN_HIGH)
		{

			GPIO_PORTS[Port] -> ODR |= (GPIO_1BIT_MASK << PinNum);

		}

		else
		{
			GPIO_PORTS[Port] -> ODR &=  ~(GPIO_1BIT_MASK << PinNum);
		}
	}

	else
	{
		Local_u8ErrorState = InvalidPinOrPortNum;
	}


	return Local_u8ErrorState;
}





/****************************************************************************************************
 * 	Decription: This Function is used to toggle a GPIO pin.
 * 	Parameters: - port_t Port: is an enum holding the port.
 *				- Pin_t PinNum: is an enum holding the pin number.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 *				   - Pin is Configed usin GPIO_u8PinInit as OUTPUT
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Pin is set to a value
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
GPIOErrorStates_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum)
{
	uint8_t Local_u8ErrorState = Exit_Ok;


	if((Port <= PORTG) && (PinNum <= PIN15))
	{


		GPIO_PORTS[Port] -> ODR ^= (GPIO_1BIT_MASK << PinNum);

	}


	else
	{
		Local_u8ErrorState = InvalidPinOrPortNum;
	}


	return Local_u8ErrorState;
}





/****************************************************************************************************
 * 	Decription: This Function is used to set a GPIO pin.
 * 	Parameters: - port_t Port: is an enum holding the port.
 *				- Pin_t PinNum: is an enum holding the pin number.
 *				- PinVal_t* PinVal: is a ptr to an enum to recive the value by reference.
 * 	Returns: uint8_t errorState
 * 	Preconditions: - RCC is initialized and working
 * 				   - Clk enabled for GPIO Peripheral
 *				   - Pin is Configed usin GPIO_u8PinInit as INPUT
 * 	Side effects: No side effects
 * 	Post Conditions: a GPIO Pin is read
 * 	Synch/Asynch: Synch.
 * 	Reentrant/NonReenterant: Re
 ***************************************************************************************************/
GPIOErrorStates_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t* PinVal)
{

	GPIOErrorStates_t Local_u8Errorstates = Exit_Ok;


	if((Port <= PORTG) && (PinNum <= PIN15))
	{
		*PinVal = (GPIO_1BIT_MASK & ((GPIO_PORTS[Port] -> IDR) >> PinNum));
	}

	else
	{
		Local_u8Errorstates = InvalidPinOrPortNum;
	}


	return Local_u8Errorstates;

}
