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

#include "uart.h"
#include <LPC17xx.h>
#include <string.h>

//Putos !!!!!!!!!!!!!!

typedef struct 
{
	uint32_t gu32Counter;
	uint32_t gbTxFlag;
	uint8_t *gpu8Msg;
	uint8_t gau8Data[100];
}_UART;

static _UART Uart[4];

void Uart_Init(LPC_UART_TypeDef *pxUart, const unsigned int u32BaudRate)
{
	unsigned int clk=SystemCoreClock/4;
	unsigned int Fdiv;
	
	if(pxUart==LPC_UART3){
	/*pin sel*/
		LPC_PINCON->PINSEL0 |= ((2<<0)|(2<<2));
	}
	else if(pxUart==LPC_UART2){
	/*pin sel*/
		LPC_PINCON->PINSEL0 |= ((2<<0)|(2<<2));
	}
	else if(pxUart==LPC_UART0){
	/*pin sel*/
		LPC_PINCON->PINSEL0 |= ((2<<0)|(2<<2));
	}
	
	/*turn on power*/
	LPC_SC->PCONP |= (1<<25);
	pxUart->LCR= 0x83;
	Fdiv=(clk/16)/u32BaudRate;
	pxUart->DLM=Fdiv/256;
	pxUart->DLL=Fdiv%256;
	pxUart->LCR=0x03;
	
	pxUart->IER|=(1<<0); //interrupcion por Rx
	
	if(pxUart==LPC_UART3){
		NVIC_EnableIRQ(UART3_IRQn);
	}
	
	else if(pxUart==LPC_UART2){
		NVIC_EnableIRQ(UART3_IRQn);
	}
	
	else if(pxUart==LPC_UART0){
		NVIC_EnableIRQ(UART3_IRQn);
	}
	
}

void Uart_Char(LPC_UART_TypeDef *pxUart, unsigned char u8Char)
{
	pxUart->THR=u8Char;
	while((pxUart->LSR & (1<<5))==0);
}


void Uart_SendString(LPC_UART_TypeDef *pxUart, unsigned char *strString)
{
	while(*strString != '\0')
	{
		Uart_Char(pxUart, *strString);
		strString++;
	}
}


void Uart_SendMsg(LPC_UART_TypeDef *pxUart, unsigned char *pu8Data, unsigned int u32Lenght)
{
	if(pxUart == LPC_UART0)
	{
		Uart[0].gpu8Msg = &Uart[0].gau8Data[0];
		Uart[0].gu32Counter=u32Lenght;
		memcpy((void*)&Uart[0].gau8Data[0], (const void*)pu8Data, u32Lenght);
		Uart[0].gbTxFlag=1;
	}

		if(pxUart == LPC_UART2)
	{
		Uart[2].gpu8Msg = &Uart[2].gau8Data[2];
		Uart[2].gu32Counter=u32Lenght;
		memcpy((void*)&Uart[2].gau8Data[2], (const void*)pu8Data, u32Lenght);
		Uart[2].gbTxFlag=1;
	}
	
	if(pxUart == LPC_UART3)
	{
		Uart[3].gpu8Msg = &Uart[3].gau8Data[3];
		Uart[3].gu32Counter=u32Lenght;
		memcpy((void*)&Uart[3].gau8Data[3], (const void*)pu8Data, u32Lenght);
		Uart[3].gbTxFlag=1;
	}
	
	pxUart->THR=*pu8Data;
	pxUart->IER|=(1<<1);/*habilito int por tx*/
}

unsigned int Uart_bTxBusy(LPC_UART_TypeDef *pxUart)
{
	if(pxUart==LPC_UART0)
	{
		return Uart[0].gbTxFlag;
	}
	else if(pxUart==LPC_UART2)
	{
		return Uart[2].gbTxFlag;
	}
	else if(pxUart==LPC_UART3)
	{
		return Uart[3].gbTxFlag;
	}
}

void UART3_IRQHandler()
{
	if(LPC_UART3->IIR & 0x02)  /*Interrupcion por Tx*/
	{
		Uart[3].gu32Counter--;
		Uart[3].gpu8Msg++;
		if(Uart[3].gu32Counter==0)
		{
			Uart[3].gbTxFlag=0;
			LPC_UART3->IER &=~(1<<1);/*deshabilito int por tx*/
		}
		else
		{
			LPC_UART3->THR=*Uart[3].gpu8Msg;
		}
	}
	
	if(LPC_UART3->IIR & 0x04)  /*Interrupcion por Rx*/
	{
		Uart_CallbackRx3(LPC_UART3->RBR);
		
	}	
}

void UART0_IRQHandler()
{
	if(LPC_UART0->IIR & 0x02)  /*Interrupcion por Tx*/
	{
		Uart[0].gu32Counter--;
		Uart[0].gpu8Msg++;
		if(Uart[0].gu32Counter==0)
		{
			Uart[0].gbTxFlag=0;
			LPC_UART0->IER &=~(1<<1);/*deshabilito int por tx*/
		}
		else
		{
			LPC_UART0->THR=*Uart[0].gpu8Msg;
		}
	}
	
	if(LPC_UART0->IIR & 0x04)  /*Interrupcion por Rx*/
	{
		Uart_CallbackRx0(LPC_UART0->RBR);
		
	}
}

void UART2_IRQHandler()
{
	if(LPC_UART2->IIR & 0x02)  /*Interrupcion por Tx*/
	{
		Uart[2].gu32Counter--;
		Uart[2].gpu8Msg++;
		if(Uart[2].gu32Counter==0)
		{
			Uart[2].gbTxFlag=0;
			LPC_UART2->IER &=~(1<<1);/*deshabilito int por tx*/
		}
		else
		{
			LPC_UART2->THR=*Uart[2].gpu8Msg;
		}
	}
	
	if(LPC_UART2->IIR & 0x04)  /*Interrupcion por Rx*/
	{
		Uart_CallbackRx2(LPC_UART2->RBR);
		
	}	
}