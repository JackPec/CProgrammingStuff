#include <stdio.h>

#define N 20

double power(int,int);
void prn_heading(void);
void prn_tbl_powers(int);

int main(void)
{
    prn_heading();
    prn_tbl_powers(N);
    return 0;

}

void prn_heading(void)
{
    printf("\n::::: A TABLE OF POWERS :::::\n\n");
}

void prn_tbl_powers(int n)
{
    int i, j;

    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j<= n; ++j)
            if(j==1)
                printf("%lf",power(i,j));
            else
                printf("%9lf",power(i,j));
            putchar('\n');
    }
}


double power(int m, int n)
{
    int i;
    double product = 1;

    for(i = 1; i <=n; ++i)
        product *= m;

    product = floor(10000*product)/10000;
    return product;
}
