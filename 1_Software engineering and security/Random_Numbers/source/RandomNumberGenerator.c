/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "pin_mux.h"				// Inicialización de los pines necesarios de la tarjeta
#include "clock_config.h"			// Configuración del reloj del microcontrolador
#include "board.h"					// Macros y funciones específicas de la tarjeta
#include "fsl_rnga.h"				// Funciones especializadas para el Randoms Generator
#include "fsl_debug_console.h"		// Funciones de Consola, como PRINTF Y SCANF

#include "fsl_device_registers.h"	//Registros básicos
/*******************************************************************************
 * Definitions
 ******************************************************************************/

//#define RNGA_EXAMPLE_RANDOM_NUMBER 10

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Test rnga.
 * @details Generate random numbers and print them to terminal.
 */

int main(void)
{
    uint32_t i;				// Contador para el for
    status_t status;		// Retorna el estatus de la generación de los números
    uint8_t numeros = 0;	// Cantidad de números de 32 bits que queremos generar

    BOARD_InitBootPins();		// Inicialización de los pines de la tarjeta
    BOARD_InitBootClocks();		// Inicialización del reloj del microcontrolador
    BOARD_InitDebugConsole();	// Inicialización de la comunicación con al terminal

    RNGA_Init(RNG);				// Inicialización del reloj dedicado para los números aleatorios

    while (1)
    {
        PRINTF("Cuantos numeros de 32 bits quieres recibir?\r\n");
        SCANF("%i", &numeros);					// Ingresamos el valor y lo guardamos en números

        uint32_t data[numeros];					// Creamos un arreglo llamado "data", con longuitud "numeros"

        status = RNGA_GetRandomData(RNG, data, sizeof(data));		// Se obtiene 32 bits de datos random y/o el estatus de la función
        // En caso de que se haya realizado correctamete la generación los datos se guardarán en el arreglo data.
        if (status == kStatus_Success)								// Se verifica el estatus anteriormente obtenido
        {
        	// "for" para imprimir los números random generados
        	PRINTF("Aqui tienes %i numeros de 32 bits aleatorios = ", numeros);

        	for (i = 0; i < numeros; i++)
            {
                PRINTF("%X ", data[i]);
            }
            PRINTF("\r\n\n");
        }
        else
        {
        	// En caso de que el estatus de la generación de números no haya sido exitosa, imprimimos una leyenda
        	// Que nos diga que ha fallado
            PRINTF("RNGA failed!\r\n");
        }

    }
}
