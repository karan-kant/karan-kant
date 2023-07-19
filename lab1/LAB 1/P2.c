#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

char stack[MAX];
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

void push(char c)
{
    if(!isFull())
    {
        top = top + 1;
        stack[top] = c;
        return;
    }
    else
        printf("Stack Overflow\n");
        return;
}

char pop()
{
    if(!isEmpty)
    {
        char c = stack[top];
        top = top - 1;
        return c;
    }
    else
        printf("Stack Underflow\n");
        exit(101);
}

char peek()
{
    if(!isEmpty())
    {
        char c = stack[top];
        return c; 
    }
    else    
        printf("Stack Underflow\n");
        exit(102);
}

void display()
{
    if(isEmpty)
    {
        for(int i = top; i > -1; i--)
        {
            printf("%c", stack[i]);
        }
        printf("\n");
    }
    else   
        printf("Stack Underflow\n");
        return;
}

int main()
{
    printf("Enter the string\n");
    char str[MAX];
    scanf("%s", str);
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        push(str[i]);
    }
    printf("The Reversed String is\n");
    display();
    return 0;
}
