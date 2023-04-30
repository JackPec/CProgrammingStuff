#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct
{

    char name[20];
    char grade;

} student;


typedef student DATA;
typedef struct dllist
{
    DATA d;
    struct dllist *prev;
    struct dllist *next;


} ELEMENT;

typedef ELEMENT *LINK;



LINK string_to_list(char s[]);
void print_list(LINK head);
int numOfElemts(LINK head,int j);
LINK getoEnd(LINK head);
LINK getoStart(LINK head);
void print_listBackwards(LINK tail);

LINK goNext(LINK head);
LINK goPrev(LINK head);
LINK insert(LINK head,DATA p,int i);
LINK insertHead(LINK head,DATA p);
LINK deleteAt(LINK head,int i);
int main(int argc, char *argv[])
{

    int i = 0;

    int running = 1;

    LINK studentlist;

    while(running)
    {


        student temp;
        printf("Enter name, then grade:\n");
        scanf("\n%[^\n]s\n",temp.name);
        scanf("\n%c",&temp.grade);


        if(i == 0)
        {
            studentlist = insertHead(studentlist,temp);
        }
        else
        {
            studentlist = insert(studentlist,temp,i);
        }

        i++;



        char yesorno;

        printf("Enter another name? Enter y for yes, n for no\n");
        scanf("\n%c",&yesorno);

        if(yesorno == 'n')
        {
            running = 0;
        }



    }

    printf("\nList:\n");
    print_list(studentlist);




    return 0;
}

void print_list(LINK head)
{
    if(head == NULL)
        printf("NULL");
    else
    {
        printf("Name: %s, Grade: %c\n", head -> d.name,head -> d.grade);

        print_list(head->next);
    }
    return;
}

int numOfElemts(LINK head,int j)
{
    if(head == NULL)
        return j;
    else
    {
        numOfElemts(head->next,++j);
    }
}

LINK getoEnd(LINK head)
{
    if(head->next == NULL || head == NULL)
    {
        return head;
    }

    else
        getoEnd(head->next);

}

LINK getoStart(LINK head)
{
    if(head == NULL)
        return head;
    if(head->prev == NULL)
    {
        return head;
    }

    else
        getoStart(head->prev);


}

LINK goNext(LINK head)
{
    return head->next;
}

LINK goPrev(LINK head)
{
    return head->prev;
}


void print_listBackwards(LINK tail)
{
    if(tail == NULL)
        printf("NULL");
    else
    {
        printf("%c -- > ", tail -> d);
        print_listBackwards(tail->prev);
    }
}

LINK insert(LINK head,DATA p,int i)
{
    LINK temp = malloc(sizeof(ELEMENT));
    temp -> d = p;

    if(i == 0)
    {
        temp->next = head;

        head->prev = temp;

        temp -> prev = NULL;

        return getoStart(head);


    }

    else if(i > 0)
    {

        for(size_t j = 1; j < i; j++)
        {
            head = goNext(head);
        }

        temp -> next = head ->next;

        temp -> prev = head;
        head -> next = temp;

        return getoStart(head);
    }

}

LINK insertHead(LINK head,DATA p)
{
    head = malloc(sizeof(ELEMENT));
    head -> d = p;

    head->next = NULL;
    head->prev = NULL;

    return head;

}

LINK deleteAt(LINK head,int i)
{

    if(i == 0)
    {
        LINK temp = head;

        head = head->next;

        head->prev = NULL;

        free(temp);


        return head;


    }
    else if (i == 1)
    {
        LINK temp2 = head;

        LINK temp = head->next;

        head->next = head->next->next;

        head->next->prev = head;

        free(temp);

        return temp2;

    }

    else if(i > 0)
    {

        for(size_t j = 0; j < i; j++)
        {

            head = goNext(head);
        }

        if(head->next != NULL)
        {
            LINK temp2 = head -> next;

            LINK temp = head;

            head->prev->next = head->next;

            head->next->prev = head->prev->prev;

            free(temp);

            return getoStart(temp2);

        }
        else
        {

            LINK temp2 = head -> prev;

            LINK temp = head;

            head->prev->next = NULL;

            free(temp);

            return getoStart(temp2);

        }

    }

}


