
#include "utils.h"
#include <string.h>

int setNth(char* mask, int n)
{
	int c = 0;
	while(*(mask+c) || (n--) > 0) c++;
	*(mask+c) = 1;
	return c;
}

// Function implementation
int main( int argc, char **argv)
{
	int N, x, k, v;
	scanf("%d %d", &x, &N); x--;

	char* mask = malloc(N*sizeof(char));
 	char* res = malloc(N*sizeof(char));	
	for (int i=0; i<N;i++)
		*(mask+i) = 0;

	for (int i=0; i<N; ++i)
	{
		k = fac(N-i-1);
		*(res+i) = '0' + setNth(mask, x/k);
		x %= k;
	}
	printf("\n%s\n", res);
}


