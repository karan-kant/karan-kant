
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct queue{
    int arr[MAX];
    int rear;
    int fron;
}kyu;

void enqr(kyu *q, int data)
{
    if(q->rear >= MAX - 1)
    {
        printf("Can't insert at rear\n\n");
        return;
    }
    else if(q->rear == -1)
        q->fron = 0;
    q->arr[++q->rear] = data;
}
void enqf(kyu *q, int data)
{
    if(q->fron < 1)
    {
        printf("Can't insert at front\n\n");
        return;
    }
    q->arr[--q->fron]=data;
}
int deqf(kyu *q)
{
    if(q->fron > q->rear)
    {
        printf("Queue is empty\n\n");
        return 0;
    }
    else if(q->fron == q->rear)
    {
        q->rear = -1;
        int temp = q->arr[q->fron];
        q->fron = -1;
        return temp;
    }
    return q->arr[q->fron++];
}
int deqr(kyu *q)
{
    if(q->rear < q->fron)
    {
        printf("Queue is empty\n\n");
        return 0;
    }
    else if(q->rear == q->fron)
    {
        q->fron = -1;
        int temp = q->arr[q->fron];
        q->rear = -1;
        return temp;
    }
    return q->arr[q->rear--];
}
void display(kyu *q)
{
    int temp = q->fron;
    printf("\nPrinting Queue...\n");
    if(q->fron==-1)
        return;
    while(temp!=q->rear)
        printf("%d  ", q->arr[temp++]);
    printf("%d  ", q->arr[temp]);
    printf("\n\n");
}

int main()
{
    kyu queue;
    queue.rear = -1;
    queue.fron = -1;

    while(1)
    {
        printf("1)Enqueue 2)Dequeue 3)Display 4)Exit \t");
        int n;
        scanf("%d", &n);

        switch(n)
        {
            case 1:
            printf("1)Front 2)Rear\t");
            int x;
            scanf("%d", &x);
            printf("Enter the Number:\t");
            int a;
            scanf("%d", &a);
            if(x == 1)
                enqf(&queue, a);
            else if(x == 2)
                enqr(&queue, a);
            break;

            case 2:
            printf("1)Front 2)Rear\t");
            scanf("%d", &x);
            if(x == 1)
                a = deqf(&queue);
            else if(x == 2)
                a == deqr(&queue);
            printf("%d Dequeued\n", a);
            break;

            case 3:
            display(&queue);
            break;

            case 4:
            return 0;

            default:
            printf("Invalid Input\n");
        }
    }
}
