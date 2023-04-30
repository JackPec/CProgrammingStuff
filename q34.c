#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);

    int startCap = 0;

    for(int i = 0; i < argc; ++i)
    {

        if(argv[i][0] == '-'&& argv[i][1] == 'c')
        {
            startCap = 1;
        }
    }

    for(int i = 0; i < argc; ++i)
    {
        if(startCap == 1)
        {
            size_t length = strlen(argv[i]);

            for(int j = 0; j < length; j++)
                argv[i][j] = toupper(argv[i][j]);
        }

        if(!(argv[i][0] == '-'&& argv[i][1] == 'C'))
            printf("argv[%d] = %s\n",i,argv[i]);

    }

    return 0;
}
