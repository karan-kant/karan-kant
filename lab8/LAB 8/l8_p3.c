#include <stdio.h>
#include "linkedlist.h"


node *swap(node *trav, node *prev)
{
    if(!trav->next) return NULL;
    node  *temp = trav->next;
    trav->next = temp->next;
    temp->next = trav;
    prev->next = temp;
    return trav;
}

int main()
{
    node *head = NULL;
    int n;
    printf("Enter the Size fo the Elements to insert\n");
    scanf("%d", &n);
    head = addElements(n);
    node *trav = create_node(-1);
    trav->next  = head;
    node *t1 = trav;
    while(t1 && t1->next)
    {

        t1 = swap(t1->next,t1);
    }

    display(trav->next);
}