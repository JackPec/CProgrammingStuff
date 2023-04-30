#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//#include <string.h>

/*

A palindrome is a string that reads the same both forward and backward. Some examples are"ABBA" "123343321" "otto"
Write a function that takes a string as an
argument and returns the int value 1 if the string is a palindrome and returns  0 otherwise.
*/


int palindrome(const char in[],int stringSize);


int main(int argc, char *argv[])
{
    const char a[5] = "ABBA";
    const char b[10] = "123343321";
    const char c[5] = "otto";
    const char d[3] = "cat";
    const char e[3] = "dog";



    printf("%d\n",palindrome(a,5));
    printf("%d\n",palindrome(b,10));
    printf("%d\n",palindrome(c,5));
    printf("%d\n",palindrome(d,3));
    printf("%d\n",palindrome(e,3));


}

int palindrome(const char in[],int stringSize)
{
    int stringLength = stringSize - 1;

    int returnVal = 1;

    int i = 0;
    while (in[i] != '\0')
    {
        // do something with s[i]

        if(in[i] != in[stringLength] && in <= stringLength)
        {
            returnVal = 0;
        }


        --stringLength;

        ++i;
    }

    return returnVal;
}
