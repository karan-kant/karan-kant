
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct block{
    char name[10];
    int pos;
    int time;
}memblock;

int que[MAX];
int fron = 0;
int rear = -1;

void enque(int n)
{
    if(rear != MAX - 1)
    {
        rear = rear + 1;
        que[rear] = n;
        printf("SUCCESS\n");
    }
    else 
        printf("ERROR ENQUE\n");
    return;
}

int deque()
{
    if(fron <= rear)
    {
        int c = que[fron];
        fron = fron + 1;
        return c;
    }
    else
        printf("ERROR DEQUE\n");
        exit(101);
}

void display()
{
    if(fron <= rear)
    {
        for(int i = rear; i >= fron; i--)
        {
            printf(" %d ", que[i]);
        }
        printf("\n");
    }
    else 
        printf("ERROR DISPLAY\n");
    return;
}

int main()
{
    printf("Enter the Number of Programs alloted to CPU\n");
    int n, avg = 0;
    scanf("%d", &n);

    memblock *ptr;
    ptr = (memblock*)malloc(n*sizeof(memblock));

    printf("Enter the details of the Programs\n");

    for(int i = 0; i < n; i++)
    {
        printf("Enter the name of the program\t");
        scanf("%s", ptr[i].name);
        ptr[i].pos = i + 1;
        printf("Enter the Burst Time\t");
        scanf("%d", &ptr[i].time);
        enque(ptr[i].pos);
        printf("\n\n");
        avg = avg + ptr[i].time;
    }

    printf("Calculating Average Time..........\n\nAverage Time = %d\n", avg/n);
    int sum = 0;
    printf("Waiting time per program is.......\n\n");
    for(int i = 0; i < n; i++)
    {
        printf("Waiting time for %d program = %d\n", i + 1, sum);
        sum = sum + ptr[i].time;
    }

    free(ptr);
    return 0;
}
