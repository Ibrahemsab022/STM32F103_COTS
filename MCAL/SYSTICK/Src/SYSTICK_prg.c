
#include <stdint.h>
#include "Stm32F103C8T6.h"
#include "SYSTICK_prv.h"
#include "SYSTICK_interface.h"

/*****************************************
@fn 	SYSTICK_DelayMs
@brief	 Timer in ms
@param[in] Copy_u32Duration: required delay duration in ms
@retval void
 *****************************************/
void SYSTICK_DelayMs(uint32_t Copy_u32Duration)
{

    uint32_t tick_per_ms = (SYSTEM_FREQUANCY / DENOMINATOR_MS); /* Ticks per millisecond*/
    uint32_t total_ticks = Copy_u32Duration * tick_per_ms;
    uint32_t reload_value = 0;

    /* Configure clock source */
    SYSTICK-> CSR |= (1 << CLKSOURCE);

    while (total_ticks > 0)
    {
        if (total_ticks > MAX_TICKS_COUNT) /* SysTick maximum reload value */
        {
            reload_value = MAX_TICKS_COUNT; /*Use max reload value for large delays*/
        }
        else
        {
            reload_value = total_ticks; /*Use remaining ticks*/
        }

        /* Set the reload value */
        SYSTICK-> RVR = reload_value - 1;

        /* Reset the current counter value */
        SYSTICK-> CVR = INITIAL_RELOAD_VAL;

        /* Enable SysTick */
        SYSTICK-> CSR |= (1 << ENABLE);

        /* Busy wait for the count flag */
        while (!((SYSTICK-> CSR >> COUNTFLAG) & ONE_BIT_MASK))
        {
            /* Do nothing */
        }

        /* Disable SysTick after each interval */
        SYSTICK-> CSR &= ~(1 << ENABLE);

        /* Subtract handled ticks from the total */
        total_ticks -= reload_value;
    }
}





/*****************************************
@fn 	SYSTICK_DelayUs
@brief	 Timer in us
@param[in] Copy_u32Duration: required delay duration in us
@retval void
 *****************************************/
void SYSTICK_DelayUs(uint32_t Copy_u32Duration)
{

    uint32_t tick_per_us = (SYSTEM_FREQUANCY / DENOMINATOR_US); /* Ticks per millisecond*/
    uint32_t total_ticks = Copy_u32Duration * tick_per_us;
    uint32_t reload_value = 0;

    /* Configure clock source */
    SYSTICK-> CSR |= (1 << CLKSOURCE);

    while (total_ticks > 0)
    {
        if (total_ticks > MAX_TICKS_COUNT) /* SysTick maximum reload value */
        {
            reload_value = MAX_TICKS_COUNT; /*Use max reload value for large delays*/
        }
        else
        {
            reload_value = total_ticks; /*Use remaining ticks*/
        }

        /* Set the reload value */
        SYSTICK-> RVR = reload_value - 1;

        /* Reset the current counter value */
        SYSTICK-> CVR = INITIAL_RELOAD_VAL;

        /* Enable SysTick */
        SYSTICK-> CSR |= (1 << ENABLE);

        /* Busy wait for the count flag */
        while (!((SYSTICK-> CSR >> COUNTFLAG) & ONE_BIT_MASK))
        {
            /* Do nothing */
        }

        /* Disable SysTick after each interval */
        SYSTICK-> CSR &= ~(1 << ENABLE);

        /* Subtract handled ticks from the total */
        total_ticks -= reload_value;
    }
}
