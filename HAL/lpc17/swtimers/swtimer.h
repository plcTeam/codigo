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

#ifndef _SWTIMER_H_
#define _SWTIMER_H_

/*-------------------------------------------------------------------------------------
 \brief    Estos define describen las configuraciones de mi puerto como entradas y salidas
 \warning  Configura puerto como salida o entrada
---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
 \brief    Inicializa el systick timer para que genere la base de tiempo.
 \param    u32BaseTime.- Es la base de tiempo de nuestro Tick en ms.
 \return   None
 \warning  Esta funcion sobre escribe el valor anterior
---------------------------------------------------------------------------------------*/
extern void Timers_Init(unsigned int u32BaseTime);

/*-------------------------------------------------------------------------------------
 \brief    Inicializa el systick timer para que genere la base de tiempo del timer especificado.
 \param    u32Timer.- Timer a configurar.
 \param    u32BaseTime.- Es la base de tiempo de nuestro Tick en ms.
 \return   None
 \warning  Esta funcion sobre escribe el valor anterior
---------------------------------------------------------------------------------------*/
extern void Timers_SetTimer(unsigned int u32Timer, unsigned int u32Time);

/*-------------------------------------------------------------------------------------
 \brief    Inicializa el systick timer para que genere la base de tiempo del timer especificado.
 \param    u32Timer.- Timer a configurar.
 \param    u32BaseTime.- Es la base de tiempo de nuestro Tick en ms.
 \return   None
 \warning  Esta funcion sobre escribe el valor anterior
---------------------------------------------------------------------------------------*/
extern unsigned int  Timers_u32GetTimer(unsigned int u32Timer);




#endif
