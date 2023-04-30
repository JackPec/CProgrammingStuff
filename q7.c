#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    /*
    int i;
    while (i = 2)
    {
        printf("Some even numbers: %d %d %d\n", i, i + 2, i + 4);
        i = 0;
    }
    */

    /* Code Above causes printing to loop forever*/


    int i;
    if (i = 2)
        printf("Some even numbers: %d %d %d\n", i, i + 2, i + 4);

    /* Code above just assigns i a value of 2, then prints */


    return 0;
}
