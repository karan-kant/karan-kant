#include <stdio.h>
#include <stdlib.h>
#include "queues.h"

void BFS(int adjmat[][8], int index, int visited[], queue *q)
{
    if(visited[index])
    {
        dequeue(q);
        if(q -> front != -1 && q -> rear != -1)
        {
            BFS(adjmat, peek(q), visited, q);
            return;
        }
        else return;
    }
    for(int i = 0; i < 8; i++) if(adjmat[index][i] && !visited[i]) enqueue(q, i);
    visited[dequeue(q)] = 1;
    printf("%c ", index + 'A');
    if(q -> front != -1 && q -> rear != -1) BFS(adjmat, peek(q), visited, q);
}

void DFS(int adjmat[][8], int index, int visited[])
{
    printf("%c ", index + 'A');
    for(int i = 0; i < 8; i++) 
    {
        if(adjmat[index][i] && !visited[i]) 
        {
            visited[i] = 1;
            DFS(adjmat, i, visited);
        }
    }
}

int main()
{
    int adjmat[8][8] = {{0,1,1,1,0,0,0,0}, {0,0,1,0,1,0,0,0}, {0,0,0,0,1,0,0,0}, {0,0,1,0,0,1,0,0}, {1,0,0,0,0,0,0,0}, {0,0,1,0,0,0,0,0}, {0,0,0,1,0,1,0,1}, {0,0,1,0,0,0,0,0}};

    int visited[8] = {0};

    queue q;
    q.front = -1;
    q.rear = -1;
    enqueue(&q, 6);

    BFS(adjmat, 6, visited, &q);
    printf("\n");

    for(int i = 0; i < 8; i++) visited[i] = 0;
    
    visited[6] = 1;
    DFS(adjmat, 6, visited);
    printf("\n");

    return 0;
}