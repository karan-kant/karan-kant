#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int tops = -1;
int topt = -1;
int stack[MAX];
int tmtck[MAX];

void pushs(int a)
{
    if(tops != MAX - 1)
    {
        tops = tops + 1;
        stack[tops] = a;
        return;
    }
    else
        printf("Stack Overflow 1\nTerminate\n");
    exit(101);
}

int pops()
{
    if(tops != -1)
    {
        int a = stack[tops];
        tops = tops - 1;
        return a;
    }
    else
        printf("Stack Underflow 1\nTerminate\n");
    exit(102);
}

void pusht(int a)
{
    if(topt != MAX - 1)
    {
        topt = topt + 1;
        tmtck[topt] = a;
        return;
    }
    else
        printf("Temporary Stack Overflow 1\n Terminate\n");
    exit(103);
}

int popt()
{
    if(topt != -1)
    {
        int a = tmtck[topt];
        topt = topt - 1;
        return a;
    }
    else
        printf("Temporary Stack Underflow 1\nTerminate\n");
    exit(104);
}

void display()
{
    for(int i = tops; i > -1; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return;
}

int main()
{
    printf("Enter the number of Elements\t");
    int x;
    scanf("%d", &x);
    int a[x];
    printf("Enter the Elements\n");

    for(int i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < x; i++)
    {
        if(tops == -1)
            pushs(a[i]);
        else if(stack[tops] > a[i])
        {
            for(; stack[tops] > a[i];)
            {
                pusht(pops());
            }
            pushs(a[i]);
            for(; topt != -1;)
            {
                pushs(popt());
            }
        }
        else if(stack[tops] == a[i])
            pushs(a[i]);
        else if(stack[tops] < a[i])
            pushs(a[i]);
    }

    printf("Sorted array is\n");
    /*for(int i = 0; i < x; i++)
    {
        printf("%d ", pops());
    }*/
    display();
    return 0;
}