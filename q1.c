#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main(int argc, char *argv[])
{

    char *format = "%p %d %d %d\n";
    int i = 3;
    int *p = &i;
    printf(format, p, *p + 7, 3 * **&p + 1, 5 * (p - (p - 2)));

    printf("%p %d %d %d\n", p, *p + 7, 3 * **&p + 1, 5 * (p - (p - 2)));

    printf("%d \n", p);
    printf("%p \n", p);
    printf("%d \n", p-2);
    printf("%p \n", p - 2);

    printf("%d \n", p - (p - 2));













    return 0;
}
