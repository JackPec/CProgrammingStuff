#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    short n = 0;

    printf("Input an integer: ");
    scanf("%d", &n);


    while (--n)
    {
         printf("%d\n",n);

    }

    return 0;
}
