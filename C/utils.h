
#include "primes.h"

typedef unsigned long ulong;

typedef struct {
    int p, m;
} factor;

// Function decleration
long fast_atoi( const char* str);
factor * factors(ulong num, int* size);
int ndivs(int num);
long npow(int a, int e);
void free_utils();

long fast_atoi( const char* str )
{
    long val = 0;
    while( *str )
        val = val*10 + (*str++ - '0');
    return val;
}

// Static members
factor * factors_data = 0;

// Function implementation
factor * factors(ulong num, int* size)
{
    if (!factors_data)
        factors_data = (factor *) malloc( 15*sizeof(factor) );

    ulong nn = num;
    int *p = primes();
    int m = 0, c = 0;
    while (*p && nn >= npow(*p,2)) { // if 1 < nn < pow(*p, 2) then nn is prime.
        m = 0;
        while (nn % *p == 0)
        { m++; nn /= *p; }
        if (m > 0)
        { factors_data[c].m = m; factors_data[c++].p = *p; }
        p++;
    }
    if(!*p) {
        printf("Was unable to factorize %lu, it exides the prime list. \n Got to %lu \n", num, nn);
        return 0;
    }
    if (nn > 1)
    { factors_data[c].m = 1; factors_data[c++].p = nn; }

    *size = c;
    return factors_data;
}

int ndivs(int num)
{
    int *p = primes();
    int nn = num, divs = 1, m;
    while ( *p && nn >= npow(*p,2) ) {
        m = 0;
        while (nn % *p == 0)
        { m++; nn /= *p; }
        divs *= m+1;
        p++;
    }
    if (nn > 1)
        return divs*2;
    return divs;
}

long npow(int a, int e)
{
    long res = 1;
    for(int i=0;i<e;i++)
        res*=a;
    return res;
}

ulong fac(unsigned x) 
{
	ulong res = 1;
	for(int i=1;i<=x;++i)
		res*=i;
	return res;
}


void free_utils()
{
    if(factors_data)
        free(factors_data);
    free_primes();
}
