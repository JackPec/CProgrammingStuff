#include <stdio.h>
#include <math.h>
#include <limits.h>



int main(void)
{

   float x = 1.0, y = 2.0;
   long float z = 23.34;

   printf("%s%u\n%s%u\n%s%u\n", "sizeof(float) = ",
           sizeof(float) , "sizeof(double) = ",
           sizeof(double) , "sizeof(x + y + z) = ", sizeof(x + y + z));


    return 0;
}

