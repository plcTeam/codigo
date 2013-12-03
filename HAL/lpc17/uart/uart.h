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

#ifndef _UART_H_
#define _UART_H_

#include <LPC17xx.h>

extern void Uart_Init(LPC_UART_TypeDef *pxUart, unsigned int u32Baudrate);
extern void Uart_Char(LPC_UART_TypeDef *pxUart, unsigned char u8Char);
extern void Uart_SendString(LPC_UART_TypeDef *pxUart, unsigned char *strString);
extern void Uart_SendMsg(LPC_UART_TypeDef *pxUart, unsigned char *pu8Date, unsigned int u32Lenght);
extern unsigned int Uart_bTxBusy(LPC_UART_TypeDef *pxUart);
extern void Uart_CallbackRx0(unsigned char u8Data);
extern void Uart_CallbackRx2(unsigned char u8Data);
extern void Uart_CallbackRx3(unsigned char u8Data);


#endif
