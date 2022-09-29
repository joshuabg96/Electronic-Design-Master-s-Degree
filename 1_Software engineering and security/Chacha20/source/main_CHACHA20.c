/*
 *  Benchmark demonstration program
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 *  Copyright 2017, 2021 NXP. Not a Contribution
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/



#include "mbedtls/version.h"
#include <stdio.h>
#include "fsl_debug_console.h"
#include "fsl_clock.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"


#include "mbedtls/platform.h"

#include <string.h>
#include <stdlib.h>

#include "mbedtls/timing.h"

#include "mbedtls/error.h"

#include "fsl_device_registers.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/


#include <stdio.h>
#include "fsl_debug_console.h"
#include "fsl_clock.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "mbedtls/platform.h"
#include <string.h>
#include <stdlib.h>
#include "mbedtls/timing.h"
#include "mbedtls/error.h"

#include "mbedtls/chacha20.h"

int main( int argc, char *argv[] )
{
    const unsigned char nonce[12] = "00000000000";
	const unsigned char key[32] = "eYtejsk8ksh9soP8JAth45hslhG5E7u"; //256 bits
	uint32_t counter = 0;
	const unsigned char inputData[50] = "Este es un texto plano";
	unsigned char outputData[50];

	mbedtls_chacha20_context chacha20;

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();


    //Chacha20

	mbedtls_chacha20_init(&chacha20);												// Se inicializa la estructura específica del chacha

	mbedtls_chacha20_setkey(&chacha20, key);										// Se llena la estructura con la llave anteriormente inicializada

	mbedtls_chacha20_starts(&chacha20, nonce, counter);								// Se Agrega el vector de inicialización y el contador

	mbedtls_chacha20_update(&chacha20, sizeof(inputData),inputData,outputData);		// Se realizan todas las corridas y se almacenan en el outputData

	mbedtls_chacha20_free(&chacha20);												// Se limpia la estructura


    PRINTF( "\r\nTexto plano: ");
    for(int i = 0; i < sizeof(inputData); i++)
    {
    	PRINTF( "%c", inputData[i]);
    }

    PRINTF( "\r\nTexto Cifrado: ");
	for(int i = 0; i < sizeof(outputData); i++)
	{
		PRINTF( "%x ", outputData[i]);
	}
	PRINTF( "\r\n\n");

}

