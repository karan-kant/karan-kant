
#include <stdio.h>
#include <stdlib.h>

struct node{
    int var;
    struct node* next;
};

struct node *head = NULL;

void insB(int info)
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->next = head;
    new->var = info;
    head = new;
    return;
}

void insE(int info)
{
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->var = info; 
    temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return;
}

void insMid(int info)
{
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->var = info;
    temp = head;
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
    temp = head;
    head = temp->next;
    free(temp);
    return;
}

void delete_end()
{
    struct node *temp, *prev;
    temp = head;
    while(temp->next != head){
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = head;
    return;
}

void delete_mid()
{
    struct node *temp, *prev;
    int i = 1, x;
    temp = head;
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
    check = head;
    int count = 0;
    if(check == NULL)
        printf("Linked List Empty\n");
    else
    {
        while(check != NULL){
            count = count + 1;
            printf("NODE#%d:\t%d\n", count, check->var);
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

        switch(n)
        {
            case 1:
                int x;
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
