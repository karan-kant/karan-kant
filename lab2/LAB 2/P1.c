
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
        return 4;
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
    char pri[MAX];
    int a = 0;

    int len = strlen(arr);

    for(int i = 0; i < len; i++)
    {
        if(isalnum(arr[i]))
        {
            pri[a] = arr[i];
            a = a + 1;
        }
        else if(top == -1 || stack[top] == '(')
        {
            push(arr[i]);
        }
        else if(arr[i] == '(')
        {
            push(arr[i]);
        }
        else if(arr[i] == ')')
        {
            for(; stack[top] != '('; )
            {
                pri[a] = pop();
                a = a + 1;
            }
        }
        else if(prec(arr[i]) > prec(stack[top]))
        {
            push(arr[i]);
        }
        else if(prec(arr[i]) == prec(stack[top]))
        {
            pri[a] = pop();
            a = a + 1;
            push(arr[i]);
        }
        else if(prec(arr[i]) < prec(stack[top]))
        {
            for(; prec(arr[i]) < prec(stack[top]); )
            {
                pri[a] = pop();
                a = a + 1;
            }
            push(arr[i]);
        }
    }

    for(int i = top; i > -1; i--)
    {
        if(prec(stack[top]) != 4)
        {
            pri[a] = pop();
            a = a + 1;
        }
    }
    pri[a] = '\0';

    printf("Postfix Expression is\n%s\n", pri);
    return 0;
}
