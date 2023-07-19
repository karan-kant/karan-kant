#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

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

node *bt_to_bst(node *root, btnode *tree, btnode *trav)
{
    if(!trav) return root;
    root = bt_to_bst(root, tree, trav -> left);
    node *temp = NULL;
    temp = create_node(trav -> data);
    root = insert(root, temp);
    root = bt_to_bst(root, tree, trav -> right);
    return root;
}

int main()
{
    btnode *btroot = create_btnode(1);
    btroot -> left = create_btnode(2);
    btroot -> right = create_btnode(3);
    btroot -> left -> left = create_btnode(4);
    btroot -> left -> right = create_btnode(5);
    btroot -> right -> left = create_btnode(6);
    btroot -> right -> right = create_btnode(7);
    btnode *t = btroot;
    node *bstroot = NULL;
    bstroot = bt_to_bst(bstroot, btroot, t);
    display(bstroot);
    printf("\n");

    return 0;
}