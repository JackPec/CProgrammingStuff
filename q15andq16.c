#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef char DATA;
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
LINK del_dupl(LINK head);

int main(int argc, char *argv[])
{

    char a[5] = {'a','b','c','c'};
    LINK a1 = string_to_list(a);
    print_list(a1);
    printf("\n");
    LINK a1tail = getoEnd(a1);
    print_listBackwards(a1tail);
    DATA p = 'd';
    a1 = insert(a1,p,0); /* insert like an array */
    printf("\n");
    print_list(a1);
    a1 = insert(a1,'e',5); /* insert like an array */
    a1 = insert(a1,'e',6); /* insert like an array */
    printf("\n");
    print_list(a1);
    a1 = deleteAt(a1,1); /* delete like an array */
    printf("\n");
    print_list(a1);
    a1 = del_dupl(a1);
    printf("\n");
    print_list(a1);

    return 0;
}

LINK string_to_list(char s[])
{
    LINK head;

    static LINK pre = NULL;

    if(s[0] == '\0')
        return NULL;
    else
    {
        head = malloc(sizeof(ELEMENT));
        head -> d = s[0];


        head -> prev = pre;

        pre = head;


        head -> next = string_to_list(s+1);

        return head;

    }

}

void print_list(LINK head)
{
    if(head == NULL)
        printf("NULL");
    else
    {
        printf("%c -- > ", head -> d);
        print_list(head->next);
    }
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

LINK del_dupl(LINK head)
{
    LINK HEAD = head;

    LINK temp = head;
    LINK temp2 = head;

    int n = numOfElemts(temp,0);

    int j = 0;

    for(int i = 0; i < n; i++)
    {
        DATA maybeDup = temp->d;

        while(temp->next != NULL)
        {


            if(temp->next->d == maybeDup)
            {
                printf("\nFound Dup at index: %u, removing \n",j);
                HEAD = deleteAt(HEAD,j);
                n--;
            }

            if(temp->next != NULL)
                temp = temp->next;


        }

        j++;

        temp = temp2->next;
        temp2 = temp2 ->next;

    }


    return HEAD;

}


