#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>




int main(void)
{

    static int count = 1;
    printf(" The universe is never ending! \n");

    if(count < 17)
    {
        count++;
        main();
    }



    return 0;
}
