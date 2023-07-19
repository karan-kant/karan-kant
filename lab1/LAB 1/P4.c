#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

int isEmpty()
{
    if(top == -1)
        return 0;
    else    
        return 1;
}

int isFull()
{
    if(top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(int a)
{
    if(!isFull())
    {
        top = top + 1;
        stack[top] = a;
        return;
    }
    else 
        printf("Stack Overflow\n");
        return;
}

int pop()
{
    if(!isEmpty())
    {
        int c = stack[top];
        top = top - 1;
        return c;
    }
    else 
        printf("Stack Underflow\n");
        exit(101);
}

int sum()
{
    if(isEmpty())
    {
        int s = 0;
        for(int i = 4; i > -1; i--)
        {
            // printf("%d \n", stack[i]);
            s = s + stack[i];
        }
        return s;
    }
    else    
    {
        printf("Stack is Empty. Sum is incalculatable\n");
        printf("Terminating program\n");
        exit(102);
    }
}

int avg()
{
    if(isEmpty())
    {
        int s = 0;
        for(int i = 4; i > -1; i--)
        {
            s = s + stack[i];
        }
        int av = (float)s/5;
        return av;
    }
    else 
    {
        printf("Stack is Empty. Avarage is incalculatable\n");
        printf("Terminating program\n");
        exit(103);
    }
}

int mini()
{
    if(isEmpty())
    {
        int arr[5];
        for(int i = 0; i < 5; i++)
        {
            arr[i] = stack[i];
        }

        /*for(int i = 0; i < 5; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");*/
        // used for debugging

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(arr[j] > arr[j + 1])
                    continue;
                else 
                {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        /*for(int i = 0; i < 5; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");*/
        // used for debugging

        return arr[4];
    }
    else 
    {
        printf("Stack is Empty. Minimum not found\n");
        printf("Terminating Program\n");
        exit(105);
    }
}

int maxi()
{
    if(isEmpty())
    {
        int arr[5];
        for(int i = 0; i < 5; i++)
        {
            arr[i] = stack[i];
        }

        /*for(int i = 0; i < 5; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");*/
        // used for debugging

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(arr[j] > arr[j + 1])
                    continue;
                else 
                {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        /*for(int i = 0; i < 5; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");*/
        // used for debugging

        return arr[0];
    }
    else 
    {
        printf("Stack is Empty. Maximum not found\n");
        printf("Terminating Program\n");
        exit(105);
    }
}

void display()
{
    if(isEmpty())
    {
        for(int i = top; i > -1; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    else 
    {
        printf("Stack is Empty. Displaying Impossible\n");
        printf("Terminating Program\n");
        exit(106);
    }
}

int main()
{
    printf("Enter the 5 elements into the stack\n");

    for(int i = 0; i < 5; i++)
    {
        int a;
        scanf(" %d", &a);
        push(a);
    }

    push(sum());
    push(avg());
    push(mini());
    push(maxi());

    display();

    printf("Program Completed\n");
    return 0;
}
