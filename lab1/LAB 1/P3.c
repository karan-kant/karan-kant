#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 35

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
    if(!isEmpty())
    {
        char c = stack[top];
        top = top - 1;
        return c;
    }
    else
        printf("Stack Underflow\n");
        exit(101);
}

int main()
{
    printf("Enter the string to be checked\t");
    char st[MAX];
    scanf("%s", st);

    int len = strlen(st);
    for(int i = 0; i < len; i++)
    {
        push(st[i]);
    }
    int a = 0;
    for(int i = 0; i < len; i++)
    {
        char c = pop();
        if(c == st[i])
        {
            continue;
        }
        else 
            a = 1;
    }

    if(a == 0)
        printf("String is Palindrome\n");
    else
        printf("String is not a Palindrome\n");
    return 0;
}
