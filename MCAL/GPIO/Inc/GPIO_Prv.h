/***************************************************************************************************
 * file: GPIO_Prv.h
 * brief: This file contains the private components that supports the dev of the GPIO driver
 * author: Ibrahim Saber
 * version: 1.0
 * date: 16 - 10 -2024
 ***************************************************************************************************/

#ifndef GPIO_PRV_H
#define GPIO_PRV_H


/*Used to divide by to do the correct pin shifting for CRl & CRh  */
#define CR_PIN_SHIFTINTG	8u


/*Number of the GPIO Ports in this family*/
#define GPIO_PORTS_NUM		7u

/*************************** Masks ***************************/
#define GPIO_1BIT_MASK		0b1
#define GPIO_2BIT_MASK		0b11
#define GPIO_4BIT_MASK		0b1111


/*************************** PIN/Register ***************************/
#define GPIO_1BIT_PIN_REG	1u
#define GPIO_2BIT_PIN_REG	2u
#define GPIO_4BIT_PIN_REG	4u



#define NULL ((void *)0)





#endif
