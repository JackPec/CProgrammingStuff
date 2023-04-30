#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{

    char last_name[20];
    int student_id;
    char grade;

} student;

void swap(student* xp, student* yp);
void bubbleSortForName(student arr[], size_t n);
void bubbleSortForGrade(student arr[], size_t n);

double class_average(student arr[],size_t n);

int main(int argc, char *argv[])
{

    FILE *ifp;

    ifp = fopen("data.txt","r");

    if(!ifp)
    {
        printf("Can't open file");
        return 0;
    }

    student x;

    int SIZE = 0;

    while(fscanf(ifp,"%s %d %c",&(x.last_name)[0],&x.student_id,&x.grade) == 3)
    {
        SIZE++;
    }

    printf("Size of Student array is %d\n",SIZE);
    rewind(ifp);


    student n[SIZE]; //or whatever amount needed;

    size_t i = 0;
    while(fscanf(ifp,"%s %d %c",&(x.last_name)[0],&x.student_id,&x.grade) == 3)
    {
        printf("%d\n",i);

        /*
        printf("%s ",x.last_name);
        printf("%d ",x.student_id);
        printf("%c\n",x.grade);
        printf("heyo");
        */


        n[i] = x;



        i++;

    }


    printf("\nOrignal Student Array\n");
    for(int j = 0; j < SIZE; j++)
    {

        printf("%s ",n[j].last_name);
        printf("%d ",n[j].student_id);
        printf("%c \n",n[j].grade);

    }



    /*
        Sort the student array, first by grade,
         then by name


    */

    bubbleSortForName(n,SIZE);
    bubbleSortForGrade(n,SIZE);




    printf("\nSorted Student Array\n");
    for(int j = 0; j < SIZE; j++)
    {

        printf("%s ",n[j].last_name);
        printf("%d ",n[j].student_id);
        printf("%c \n",n[j].grade);

    }

    printf("\nClass Average is a %f GPA \n",class_average(n,SIZE));

    fclose(ifp);

    return 0;
}



void swap(student* xp, student* yp)
{
    student temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSortForName(student arr[], size_t n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j + 1].last_name,arr[j].last_name) < 0)
                swap(&arr[j], &arr[j + 1]);
}

void bubbleSortForGrade(student arr[], size_t n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j + 1].grade < arr[j].grade)
                swap(&arr[j], &arr[j + 1]);
}

double class_average(student arr[],size_t n)
{
    double classAvg = 0;

    for(size_t i = 0; i < n; i++)
    {
        if(arr[i].grade == 'A')
        {
           classAvg += 4.0;
        }
        else if (arr[i].grade == 'B')
        {
            classAvg += 3.0;
        }
        else if (arr[i].grade == 'C')
        {
            classAvg += 2.0;
        }
        else if (arr[i].grade == 'D')
        {
            classAvg += 1.0;
        }
        else if (arr[i].grade == 'F')
        {
            classAvg += 0.0;
        }
    }

    return classAvg / n;

}
