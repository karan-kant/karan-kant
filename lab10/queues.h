#ifndef _INT_QUEUE_H_
#define _INT_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#define MAX 64

typedef struct 
{
    int qu[MAX];
    int front;
    int rear;
}queue;

int size(queue *q)
{
    if(q -> front == -1 && q -> rear == -1)
    {
        return 0;
    }
    else
    {
        return (((q -> rear) - (q -> front)) + 1);
    }
}

int peek(queue *q)
{
    if(q -> front == -1 && q -> rear == -1)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    else
    {
        return q -> qu[q -> front];
    }
}

void enqueue(queue *q, int n)
{
    if(q -> rear == MAX - 1)
    {
        if(q -> front == 0)
        {
            printf("Queue Overflow\n");
            exit(1);
        }
        else
        {
            int i = q -> front;
            for(int j = 0; j < size(q); j++)
            {
                q -> qu[j] = q -> qu[i + j];
            }
            q -> rear = size(q) - 1;
            q -> front = 0;
            q -> qu[++(q -> rear)] = n;
        }
    }
    else if(q -> front == -1 && q -> rear == -1)
    {
        (q -> front)++;
        q -> qu[++(q -> rear)] = n;
    }
    else
    {
        q -> qu[++(q -> rear)] = n;
    }
}

int dequeue(queue *q)
{
    if(q -> front == -1 && q -> rear == -1)
    {
        printf("Queue Underflow\n");
        exit(2);
    }
    else if (q -> front == q -> rear)
    {
        int val = peek(q);
        q -> front = -1;
        q -> rear = -1;
        return val;
    }
    else
    {
        return (q -> qu[(q -> front)++]);
    }
}

#endif