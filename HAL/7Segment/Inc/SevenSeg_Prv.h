/***************************************************************************************************
 * @file  	SevenSeg_Prv.h
 * @brief 	This file contains the private definitions and components of the 7-Segment display Driver
 * @author 	Ibrahim Saber
 * @version 1.0
 * @date 	26 - 1 -2025
 ***************************************************************************************************/
#ifndef SEVENSEG_PRV_H
#define SEVENSEG_PRV_H

#define NULL ((void *)0)

#define GET_BIT(BYTE, BIT_NUM)		(1&(BYTE >> BIT_NUM))


uint16_t BinaryCodedDecimal[10] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11110110};




#endif
