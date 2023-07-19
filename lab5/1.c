/* Write a program to demonstrate various singly linked list operations such as insertion, deletion and
traversal. The program should be menu driven. The program should allow the user to insert, delete
at the beginning, end, and at a specified position in the linked list. */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_start(int info)
{
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    temp = start;
    start = new_node;
    new_node->next = temp;
    new_node->data = info;
    return;
}

void insert_end(int info)
{
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = info;
    temp = start;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
    return;
}

void insert_mid(int info)
{
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = info;
    temp = start;
    int i = 1, x;
    printf("Enter the Location of Insertion\t");
    scanf("%d", &x);
    while(i < x -1){
        temp = temp->next;
        i++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return;
}

void delete_start()
{
    struct node *temp;
    temp = start;
    start = temp->next;
    free(temp);
    return;
}

void delete_end()
{
    struct node *temp, *prev;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
    return;
}

void delete_mid()
{
    struct node *temp, *prev;
    int i = 1, x;
    temp = start;
    printf("Enter the position to delete\t");
    scanf("%d", &x);
    while(i < x - 1){
        temp = temp->next;
    }
    prev = temp->next;
    temp = prev->next;
    free(temp);
    return;
}

void display()
{
    struct node *check;
    check = start;
    int count = 0;
    if(check == NULL)
        printf("Linked List Empty\n");
    else
    {
        while(check != NULL){
            count = count + 1;
            printf("NODE#%d:\t%d\n", count, check->data);
            check = check->next;
        }
        printf("Linked List Terminated\n");
    }
    return;
}

int main()
{
    while(1)
    {
        printf("1)INS_B 2)INS_E 3)INS_Mid\n");
        printf("4)DEL_B 5)DEL_E 6)DEL_Mid\n");
        printf("7)Traverse 8)Exit\n\t\t\t");
        int n;
        scanf("%d", &n);
        int x;
        switch(n)
        {
            case 1:
                printf("Enter number to be added\t"); 
                scanf("%d", &x);
                insert_start(x);
                break;
            case 2:
                printf("Enter number to be added\t");
                scanf("%d", &x);
                insert_end(x);
                break;
            case 3:
                printf("Enter the number to be added\t");
                scanf("%d", &x);
                insert_mid(x);
                break;
            case 4:
                printf("Deleted\n");
                delete_start();
                break;
            case 5:
                printf("Deleted\n");
                delete_end();
                break;
            case 6:
                delete_mid();
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
            default:
                printf("Invalid Input\n");
                break;
        }
    }
    return 0;
}