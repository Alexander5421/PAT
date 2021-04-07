/************************************************************************
Lab 9 Nios Software

Dong Kai Wang, Fall 2017
Christine Chen, Fall 2013

For use with ECE 385 Experiment 9
University of Illinois ECE Department
************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "aes.h"

// Pointer to base address of AES module, make sure it matches Qsys
//volatile unsigned int * AES_PTR = (unsigned int *) 0x00000100;

// Execution mode: 0 for testing, 1 for benchmarking
int run_mode = 0;
unsigned long T (unsigned long w,int j);
void decrypt(unsigned int * msg_enc, unsigned int * msg_dec, unsigned int * key);
void encrypt(unsigned char * msg_ascii, unsigned char * key_ascii, unsigned int * msg_enc, unsigned int * key);
void AddRoundKey(unsigned char* state, unsigned long * w,int round);
void shiftrows(unsigned char* state);
void MixColumns(unsigned char* state);
void subbytes (unsigned char* state);
void subword(unsigned long* word);
void subbyte(unsigned char* byte);
void rotword(unsigned long* word);
unsigned long T (unsigned long w,int j);
/** charToHex
 *  Convert a single character to the 4-bit value it represents.
 *
 *  Input: a character c (e.g. 'A')
 *  Output: converted 4-bit value (e.g. 0xA)
 */
char charToHex(char c)
{
	char hex = c;

	if (hex >= '0' && hex <= '9')
		hex -= '0';
	else if (hex >= 'A' && hex <= 'F')
	{
		hex -= 'A';
		hex += 10;
	}
	else if (hex >= 'a' && hex <= 'f')
	{
		hex -= 'a';
		hex += 10;
	}
	return hex;
}

/** charsToHex
 *  Convert two characters to byte value it represents.
 *  Inputs must be 0-9, A-F, or a-f.
 *
 *  Input: two characters c1 and c2 (e.g. 'A' and '7')
 *  Output: converted byte value (e.g. 0xA7)
 */
char charsToHex(char c1, char c2)
{
	char hex1 = charToHex(c1);
	char hex2 = charToHex(c2);
	return (hex1 << 4) + hex2;
}


/** keyExpansion
 *  Perform keyExpansion
 *
 *  Input: key - pointer to char array that contains the 128-bit input key
 *  output w   - Pointer to 44x 32-bit round key array

 */

 void keyExpansion(unsigned char* key, unsigned long* w){
	 unsigned long temp;
	 int i=0;

	// add key into w[0~3]
	 for (i=0;i<4;i++){
		 w[i]=(unsigned long)((key[0+i]<<24)+(key[4+i]<<16)+(key[8+i]<<8)+(key[12+i]));
	 }
	 // expansion key to get w[4~43]
	 int j=1;
	 for (i=4;i<44;i++){
		 if ((i%4)==0) { // w[i]=w[i-4]xorT(w[i-1])
			w[i]=w[i-4]^T(w[i-1],j);
		 }else{
			w[i]=w[i-4]^w[i-1];
		 }
	 }
 }
 /** T
 *  Perform function T
 *
 *  Input: w,j
 *  output T(w)

 */
 unsigned long T (unsigned long w,int j){
	 unsigned long temp = w;
	 rotword(&temp);
	 subword(&temp);
	 return (unsigned long)(temp ^ Rcon[j]);

 }
 /** rotword
 *   input a pointer to a 32 bit word [1,2,3,4]
 *   return back a [2,3,4,1]
 */
void rotword(unsigned long* word)
{
	unsigned char temp =  (*word)>>24;
	*word = ((*word)<<24) & 0xFFF0 + temp;
}

/** subbyte
*/
void subbyte(unsigned char* byte)
{
	*byte = aes_sbox[(int)*byte];
}
/** subword
 use mutiple subbyte
*/
void subword(unsigned long* word)
{

	// if there is a bug, may be you need Type Cast :(type)
	unsigned char byte3= *word>> 24;
	unsigned char byte2= *word>> 16;
	unsigned char byte1= *word>>8;
	unsigned char byte0= *word;
	byte3=aes_sbox[byte3];
	byte2=aes_sbox[byte2];
	byte1=aes_sbox[byte1];
	byte0=aes_sbox[byte0];
	*word = (byte3 << 24) | (byte2 << 16) | (byte1 << 8) | (byte0);
}
/**
subbytes
convert the bytes in a 4*4 state into what we want
*/
void subbytes (unsigned char* state){
	for (int i=0 ;i<16;i++){
		state[i] = aes_sbox[(int)state[i]];
	}
}

/**
shift rows
state 4*4 need shift
*/
void shiftrows(unsigned char* state) {
	unsigned char temp[3];
	/* 4x4 Box model
		0 1 2 3
		4 5 6 7
		8 9 a b
		c d e f
	*/
	/* 4x4 Box model
		0 1 2 3
		5 6 7 4
		a b 8 9
		f c d e
	*/
	temp[0] = state[4];
	state[4] = state[5];
	state[5] = state[6];
	state[6] = state[7];
	state[7] = temp[0];

	temp[0] = state[8];
	temp[1] = state[9];
	state[8] = state[10];
	state[9] = state[11];
	state[10] = temp[0];
	state[11] = temp[1];

	temp[0] = state[12];
	temp[1] = state[13];
	temp[2] = state[14];
	state[12] = state[15];
	state[13] = temp[0];
	state[14] = temp[1];
	state[15] = temp[2];
}

/** mixcolumns
*  mix columns
*/

void MixColumns(unsigned char* state) {
	unsigned char	a[4], b[4];

	int i = 0;
	for(i=0; i<4; i++) {
		a[0]=state[0+i];
		a[1]=state[4+i];
		a[2]=state[8+i];
		a[3]=state[12+i];
		b[0] = gf_mul[a[0]][0] ^ gf_mul[a[1]][1] ^ a[2] ^ a[3];
		b[1] = a[0] ^ gf_mul[a[1]][0] ^ gf_mul[a[2]][1] ^ a[3];
		b[2] = a[0]^ a[1] ^ gf_mul[a[2]][0] ^ gf_mul[a[3]][1];
		b[3] = gf_mul[a[0]][1] ^ a[1] ^ a[2] ^ gf_mul[a[3]][0];

        state[0+i] = b[0];
        state[4+i] = b[1] ;
        state[8+i] = b[2] ;
        state[12+i] = b[3] ;

	}
}
void AddRoundKey(unsigned char* state, unsigned long * w,int round){

	int i,j;
	unsigned char* byte[4];

	for (i=0; i<4; i++){ //each colomns
		byte[3]= w[i+4*round]>> 24;
		byte[2]= w[i+4*round]>> 16;
		byte[1]= w[i+4*round]>>8;
		byte[0]= w[i+4*round];
	}
		for (j=0; j<4; j++){ //each rows
			//state[4*j+i]=state[4*j+i]^byte[3-j];
			state[4*j+i] ^= (unsigned char)(byte[3-j]);
	}

}

/** encrypt
 *  Perform AES encryption in software.
 *
 *  Input: msg_ascii - Pointer to 32x 8-bit char array that contains the input message in ASCII format
 *         key_ascii - Pointer to 32x 8-bit char array that contains the input key in ASCII format
 *  Output:  msg_enc - Pointer to 4x 32-bit int array that contains the encrypted message
 *               key - Pointer to 4x 32-bit int array that contains the input key
 */
void encrypt(unsigned char * msg_ascii, unsigned char * key_ascii, unsigned int * msg_enc, unsigned int * key)
{
	int i,round;
	unsigned char state[16];
	unsigned char keyInit[16];
	unsigned long w[44];

	// transform raw input into a major coloumn matrix
	for (i=0;i<16;i++){
		state[(i%4)*4 + i/4] = charsToHex(msg_ascii[2*i],msg_ascii[2*i+1]);
		keyInit[(i%4)*4 + i/4] = charsToHex(key_ascii[2*i],key_ascii[2*i+1]);
	}



	keyExpansion(keyInit,w);

// do it first time.
	AddRoundKey(state,w,0);

	for (round=1; round<10;round++){
		subbytes(state);
		shiftrows(state);
		MixColumns(state);
		AddRoundKey(state,w,round);
	}

	// last round
	subbytes(state);
	shiftrows(state);
	AddRoundKey(state,w,10);

	//  matrix transformed into array. each colmun is one element in that array.

	for (i=0; i<4; i++){

		key [i] =keyInit[i]<<24 + keyInit[i+4]<<16 + keyInit[i+8]<<8 + keyInit[i+12];
		msg_enc[i]= state[i]<<24 + state[i+4]<<16 + state[i+8]<<8 + state[i+12];

	}
}
/** decrypt
 *  Perform AES decryption in hardware.
 *
 *  Input:  msg_enc - Pointer to 4x 32-bit int array that contains the encrypted message
 *              key - Pointer to 4x 32-bit int array that contains the input key
 *  Output: msg_dec - Pointer to 4x 32-bit int array that contains the decrypted message
 */
void decrypt(unsigned int * msg_enc, unsigned int * msg_dec, unsigned int * key)
{
	// Implement this function
}

/** main
 *  Allows the user to enter the message, key, and select execution mode
 *
 */
int main()
{
	// Input Message and Key as 32x 8-bit ASCII Characters ([33] is for NULL terminator)
	unsigned char msg_ascii[33];
	unsigned char key_ascii[33];
	// Key, Encrypted Message, and Decrypted Message in 4x 32-bit Format to facilitate Read/Write to Hardware
	unsigned int key[4];
	unsigned int msg_enc[4];
	unsigned int msg_dec[4];

	printf("Select execution mode: 0 for testing, 1 for benchmarking: ");
	scanf("%d", &run_mode);

	if (run_mode == 0) {
		// Continuously Perform Encryption and Decryption
		while (1) {
			int i = 0;
			printf("\nEnter Message:\n");
			scanf("%s", msg_ascii);
			printf("\n");
			printf("\nEnter Key:\n");
			scanf("%s", key_ascii);
			printf("\n");
			encrypt(msg_ascii, key_ascii, msg_enc, key);
			printf("\nEncrpted message is: \n");
			for(i = 0; i < 4; i++){
				printf("%08x", msg_enc[i]);
			}
			printf("\n");
			// decrypt(msg_enc, msg_dec, key);
			// printf("\nDecrypted message is: \n");
			// for(i = 0; i < 4; i++){
			// 	printf("%08x", msg_dec[i]);
			// }
			printf("\n");
		}
	}
	else {
		// Run the Benchmark
		int i = 0;
		int size_KB = 2;
		// Choose a random Plaintext and Key
		for (i = 0; i < 32; i++) {
			msg_ascii[i] = 'a';
			key_ascii[i] = 'b';
		}
		// Run Encryption
		clock_t begin = clock();
		for (i = 0; i < size_KB * 64; i++)
			encrypt(msg_ascii, key_ascii, msg_enc, key);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		double speed = size_KB / time_spent;
		printf("Software Encryption Speed: %f KB/s \n", speed);
		// Run Decryption
		begin = clock();
		for (i = 0; i < size_KB * 64; i++)
			decrypt(msg_enc, msg_dec, key);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		speed = size_KB / time_spent;
		printf("Hardware Encryption Speed: %f KB/s \n", speed);
	}
	return 0;
}
