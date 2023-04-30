#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void try_me(int [][3]);

int main(int argc, char *argv[])
{

    int a[3][3] = {{2,5,7},{0,-1,-2},{7,9,3}};

   // **a;

    try_me(a);



    return 0;
}

void try_me(int *a[3])
{
    printf("%d %d %d %d . . . infinity\n"
           ,a[1][0],-a[1][1],a[0][0],a[2][2]);
}

/*
void try_me(int (*a)[3])
{
    printf("%d %d %d %d . . . infinity\n"
           ,a[1][0],-a[1][1],a[0][0],a[2][2]);
}
*/

