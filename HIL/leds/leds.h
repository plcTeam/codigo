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


#ifndef _LEDS_H_
#define _LEDS_H_

/*-------------------------------------------------------------------------------------
 \brief    Configuramos el numero de leds a utilizar
 \warning  Estos define se deberan agregar en el archivo config.h de cada aplicacion
---------------------------------------------------------------------------------------*/
//#define LEDS_N		3

/*-------------------------------------------------------------------------------------
 \brief    Coloca aqui los puertos a los que estan conectados tus leds
 \warning  Estos define se deberan agregar en el archivo config.h de cada aplicacion
---------------------------------------------------------------------------------------*/
//#define LEDS_0_P			1
//#define LEDS_0_B			18

//#define LEDS_1_P			1
//#define LEDS_1_B			20

//#define LEDS_2_P			1
//#define LEDS_2_B			21


/*-------------------------------------------------------------------------------------
 \brief    Inicializa los puertos de donde estan conectados los leds
 \param    None
 \return   None
 \warning  Los puertos de los leds se configurar como salidas
---------------------------------------------------------------------------------------*/
extern void Leds_Init(void);

/*-------------------------------------------------------------------------------------
 \brief    Enciende un led en especifico
 \param    u32Led.- Led a encender
 \return   None
 \warning  El puerto donde esta el Led debe configurarse como salida
---------------------------------------------------------------------------------------*/
extern void Leds_TurnOn(unsigned int u32Led);

/*-------------------------------------------------------------------------------------
 \brief    Apaga un led en especifico
 \param    u32Led.- Led a apagar
 \return   None
 \warning  El puerto donde esta el Led debe configurarse como salida
---------------------------------------------------------------------------------------*/
extern void Leds_TurnOff(unsigned int u32Led);

/*-------------------------------------------------------------------------------------
 \brief    Toggle el valor del led
 \param    u32Led.- numero de led
 \return   None
 \warning  El puerto donde esta el Led debe configurarse como salida
---------------------------------------------------------------------------------------*/
extern void Leds_Toggle(unsigned int u32Led);


#endif
