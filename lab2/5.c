/* Using stack data structure, write a C program to check whether a given expression is having the
balanced parentheses or not. */

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
        printf("Stack Underflow 1\n");
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
        printf("Stack Overflow 1\n");
    exit(102);
}

char peek()
{
    if(top != -1)
        return stack[top];
    else 
        printf("Stack Undeflow 2\n");
    exit(103);
}

void getrid()
{
    top = top - 1;
}

int main()
{
    printf("Enter the Expresion to check if Brackets are balanced\n");
    char arr[MAX];
    scanf("%s", arr);
    int len = strlen(arr);
    int a = 0;

    for(int i = 0; i < len; i++)
    {
        if(isalnum(arr[i]))
                continue;
        else if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
        {
            push(arr[i]);
        }
        else if(arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            if(top == -1)
            {
                printf("Brackets are not Balanced\n");
                a = 1;
                // break;
                return 0;
            }
            if(peek() == '(')
            {
                if(arr[i] == ')')
                    {
                        getrid();
                        continue;
                    }
                else
                {
                    a = 1;
                    break;
                }
            }
            else if(peek() == '[')
            {
                if(arr[i] == ']')
                {
                    getrid();
                    continue;
                }
                else
                {
                    a = 1;
                    break;
                }
            }
            else if(peek() == '{')
            {
                if(arr[i] == '}')
                {
                    getrid();
                    continue;
                } 
                else
                {
                    a = 1;
                    break;
                }
            }    
        }
        else if(arr[i] == '-'|| arr[i] == '+'|| arr[i] == '*'|| arr[i] == '/')
            continue;
    }

    if(a == 1 || top != -1)
        printf("Brackets are not Balanced\n");
    else if(a == 0)
        printf("Brackets are Balanced\n");
    return 0;
}