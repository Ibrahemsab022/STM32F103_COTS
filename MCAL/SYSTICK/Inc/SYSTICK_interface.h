/********************************************************************************************************
 * file: SysTick_Interface.h
 * brief: This file contains the function prototypes and the interface components for the SysTick driver
 * author: Ibrahim Saber
 * version: 1.0
 * date: 24-10-2024
 ********************************************************************************************************/
#ifndef  SYSTICK_INTERFACE_H_
#define  SYSTICK_INTERFACE_H_

/*@CSR_t*/
typedef enum{
	ENABLE=0,
	TICKINT,
	CLKSOURCE,
	COUNTFLAG=16
}CSR_t;




/*****************************************
@fn 	SYSTICK_DelayMs
@brief	 Timer in ms
@param[in] Copy_u32Duration: required delay duration in ms
@retval void
 *****************************************/
void SYSTICK_DelayMs(uint32_t Copy_u32Duration);



/*****************************************
@fn 	SYSTICK_DelayUs
@brief	 Timer in us
@param[in] Copy_u32Duration: required delay duration in us
@retval void
 *****************************************/
void SYSTICK_DelayUs(uint32_t Copy_u32Duration);



#endif
