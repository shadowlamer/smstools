#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iconv.h>

/*
	1. Chop elder bit of each byte
	2. Concatenate 7-bit bytes to one bitstring
	3. Split bitstring to 8-bit bytes
	4. Print each byte as two hex digits
*/

unsigned char
hexVal (unsigned char number)
{
	if (number <= '9')
		return number - '0';
	return number - 'A' + 10;
}

int
main (int argc, char **argv)
{
	char *input, *output, *result, error[] = "USAGE: ussdDecode <string>\n";
	size_t i, ilen, olen, rlen;
	iconv_t	cd;
	
	if (argc != 2)
	{
		write(2, error, strlen(error));
		return 1;
	}
	
	input = argv[1];
	ilen = strlen(input);
	olen = ilen / 2;
	output = malloc(olen);
	
	for (i = 0; i < olen; i ++)
	{
		output[i] = hexVal(input[i * 2]) << 4;
		output[i] += hexVal(input[i * 2 + 1]);
	}
	
	input = output;
	rlen = ilen = olen;
	result = output = malloc(olen + 1);
	cd = iconv_open("UTF-8", "UCS-2BE");
	iconv(cd, &input, &ilen, &output, &olen);
	iconv_close(cd);
	rlen -= olen;
	result[rlen] = 0;
	
	printf("%s\n", result);
	
	return 0;
}
