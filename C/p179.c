
#include "utils.h"
#include <string.h>

// Function decleration
int* brutForce(int max);

// Function implementation
int main( int argc, char **argv)
{
    factor * facs; int size;
    for (int i=0;i<16;i++)
    {
        facs = factors(i, &size);
        printf("%3d: ", i);
        for(int j=0;j<size;j++)
            printf("(%d, %d) ", facs[j].p, facs[j].m);
        printf("\n");
    }

    free_utils();
}

void with_N_divs(int N, int max)
{
    //factors(i*2, facs, &size);
}

int* brutForce(int max)
{
    factor *facs;
    int size, count=0;
    int nn, tmp;
    nn = 2;

    int mm=1;

    for(int n=2;n<max; n++)
    {
        //printf("%5d %d \n", n, ndivs(primes, n));

        if (n%100000==0)
            printf("%d %d\n", n, count);
        if((tmp=ndivs(n+1)) == nn){
            count++;
            if (nn==9)
            {printf("%2d: %4d: ", nn, n); mm=nn;

            facs = factors(n, &size);
            for (int i=0;i<size;i++)
                printf("(%d, %d) ", facs[i].p, facs[i].m);
            printf("\n    %4d: ", n+1);
            facs = factors(n+1, &size);
            for (int i=0;i<size;i++)
                printf("(%d, %d) ", facs[i].p, facs[i].m);
            printf("\n");
            }
        }

        nn=tmp;

    }
    free(facs);
}
