
#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef int unit;


typedef struct{
    int cq[MAX];
    unit front;
    unit rear;
}cqueue;

void enqueue(cqueue *q, int n)
{
    if(q->front == -1 && q->rear == -1)
    {
        q->front++;
        q->cq[++(q->rear)] = n;
    }
    else if(q->front == q->rear + 1)
    {
        printf("Circular Queue Overflow\n");
        exit(100);
    }
    else if (q->rear == MAX - 1 && q->front == 0)
    {
        printf("Circular Queue Overflow\n");
        exit(101);
    }
    
    else if(q->rear == MAX - 1 && q->front != 0)
    {
        q->rear = 0;
        q->cq[q->rear] = n;
    }
    else
        q->cq[++(q->rear)] = n;
}
int dequeue(cqueue *q)
{
    if(q->front == -1 && q->rear == -1)
    {
        printf("Circular Queue Underflow\n");
        exit(102);
    }
    else if(q->front == q->rear)
    {
        int val = q->cq[q->front];
        q->front = -1;
        q->rear = -1;
        return val;
    }
    else if(q->front == MAX - 1)
    {
        int val = q->cq[q->front];
        q->front = 0;
        return val;
    }
    else
        return q->cq[(q->front)++];
}

void display(cqueue *q)
{
    if(q -> front <= q -> rear)
    {
        for(int i = q -> front; i <= q -> rear; i++)
            printf("%d\t", q -> cq[i]);    
        printf("\n");
    }
    else
    {
        for(int i = q -> front; i < MAX; i++)
            printf("%d\t", q -> cq[i]);
        for(int i = 0; i <= q -> rear; i++)
            printf("%d\t", q -> cq[i]);
        printf("\n");
    }
}

int main()
{
    int n;
    cqueue kyu;

    kyu.front = -1;
    kyu.rear = -1;

    do
    {
        printf("1)Enqueue 2)Dequeue 3)Display 4)Exit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1 :
                int m;
                printf("Enter the value to enqueue\n");
                scanf("%d", &m);
                enqueue(&kyu, m);
                printf("%d was enqueued\n", m);
                break;
            case 2 :
                printf("%d was dequeued\n", dequeue(&kyu));
                break;
            case 3 :
                display(&kyu);
                break;
            case 4 :
                return 0;
                break;
            default :
                printf("Invalid input\n");
                break;
        }
    }
    while(n != 4);
    
    return 0;
}
