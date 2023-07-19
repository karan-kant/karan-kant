#include <stdio.h>
#include <stdlib.h>

typedef struct btnode 
{
    int data;
    struct btnode *left;
    struct btnode* right;
}btnode;

btnode *create_btnode(int d)
{
    btnode *temp = (btnode *) malloc(sizeof(btnode));
    if(!temp)
    {
        printf("Couldn't create new BT node\n");
        exit(1);
    }
    temp -> data = d;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void invert(btnode *tree)
{
    if(!tree) return;
    invert(tree -> left);
    invert(tree -> right);
    btnode *t1 = tree -> left;
    tree -> left = tree -> right;
    tree -> right = t1;
}

void display(btnode *tree)
{
    if(!tree) return;
    display(tree -> left);
    printf("%d ", tree -> data);
    display(tree -> right);
}

int main()
{
    btnode *root = create_btnode(5);
    root -> left = create_btnode(3);
    root -> left -> left = create_btnode(2);
    root -> left -> right = create_btnode(4);
    root -> right = create_btnode(8);
    root -> right -> left = create_btnode(6);
    root -> right -> right = create_btnode(10);
    
    invert(root);
    display(root);
    printf("\n");

    return 0;
}