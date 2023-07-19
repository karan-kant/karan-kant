/* Write a C program to read an expression and print the precedence of the operators present in it
using the stack data structure. */

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

int prec(char c)
{
    if(c == '(' || c == ')')
        return 0;
    else if(c == '^')
        return 3;
    else if(c == '*' || c == '/' || c == '%')
        return 2;
    else if(c == '-' || c == '+')
        return 1;
}

int main()
{
    printf("Enter the Expression\n");
    char arr[MAX];
    scanf("%s", arr);
    int len = strlen(arr);

    for(int i = 0; i < len; i++)
    {
        if(!isalnum(arr[i]))
        {
            printf("Precedence of %c is %d\n", arr[i], prec(arr[i]));
        }
        else 
            continue;
    }
}