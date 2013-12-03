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


#ifndef _GPIOS_H_
#define _GPIOS_H_


/*-------------------------------------------------------------------------------------
 \brief    Estos define describen las configuraciones de mi puerto como entradas y salidas
 \warning  Configura puerto como salida o entrada
---------------------------------------------------------------------------------------*/
#define GPIOS_OUTPUT    0
#define GPIOS_INPUT    1


/*-------------------------------------------------------------------------------------
 \brief    Esta enumeracion representa los puertos que puedo usar
 \warning  Son solo valores del 0 al 4 sin signo
---------------------------------------------------------------------------------------*/
typedef enum{
	GPIOS_PORT0=0,   /*port A*/
	GPIOS_PORT1,    /*port B*/
	GPIOS_PORT2,    /*port C*/
	GPIOS_PORT3,    /*port D*/
	GPIOS_PORT4,    /*port E*/
}_ePORTS;

/*-------------------------------------------------------------------------------------
 \brief    configura un puerto completo, a sus pines como salidas o como entradas
 \param    ePort.- el puerto al que se le cargara el valor de configuracion
 \param    u32Value.- el valor de configuracion que tendra el puerto
 \return   None
 \warning  Esta funcion sobre escribe el valor anterior
---------------------------------------------------------------------------------------*/
extern void Gpios_ConfigPort(_ePORTS ePort, unsigned int u32Value);

/*-------------------------------------------------------------------------------------
 \brief    Regresa el valor contenido en los pines configurados como entradas
 \param    ePort.- el puerto al que se le cargara el valor de configuracion
 \return   El valor actual presente en el puerto completo
 \warning  Esta funcion solo opera aquellos pines como salidas
---------------------------------------------------------------------------------------*/
extern unsigned int Gpios_u32ReadPort(_ePORTS ePort);

/*-------------------------------------------------------------------------------------
 \brief    Escribe en el puerto seleccionado el valor ingresado
 \param    ePort.- el puerto al que se le cargara el valor
 \param    u32Value.- el valor a cargar en el puerto
 \return   None
 \warning  Esta funcion solo opera aquellos pines como salidas
---------------------------------------------------------------------------------------*/
extern void Gpios_writePort(_ePORTS ePort, unsigned int u32Value);

/*-------------------------------------------------------------------------------------
 \brief    configura un pin de un puerto como salidas o como entradas
 \param    ePort.- el puerto al que se le cargara el valor de configuracion
 \param    u32Value.- el valor de configuracion del puerto que pertenece el pin a configurar
 \param    u32Pin.- el valor de configuracion que tendra el pin
 \return   None
 \warning  Esta funcion sobre escribe el valor anterior
---------------------------------------------------------------------------------------*/
extern void Gpios_ConfigPin(_ePORTS ePort, unsigned int u32Pin, unsigned int u32Value);

/*-------------------------------------------------------------------------------------
 \brief    Lee el pin del puerto descritos
 \param    ePort.- el puerto del pin a leer
 \param    u32Pin.- el pin a leer
 \return   El valor del pin leido
 \warning  Esta funcion lee el valor del pin tratado como entrada
---------------------------------------------------------------------------------------*/
extern unsigned int Gpios_bReadPin(_ePORTS ePort, unsigned int u32Pin);

/*-------------------------------------------------------------------------------------
 \brief    Escribe en el puerto y pin seleccionado el valor ingresado
 \param    ePort.- el puerto del pin al que se le cargara el valor
 \param    u32Value.- el valor a cargar en el pin
 \param    u32Pin.- pin que sera escrito
 \return   None
 \warning  Esta funcion solo opera aquellos pines como salidas
---------------------------------------------------------------------------------------*/
extern void Gpios_writePin(_ePORTS ePort, unsigned int u32Pin, unsigned int u32Value);

/*-------------------------------------------------------------------------------------
 \brief    Escribe en el puerto y pin seleccionado el valor ingresado y togglea el valor
 \param    ePort.- el puerto del pin al que se le cargara el valor
 \param    u32Pin.- pin que sera escrito
 \return   None
 \warning  Esta funcion solo opera aquellos pines como salidas
---------------------------------------------------------------------------------------*/
extern void Gpios_TogglePin(_ePORTS ePort, unsigned int u32Pin);


#endif
