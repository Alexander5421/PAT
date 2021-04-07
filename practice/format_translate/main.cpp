#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

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
unsigned char charsToHex(char c1, char c2)
{
	char hex1 = charToHex(c1);
	char hex2 = charToHex(c2);
	char retval = (hex1 << 4) + hex2;
	return retval;
}

int main(int argc, char const *argv[])
{
    unsigned int key[4];
	unsigned int msg_enc[4];
	unsigned int msg_dec[4];


    char* msg_ascii="daec3055df058e1c39e814ea76f6747e";
    char* key_ascii="3b280014beaac269d613a16bfdc2be03";
    
    for (int i=0;i<16;i++){
				msg_enc[i/4] += charsToHex(msg_ascii[2*i],msg_ascii[2*i+1])<<(8*(3-i%4));
               // int temp = (i % 4) * 4 + i / 4;
                key[i/4] += charsToHex(key_ascii[2*i],key_ascii[2*i+1])<<(8*(3-i%4));
	}
    for(int i = 0; i < 4; i++){
				printf("%08x", msg_enc[i]);
	}
        system("pause");
        return 0;
}
