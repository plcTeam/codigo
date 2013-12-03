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
				  los puerto digitales de la familia de microcontroladores BXP LPC17xx.
				  Solo estan las funciones que permiten las operaciones basicas
				  como le ctura, escritura de el puerto completo o pin a pin.
---------------------------------------------------------------------------------------*/
#include "gpios.h"
#include <LPC17xx.h>

static volatile unsigned int *gau32Config[]=
{
	&LPC_GPIO0->FIODIR,
	&LPC_GPIO1->FIODIR,
	&LPC_GPIO2->FIODIR,
	&LPC_GPIO3->FIODIR,
	&LPC_GPIO4->FIODIR
};

static volatile unsigned int *gau32Port[]=
{
	&LPC_GPIO0->FIOPIN,
	&LPC_GPIO1->FIOPIN,
	&LPC_GPIO2->FIOPIN,
	&LPC_GPIO3->FIOPIN,
	&LPC_GPIO4->FIOPIN
};

void Gpios_ConfigPort(_ePORTS ePort, unsigned int u32Value)
{
		*gau32Config[ePort]=u32Value;
}

unsigned int Gpios_u32ReadPort(_ePORTS ePort)
{
	return *gau32Port[ePort];
}

void Gpios_writePort(_ePORTS ePort, unsigned int u32Value)
{
	*gau32Port[ePort]=u32Value;
}

void Gpios_ConfigPin(_ePORTS ePort, unsigned int u32Pin, unsigned int u32Value)
{
	if(u32Value == 1)
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
	return (*gau32Port[ePort]>>u32Pin) & 0x00000001;
}

void Gpios_writePin(_ePORTS ePort, unsigned int u32Pin, unsigned int u32Value)
{
	if(u32Value == 1)
	{
		*gau32Port[ePort] |= (1<<u32Pin);
	}
	else
	{
		*gau32Port[ePort] &= ~(1<<u32Pin);
	}
}


void Gpios_TogglePin(_ePORTS ePort, unsigned int u32Pin)
{
	*gau32Port[ePort]^=(1<<u32Pin);
}
