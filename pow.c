#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
Write a function power which computes x^n, x raised to the nth power.
The function signature should look like:
double power(double x, int n)

*/

double power(double x, int n);

int main(int argc, char *argv[])
{


    double a = power(0,1);
    double b = power(0.5,2);
    double c = power(25,25);
    double d = power(-5,5);
    double e = power(5,-5);
    double f = power(11111,1);

    printf("%f\n", a);
    printf("%f\n", b);
    printf("%f\n", c);
    printf("%f\n", d);
    printf("%f\n", e);
    printf("%f\n", f);

    return 0;
}

double power(double x, int n)
{
    double returnVal = 1.0;

    if(x == 0)
    {
        returnVal = 0;

    }
    else if(n == 0)
    {
        returnVal = 1;

    }
    else if(n < 0)
    {
        for(int i = 1; i <= -n; i++)
        {
            double u = (1.0/x);
            returnVal = returnVal *= u;
        }

    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            returnVal = returnVal *= x;
        }

    }



    return returnVal;
}


/*
//recursive form
double power(double x, int n)
{
    if(n<0)
        return 1/x * power(1/x, -(n+1));
    if(n==0)
        return 1;
    if(n==2)
        return x*x;
    if(n%2==0)
        return power( power(x, n/2), 2);
    else
        return x*power( power(x, n/2), 2);


}
*/
