#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void isBST(btnode *tree, int *temp)
{
    if(!tree) return;
    isBST(tree -> left, temp);
    if(*temp > tree -> data)
    {
        printf("Not a BST\n");
        exit(0);
    }
    *temp = tree -> data;
    isBST(tree -> right, temp);
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

    int t = INT_MIN;
    isBST(root, &t);
    printf("It is a BST\n");

    return 0;
}