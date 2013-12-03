/*-------------------------------------------------------------------------------------
 Este codigo esta protegido por las normas internacionales de pirateria
 y no puede ser copiado sin un mouse y un teclado,
 ATTE CFE (grupo de ingenieria de telecomunicaciones)
 
 \autor   GAL
 \email   elgal@gmail.com
 \fecha   27/11/2013
 \version 0.0
 \target  pic32mx
 \brief   Este driver permite manejar de manera mas flexible y amigable
				  los puerto digitales de la familia de microcontroladores PIC32MXxx.
				  Solo estan las funciones que permiten las operaciones basicas
				  como le ctura, escritura de el puerto completo o pin a pin.
---------------------------------------------------------------------------------------*/
#include "gpios.h"
#include <p32xxxx.h>

static volatile unsigned int *gau32Config[]=
{
	&TRISA,
        &TRISB,
        &TRISC,
        &TRISD,
        &TRISE
};

static volatile unsigned int *gau32Input[]=
{
	&PORTA,
        &PORTB,
        &PORTC,
        &PORTD,
        &PORTE
};

static volatile unsigned int *gau32Output[]=
{
	&LATA,
        &LATB,
        &LATC,
        &LATD,
        &LATE
};

void Gpios_ConfigPort(_ePORTS ePort, unsigned int u32Value)
{
		*gau32Config[ePort]=u32Value;
}

unsigned int Gpios_u32ReadPort(_ePORTS ePort)
{
	return *gau32Input[ePort];
}

void Gpios_writePort(_ePORTS ePort, unsigned int u32Value)
{
	*gau32Output[ePort]=u32Value;
}

void Gpios_ConfigPin(_ePORTS ePort, unsigned int u32Pin, unsigned int u32Value)
{
	if(u32Value == 0)
	{
		*gau32Config[ePort] |= (1<<u32Pin);
	}
	else
	{
		*gau32Config[ePort] &= ~(1<<u32Pin);
	}
}

unsigned int Gpios_bReadPin(_ePORTS ePort, unsigned int u32Pin)
{
	return (*gau32Input[ePort]>>u32Pin) & 0x00000001;
}

void Gpios_writePin(_ePORTS ePort, unsigned int u32Pin, unsigned int u32Value)
{
	if(u32Value == 1)
	{
		*gau32Output[ePort] |= (1<<u32Pin);
	}
	else
	{
		*gau32Output[ePort] &= ~(1<<u32Pin);
	}
}


extern void Gpios_TogglePin(_ePORTS ePort, unsigned int u32Pin)
{
	*gau32Output[ePort]^=(1<<u32Pin);
}
