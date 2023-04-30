#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>




typedef struct
{

    char* name;
    char* address;
    double avgcost;
    char* typeOfFood;

} restaurant;



void printRestaurants(restaurant p[],int pSize, char* type);

int main(int argc, char *argv[])
{

    restaurant mc =
    {
        "McDonalds",
        "555 Burger ave, Burgertown,MC",
        10,
        "FastFood"
    };

    restaurant sy =
    {
        "Subway",
        "554 Sub Street, Burgertown,MC",
        5,
        "FastFood"
    };

    restaurant bb =
    {
        "Big Bowl",
        "Near Woodfield Mall",
        30,
        "FineDining"
    };

    restaurant wf =
    {
        "Wild Fire",
        "Near Woodfield Mall as well",
        20,
        "FineDining"
    };


    restaurant list[4] = {mc,sy,bb,wf};

//printing
    printf("\nPrinting Fine Dining Option\n");
    printRestaurants(list,4,"FineDining");
    printf("\nPrinting Fast Food Option\n");
    printRestaurants(list,4,"FastFood");






    return 0;
}

int comparator(const void *p, const void *q)
{
    int l = ((restaurant *)p)->avgcost;
    int r = ((restaurant *)q)->avgcost;
    return (l - r);
}

void printRestaurants(restaurant p[],int pSize, char* type)
{
    qsort(p,pSize,sizeof(*p),comparator);

    for(int i = 0; i < pSize; i++)
    {
        if(strcmp(p[i].typeOfFood,type) == 0)
        {

            printf("\nName: %s\nAddress: %s\nAvg cost: $%f\nType: %s\n\n",
                   p[i].name,p[i].address,p[i].avgcost,p[i].typeOfFood);
        }


    }


}
