#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct node {
    DATA d;
    struct node *left;
    struct node *right;



};

typedef struct node NODE;
typedef NODE *BTREE;

void inorder(BTREE root);
void preorder(BTREE root);
void postorder(BTREE root);
BTREE new_node(void);
BTREE init_node(DATA d1, BTREE p1, BTREE p2);
BTREE create_tree(DATA a[],int i,int size);

int countNumNodes(BTREE root);
int countNumNodesIf(BTREE root,DATA elem);
void inorderLeafOnly(BTREE root);

int main(int argc, char *argv[])
{
    int sizeNodes = 7;
    DATA myarray[sizeNodes];

    myarray[0] = 'a';
    myarray[1] = 'b';
    myarray[2] = 'c';
    myarray[3] = 'd';
    myarray[4] = 't';
    myarray[5] = 'f';
    myarray[6] = 'f';

    BTREE myTree = create_tree(myarray,0,sizeNodes);

    printf("Inorder: ");
    inorder(myTree);

    printf("\nNumber of nodes in the Tree is %d \n",countNumNodes(myTree));

    DATA toCheck = 'f';

    printf("\nNumber of nodes in the Tree with value %c is %d \n",
           toCheck,countNumNodesIf(myTree,toCheck));

    printf("Inorder leaves only: ");
    inorderLeafOnly(myTree);

    return 0;
}


void inorder(BTREE root)
{
    if(root != NULL){
        inorder(root->left);
        printf("%c ", root-> d);
        inorder(root -> right);
    }
}

void preorder(BTREE root)
{
    if(root != NULL){
        printf("%c ", root-> d);
        preorder(root->left);
        preorder(root -> right);
    }
}

void postorder(BTREE root)
{
    if(root != NULL){
        postorder(root->left);
        postorder(root -> right);
        printf("%c ", root-> d);
    }
}

BTREE new_node(void)
{
    return (malloc(sizeof(NODE)));
}

BTREE init_node(DATA d1, BTREE p1, BTREE p2)
{
    BTREE t;
    t = new_node();
    t -> d = d1;
    t -> left = p1;
    t -> right = p2;

    return t;
}

/* Create a linked binary tree from an array  */

BTREE create_tree(DATA a[],int i,int size)
{
    if(i >= size)
        return NULL;
    else
        return (init_node(a[i],
                          create_tree(a,2*i+1,size),
                          create_tree(a,2*i+2,size)));
}

int countNumNodes(BTREE root)
{
    int static counter = 0;

    if(root != NULL){
        countNumNodes(root->left);
        counter++;
        countNumNodes(root -> right);
    }

    return counter;

}

int countNumNodesIf(BTREE root,DATA elem)
{
    int static counter = 0;

    if(root != NULL){
        countNumNodesIf(root->left,elem);

        if(root->d == elem)
            counter++;

        countNumNodesIf(root -> right,elem);
    }

    return counter;

}

void inorderLeafOnly(BTREE root)
{
    if(root != NULL){

        inorderLeafOnly(root->left);

        if(root->left == NULL && root->left == NULL)
        {
            printf("%c ", root-> d);
        }

        inorderLeafOnly(root -> right);
    }
}
