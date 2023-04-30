#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    int i, j;

    printf("Input two integers: ");
    scanf("%d%d", &i, &j);
    while (i * j < 0 && ++i != 7 && j++ != 9)
    {

        printf("Hey");

    }

    printf("Hooh");

    return 0;
}
