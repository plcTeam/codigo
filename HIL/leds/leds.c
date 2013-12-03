/*-------------------------------------------------------------------------------------
 Este codigo esta protegido por las normas internacionales de pirateria
 y no puede ser copiado sin un mouse y un teclado,
 ATTE CFE (grupo de ingenieria de telecomunicaciones)
 
 \autor   GAL
 \email   elgal@gmail.com
 \fecha   27/11/2013
 \version 0.0
 \target  Generico (uC 32 bits)
 \brief   Este driver permite manejar leds conectados a los pines de mi micro
					de manera generica y transparente.
---------------------------------------------------------------------------------------*/
#include "leds.h"
#include "gpios/gpios.h"
#include "config.h"

static unsigned int gau32Ports[]=
{
	#if LEDS_N > 0
		LEDS_0_P,
	#endif
	#if LEDS_N > 1
		LEDS_1_P,
	#endif
	#if LEDS_N > 2
		LEDS_2_P,
	#endif
	#if LEDS_N > 3
		LEDS_3_P,
	#endif
};

static unsigned int gau32Bits[]=
{
	#if LEDS_N > 0
		LEDS_0_B,
	#endif
	#if LEDS_N > 1
		LEDS_1_B,
	#endif
	#if LEDS_N > 2
		LEDS_2_B,
	#endif
	#if LEDS_N > 3
		LEDS_3_B,
	#endif
};

void Leds_Init(void)
{
	unsigned int i=0;
	for(i=0;i<LEDS_N;i++)
	{
		Gpios_ConfigPin((_ePORTS)gau32Ports[i],gau32Bits[i],GPIOS_OUTPUT);
	}
}


void Leds_TurnOn(unsigned int u32Led)
{
		Gpios_writePin((_ePORTS)gau32Ports[u32Led], gau32Bits[u32Led], 1);
}


void Leds_TurnOff(unsigned int u32Led)
{
	Gpios_writePin((_ePORTS)gau32Ports[u32Led], gau32Bits[u32Led], 0);
}

void Leds_Toggle(unsigned int u32Led)
{
	Gpios_TogglePin((_ePORTS)gau32Ports[u32Led], gau32Bits[u32Led]);
}

