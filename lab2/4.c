/* Using stack data structure, write a C program to evaluate prefix expression provided by the user. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 30

char stack[MAX];
int top = -1;

char pop()
{
    if(top != -1)
    {
        char c = stack[top];
        top = top - 1;
        return c;
    }
    else 
        printf("Stack Underflow\n");
    exit(101);
}

void push(char c)
{
    if(top != MAX - 1)
    {
        top = top + 1;
        stack[top] = c;
        return;
    }
    else
        printf("Stack Overflow\n");
    exit(102);
}

int main()
{
    printf("Enter the Prefix Expression\n");
    char arr[MAX];
    scanf("%s", arr);
    int len = strlen(arr);
    strrev(arr);

    for(int i = 0; i < len; i++)
    {
        if(isdigit(arr[i]))
        {
            push(arr[i] - '0');
        }
        else if(arr[i] == '*')
        {
            int x = (int)pop();
            int y = (int)pop();
            push((char)(x*y));
        }
        else if(arr[i] == '/')
        {
            int x = (int)pop();
            int y = (int)pop();
            push((char)(y/x));
        }
        else if(arr[i] == '-')
        {
            int x = (int)pop();
            int y = (int)pop();
            push((char)(y - x));
        }
        else if(arr[i] == '+')
        {
            int x = (int)pop();
            int y = (int)pop();
            push((char)(x + y));
        }
    }
    printf("Result is\t%d", (int)pop());
    return 0;
}