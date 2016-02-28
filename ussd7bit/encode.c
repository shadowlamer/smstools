#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

/*
	1. Chop elder bit of each byte
	2. Concatenate 7-bit bytes to one bitstring
	3. Split bitstring to 8-bit bytes
	4. Print each byte as two hex digits
*/

int
main (int argc, char **argv)
{
	char *input, *output, error[] = "USAGE: ussdEncode <string>\n";
	int i, offset, bits, ilen, olen;
	
	if (argc != 2)
	{
		write(2, error, strlen(error));
		return 1;
	}
	
	input = argv[1];
	ilen = strlen(input);
	olen = ceil(ilen / (float)8 * 7);
	output = malloc(olen);
	
	for (i = 0; i < ilen; i++)
	{
		offset = i / 8;
		bits = i % 8;
		
		output[i - offset] = (input[i] & 0b01111111) >> bits;
		if (i < ilen - 1)
			output[i - offset] |= input[i + 1] << (7 - bits);
	}
	
	for (i = 0; i < olen; i++)
		printf("%02X", (unsigned char)output[i]);
	printf("\n");
	
	return 0;
}
