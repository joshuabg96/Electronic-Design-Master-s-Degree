//#include "mbed.h"
#include "mbedtls/sha256.h" /* SHA-256 only */
#include "mbedtls/md.h"     /* generic interface */
#include "board.h"
#include "mbedtls/chacha20.h"
#include "mbedtls/ecdsa.h"

#if DEBUG_LEVEL > 0
#include "mbedtls/debug.h"
#endif

#include "mbedtls/platform.h"

#include <string.h>

static void print_hex(const char *title, const unsigned char buf[], size_t len)
{
    mbedtls_printf("%s: ", title);

    for (size_t i = 0; i < len; i++)
        mbedtls_printf("%02x", buf[i]);

    mbedtls_printf("\r\n");
}

static int myrand( void *rng_state, unsigned char *output, size_t len )
{
    size_t use_len;
    int rnd;

    if( rng_state != NULL )
        rng_state  = NULL;

    while( len > 0 )
    {
        use_len = len;
        if( use_len > sizeof(int) )
            use_len = sizeof(int);

        rnd = rand();
        memcpy( output, &rnd, use_len );
        output += use_len;
        len -= use_len;
    }

    return( 0 );
}

void Sha256();
void Chacha20();
void Signature();

void Sha256()
{
	static const char hello_str[] = "Hello, world!";
	static const unsigned char *hello_buffer = (const unsigned char *) hello_str;
	static const size_t hello_len = sizeof(hello_str);

    unsigned char output[32]; 														// The HASH is stored in an array of 32 places

    mbedtls_sha256(hello_buffer, hello_len, output, 0);								// Send the message to be hashed and the array where the hash will be stored

    mbedtls_printf("\r\nMessage: %s\n\r", hello_str);								// Print the message
    print_hex("Sha256 of the message", output, sizeof (output));					// Print the HASH
}

void Chacha20()
{
	const unsigned char nonce[12] = "00000000000";
	const unsigned char key[32] = "eYtejsk8ksh9soP8JAth45hslhG5E7u"; //256 bits
	uint32_t counter = 0;
	const unsigned char inputData[50] = "Hello, world!";
	unsigned char outputData[50];

	mbedtls_chacha20_context chacha20;


	//Chacha20

	mbedtls_chacha20_init(&chacha20);												// Chacha20 structure is initialized

	mbedtls_chacha20_setkey(&chacha20, key);										// Add the key to the structure

	mbedtls_chacha20_starts(&chacha20, nonce, counter);								// Add the initialization vector and the counter

	mbedtls_chacha20_update(&chacha20, sizeof(inputData),inputData,outputData);		// All the rounds are done and the result is stored in OutputData

	mbedtls_chacha20_free(&chacha20);												// The structure is cleaned


	PRINTF( "\r\nPlain Text: ");
	for(int i = 0; i < sizeof(inputData); i++)
	{
		PRINTF( "%c", inputData[i]);
	}

	PRINTF( "\r\nCipher Text: ");
	for(int i = 0; i < sizeof(outputData); i++)
	{
		PRINTF( "%x", outputData[i]);
	}
}

void Signature()
{

	unsigned char Message[] = "Hello World!";
	mbedtls_ecdsa_context ecdsa;
	const mbedtls_ecp_curve_info *curve_info;
	size_t sig_len;
	unsigned char firma[200];
	const mbedtls_ecp_curve_info *curve_list = mbedtls_ecp_curve_list( );

	memset( firma, 0x00, sizeof( firma ) );																					// It is filled with zeros where the signature is to be stored.

	curve_info = curve_list;

	mbedtls_ecdsa_init( &ecdsa );																							// The structure is initialized

	mbedtls_ecdsa_genkey( &ecdsa, curve_info->grp_id, myrand, NULL );														// The Keys are generated

	mbedtls_ecdsa_write_signature( &ecdsa, MBEDTLS_MD_SHA256, Message, curve_info->bit_size, firma, &sig_len, myrand, NULL );	// The Signature is stored

	PRINTF( "\r\nMessage: ");																								// Print message
	for(int i = 0; i < sizeof(Message); i++)
	{
		PRINTF( "%c", Message[i]);
	}

	print_hex("\r\nSignature: ",firma, sig_len);																			// Print Signature

	mbedtls_ecdsa_free( &ecdsa );																							// structure free
}

int main() {
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();


    Sha256();
    Chacha20();
    Signature();

}
