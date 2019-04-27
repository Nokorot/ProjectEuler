
#include "utils.h"
#include <string.h>


// Function implementation
int main( int argc, char **argv)
{
	int c = 10, x=1000000, k, v;
 	char* res = malloc(c*sizeof(char));	
	for (int i=1; i<c; ++i)
	{
		k = fac(c-i);
		printf("%d %d\n", k, c-i);
		for (v=c-i; v*k > x; --v);
		x-=v*k;
		*(res+i-1) = '0'+v;
	}
	printf("%s\n", res);
}


