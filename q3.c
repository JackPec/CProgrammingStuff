#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <stddef.h>

int main(int argc, char *argv[])
{

    int a, b, *p = &a, *q = &b;

    ptrdiff_t diff = p - q;
    // ( p2 - p1 ) == ( addr( p2 ) - addr( p1 ) ) / sizeof( T )

    printf("p - q, diff = %p\n",diff);
    printf("diff = %ld\n",diff);


    diff = p - (int *) 0; // (int*) 0 is nullptr

    printf("p - null, diff = %p\n",diff);
    printf("diff = %ld\n",diff);

    printf("p by itself = %p\n",p);
    printf("p = %ld\n",p);

    printf("q by itself = %p\n",q);
    printf("q = %ld\n",q);

    printf("(int *) 0 by itself = %p\n",(int *) 0);
    printf("(int *) 0 = %ld\n",(int *) 0);

    //error message
    //diff = p - (ptrdiff_t *) 0;

    //printf("diff = %d\n",diff);

    return 0;
}
