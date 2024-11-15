/********************************************************************************************************
 * file: SysTick_Prv.h
 * brief: This file contains prv components and definitions for the SysTick driver
 * author: Ibrahim Saber
 * version: 1.0
 * date: 24-10-2024
 ********************************************************************************************************/
#ifndef	SYSTICK_PRV_H_
#define	SYSTICK_PRV_H_

#define SYSTEM_FREQUANCY	8000000UL

#define MAX_TICKS_COUNT 	16777215UL
#define DENOMINATOR_MS		1000u
#define DENOMINATOR_US		1000000UL


#define READY_FLAG_MASK 		1
#define INITIAL_RELOAD_VAL		0
#define ONE_BIT_MASK			1

#endif
