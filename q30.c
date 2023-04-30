#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{

    int total = 0;

    int i = -5;
    int n = 50;
    /*
    while (i < n)
    {
        ++i;
        total += i;
        printf("i = %d and total = %d\n", i, total);
    }
    */

    mywhile: {
        if(i < n)
        {
            ++i;
            total += i;
            printf("i = %d and total = %d\n", i, total);
            goto mywhile;

        }
    }

    return 0;
}
