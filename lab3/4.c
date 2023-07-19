/* Write a C program to solve the tower of hanoi problem using:
i. recursion and
ii. stack data structure */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

typedef struct stack{
    int han[MAX];
    int top;
    char _ch;
}stack;

void push(int i, stack *s)
{
    if(s->top != MAX - 1)
    {
        s->top += 1;
        s->han[s->top] = i;
        return;
    }
    else 
        printf("Stack Overflow 1\n");
    return;
}

void display(stack *st)
{
    if(st->top != -1)
    {
        // printf("%d\n", st->top);
        for(int i = 0; i <= st->top; i++)
        {
            printf("%d ", st->han[i]);
        }
        printf("\n");
        return;
    }
    else
        printf("Hanoi Tower %c Empty\n", st->_ch);
        return;
}

int pop(stack *s)
{
    if(s->top != -1)
    {
        int c = s->han[s->top];
        s->top = s->top - 1;
        return c;
    }
    else 
        printf("Stack Underflow 2\n");
    exit(102);
}

void hanoi(int n, stack *s, stack *d, stack *a)
{
    if(n == 1)
    {
        printf("From %c to %c\n", s->_ch, d->_ch);
        push(pop(s), d);
        return;
    }
    else
    {
        hanoi(n - 1, s, a, d);
        hanoi(1, s, d, a);
        hanoi(n - 1, a, d, s);
    }
}

int main()
{
    printf("Enter te Number of Disks in the Source Tower\t");
    int n;
    scanf("%d", &n);
    stack sor, des, aux;
    sor.top = -1;
    des.top = -1;
    aux.top = -1;

    sor._ch = 'A';
    des._ch = 'B';
    aux._ch = 'C';

    for(int i = n; i > 0; i--)
    {
        push(i, &sor);
    }
    printf("These are the 3 Towers right now\n\n");
    display(&sor);
    display(&des);
    display(&aux);

    printf("\nSolving\n\n");

    hanoi(n, &sor, &des, &aux); // main hanoi call

    printf("After the Sorting, Towers are\n\n");
    display(&sor);
    display(&des);
    display(&aux);

    printf("\nSolved\n");
    return 0;
}