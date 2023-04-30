#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*
void f(int x)
{
    x = 2;

    z+= x;
}
*/

int z;

int f(int x)
{
    x = 2;

    z+= x;

    return z;
}

int main(int argc, char *argv[])
{

    z = 5;

    //f(z);

    z = f(z);

    printf("z= %d\n",z);

    return 0;
}
