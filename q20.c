#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    int a = 0, b = 0, x;
    x = 0 && (a = b = 777);
    printf("%d %d %d\n", a, b, x);
    x = 777 || (a = ++b);
    printf("%d %d %d\n", a, b, x);


    return 0;
}
