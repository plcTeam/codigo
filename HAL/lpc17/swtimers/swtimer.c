/*-------------------------------------------------------------------------------------
 Este codigo esta protegido por las normas internacionales de pirateria
 y no puede ser copiado sin un mouse y un teclado,
 ATTE CFE (grupo de ingenieria de telecomunicaciones)
 
 \autor   GAL
 \email   elgal@gmail.com
 \fecha   26/11/2013
 \version 0.0
 \target  LPC17xx
 \brief   Este driver permite manejar de manera mas flexible y amigable
				  el timer interno del procesadorl de la familia de microcontroladores BXP LPC17xx.
				  Solo estan las funciones que permiten las operaciones basicas.
---------------------------------------------------------------------------------------*/

#include "swtimer.h"
#include <LPC17xx.h>

#define TIMERS_N_CHANNELS      10
#define CLEAR_FLAG()   (SysTick->CTRL &= ~(1<<16)) //limpiar bandera de interrupcion
#define ENABLE_MODULE() (SysTick->CTRL |= 7) //Habilitamos el timer  interrupciones y fuente de reloj principal
#define LOAD_BASE_TIMER(base_time)  (SysTick->LOAD = (((SystemCoreClock/1000)*(base_time))-1))

static uint32_t gau32Timers[TIMERS_N_CHANNELS];

//void SysTick_Handler(void);

void Timers_Init(unsigned int u32BaseTime)
{
	ENABLE_MODULE();
	LOAD_BASE_TIMER(u32BaseTime);
}


void Timers_SetTimer(unsigned int u32Timer, unsigned int u32Time)
{
	gau32Timers[u32Timer]=u32Time;
}


unsigned int  Timers_u32GetTimer(unsigned int u32Timer)
{
	return gau32Timers[u32Timer];
}


void SysTick_Handler(void)
{
	volatile uint32_t u32Timers= TIMERS_N_CHANNELS;
	
	CLEAR_FLAG();
	while(u32Timers)
	{
		u32Timers--;
		if(gau32Timers[u32Timers])
		{
			gau32Timers[u32Timers]--;
		}
	}
}

