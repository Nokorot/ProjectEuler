#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

static const char* primesFile = "../primes.dat";
static int* primes_data = 0;

uint bytes2int(const byte *data, const int i);
uint primes_len();
uint * primes();

uint bytes2int(const byte *data, const int i) {
	return ((data[i+0] <<  0) & 0x000000ff) | ((data[i+1] <<  8) & 0x0000ff00)
       | ((data[i+2] << 16) & 0x00ff0000) | ((data[i+3] << 24) & 0xff000000);
}

uint primes_len()
{
	if (primes_data)
		return *primes_data;
	return *(primes()-1);
}

uint * primes()
{
	if (primes_data)
		return primes_data+1;

	FILE *file;
	byte *buffer;
	unsigned long fileLen;

	//Open file
	file = fopen(primesFile, "rb");
	if (!file)
	{
		fprintf(stderr, "Unable to open file %s", primesFile);
		return 0;
	}

	//Get file length
	fseek(file, 0, SEEK_END);
	fileLen=ftell(file);
	fseek(file, 0, SEEK_SET);

	//Allocate memory
	buffer = (byte *)malloc(fileLen+1);
	if (!buffer)
	{
		fprintf(stderr, "Memory error!");
		fclose(file);
		return 0;
	}

	//Read file contents into buffer
	fread(buffer, fileLen, 1, file);
	fclose(file);

	//bytes2ints
	uint size = bytes2int(buffer, 0);
	primes_data = (uint *) malloc(fileLen);
	for(int i=0;i<fileLen/sizeof(uint);i++)
		primes_data[i] = bytes2int(buffer, i*sizeof(uint));
	primes_data[0] = fileLen/sizeof(uint);

	free(buffer);
	return primes_data+1;
}

void free_primes()
{
	if (primes_data)
		free(primes_data);
}
