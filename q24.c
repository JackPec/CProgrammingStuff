#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "tree.h"
struct test {
    unsigned a : 1, b : 1, c : 3;

};

int main(void)
{
    int i;
    struct test x;

    for(i = 0; i < 23; ++i)
    {
        /*
        x.a = x.b = x.c = i;
        */

        x.c = x.b = x. a = i;

        printf("x.a = %d    x.b = %d    x.c = %d\n",x.a,x.b,x.c);
    }

    BTREE a;

    inorder(a);

    return 0;
}
