#ifndef _INT_BST_H_
#define _INT_BST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int d)
{
    node *new_node = (node *) malloc(sizeof(node));
    if(!new_node)
    {
        printf("Couldn't create a new node\n");
        exit(1);
    }
    new_node -> data = d;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

node *insert(node *tree, node *n)
{
    if(!tree) return n;
    node *trav = tree;
    int lflag = 0, rflag = 0;
    while(trav)
    {
        if(n -> data == trav -> data)
        {
            return tree;
        }
        else if(n -> data < trav -> data)
        {
            if(trav -> left) trav = trav -> left;
            else
            {
                lflag = 1;
                break;
            }
        }
        else if(n -> data > trav -> data)
        {
            if(trav -> right) trav = trav -> right;
            else
            {
                rflag = 1;
                break;
            }
        }
    }
    if(lflag)
    {
        trav -> left = n;
    }
    else if(rflag)
    {
        trav -> right = n;
    }
    return tree;
}

void search(node *tree, int n)
{
    if(!tree)
    {
        printf("Not found!\n");
        return;
    }
    if(tree -> data == n)
    {
        printf("Found!\n");
        return;
    }
    else if(n < tree -> data)
    {
        search(tree -> left, n);
    }
    else if(n > tree -> data)
    {
        search(tree -> right, n);
    }
}

void display(node *tree)
{
    if(!tree) return;
    display(tree -> left);
    printf("%d ", tree -> data);
    display(tree -> right);
}

node *delete_node(node *tree, int key)
{
    if(!tree) return NULL;
    if(key < tree -> data)
    {
        tree -> left = delete_node(tree -> left, key);
        return tree;
    }
    else if(key > tree -> data)
    {
        tree -> right = delete_node(tree -> right, key);
        return tree;
    }
    else
    {
        if(!tree -> left && !tree -> right)
        {
            free(tree);
            return NULL;
        }
        else if(tree -> left && !tree -> right)
        {
            node *temp = tree -> left;
            free(tree);
            return temp;
        }
        else if(!tree -> left && tree -> right)
        {
            node *temp = tree -> right;
            free(tree);
            return temp;
        }
        else if(tree -> left && tree -> right)
        {
            node *temp = tree -> left;
            while(temp -> right) temp = temp -> right;
            int t = temp -> data;
            temp -> data = tree -> data;
            tree -> data = t;
            tree -> left = delete_node(tree -> left, temp -> data);
            return tree;
        }
    }
}

node *clear_tree(node *tree)
{
    if(!tree) return NULL;
    tree -> left = clear_tree(tree -> left);
    tree -> right = clear_tree(tree -> right);
    free(tree);
    return NULL;
}

#endif