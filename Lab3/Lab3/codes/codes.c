#include"mmath.h"
#include<stdio.h>

int encrypt(int start, int offset, char encrypt) {
	encrypt = bitrevc(encrypt);
	int cipher = (int)encrypt;
	cipher <<= start;
	cipher >>= offset;
	return cipher;	
}

char decrypt(int start, int offset, int cipher) {
	cipher <<= offset;
	cipher >>= start;
	char encrypt = (char)cipher;
	encrypt = bitrevc(encrypt);
	return encrypt;
}
