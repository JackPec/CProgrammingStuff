#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>




int gcd(int p, int q)
{
    int r;
    if ((r = p % q) == 0)
        return q;
    else
        return gcd(q, r);

}


int gcdV2(int p, int q)
{
    int r;

    int run = 1;

    while(run)
    {
        if ((r = p % q) == 0)
        {
            run = 0;
            return q;

        }

        else
        {
             p = q;
             q = r;

        }

    }


}

int main(void)
{
    int a = 15;

    int b = 22;

    printf("%d\n",gcd(a,b));
    printf("%d\n",gcdV2(a,b));

    int c = 6;

    int d = 15;

    printf("%d\n",gcd(c,d));
    printf("%d\n",gcdV2(c,d));

    return 0;
}
