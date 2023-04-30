#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 4

typedef unsigned long ulong;

int main(int argc, char *argv[])
{

    int a[4.0] = {1,2,3,4,5};

    char *pc = NULL;
    int *pi = NULL;
    double *pd = NULL;
    long double *pLd = NULL;
    //printf("%lu",pLd+3);
    printf("\n%p\n",pLd+38);


    printf("%5lu%5lu\n%5lu%5lu\n%5lu%5lu\n",
          (ulong)(pc+1),(ulong)(pi+1),
           (ulong)(pd+1),(ulong)(pLd+1),
           (ulong)(pc+3),(ulong)(pLd+3));

     printf("%5lu%5lu\n%5lu%5lu\n%5lu%5lu\n",
          (pc+1),(pi+1),
           (pd+1),(pLd+1),
           (pc+3),(pLd+3));

    printf("%5p\n%5p\n%5p\n%5p\n%5p\n%5p\n",
          (pc+1),(pi+1),
           (pd+1),(pLd+1),
           (pc+3),(pLd+3));




    return 0;
}
