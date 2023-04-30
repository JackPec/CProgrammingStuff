#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
    {
        printf("My var n is %d\n",n);
        return (n*factorial(--n));
       // printf("My var n is %d\n",n);
    }

}

/*

this is the working one

int factorial(int n)
{
    if(n <= 1)
        return 1;
    else
        return (n*factorial(n-1));
}
*/

int main(void)
{
    int a = 5;

    printf("%d",factorial(a));

    return 0;
}
