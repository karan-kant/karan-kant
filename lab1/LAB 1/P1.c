#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top == MAX - 1)
        return 1;
    else    
        return 0;
}

void push(int i)
{
    if(!isFull())
    {
        top = top + 1;
        stack[top] = i;
        printf("Push Confirmed\n");
        return;
    }
    else 
        printf("Stack Overflow\n");
        exit(101);
}

int pop()
{
    if(!isEmpty())
    {
        int a = stack[top];
        top = top - 1;
        return a;
    }

    else
        printf("Stack Undeflow\n");
        exit(102);
}

int peek()
{
    if(!isEmpty())
        return stack[top];
    else    
        printf("Stack Underflow\n");
        exit(103);
}

void display()
{
    if(!isEmpty())
    {
        for(int i = top; i > -1; i--)
        {
            printf("%d\t", stack[i]);
        }
        printf("\n");
        return;
    }
    else 
        printf("Stack Underflow\n");
        return;
}

int main()
{
    while(1)
    {
        printf("1)Push 2)Pop 3)Peek 4)Display 5)Exit\t");
        int x;
        scanf("%d", &x);

        switch(x)
        {
            case 1:
                printf("Enter Number to be pushed\t");
                int a;
                scanf("%d", &a);
                push(a);
                break;
            case 2:
                printf("Confirm pop: Type 1\t");
                scanf("%d", &a);
                if(a == 1)
                {
                    int d = pop();
                    printf("%d popped\n", d);
                }
                else 
                    break;
                break;
            case 3:
                printf("Topmost Element is %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Program Terminated\n");
                return 0;
            default:
                break;
        }
    }
}
