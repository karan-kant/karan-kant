#include <stdio.h>
#include <stdlib.h>
#include "doublyLL.h"

dNode *swap(dNode *p, dNode *c)
{
    dNode *n = c -> next;
    c -> next = n -> next;
    if(n -> next) n -> next -> prev = c;
    n -> next = c;
    n -> prev = p;
    p -> next = n;
    c -> prev = n;
    return n;
}

dNode *sort(dNode *head, int a)
{
    if(!head)
    {
        printf("\n");
        return 0;
    }
    if(!head -> next)
    {
        printf("%d\n", head -> data);
        clear_list(head);
        return 0;
    }
    dNode *dummy = doublyAlloc(-1);
    head = insert_begin(head, dummy);
    dNode *prev = head, *curr = head -> next;

    int flag = 1;
    do
    {
        flag = 0;
        prev = head;
        curr = head -> next;
        while(curr -> next)
        {
            if(a == 0)
            {
                if(curr -> data > (curr -> next -> data))
                {
                    flag = 1;
                    curr = swap(prev, curr);
                }
                prev = curr;
                curr = curr -> next;
            }
            else
            {
                if(curr -> data < (curr -> next -> data))
                {
                    flag = 1;
                    curr = swap(prev, curr);
                }
                prev = curr;
                curr = curr -> next;
            }
        }
    }
    while(flag);
    return dummy->next;
}


int main()
{
    int n;
    dNode *head = NULL;

    printf("Enter the Number of elements to be inserted\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int a;
        printf("Enter the value\n");
        scanf("%d", &a);
        head = append(head, doublyAlloc(a));
    }

    printf("0.Ascending \n1.Descending\n");
    scanf("%d", &n);
    head = sort(head, n);
    display(head);
}