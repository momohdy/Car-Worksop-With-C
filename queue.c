#include <stdio.h>
#include "queue.h"

void createQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

// APPEND
void append(QueueEntry e, Queue *pq)
{
    pq->rear = (pq->rear + 1) % MAX_SIZE;
    pq->entry[pq->rear] = e;
    pq->size++;
}

// SERVE
void serve(Queue *pq, QueueEntry *pe)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAX_SIZE;
    pq->size--;
}

int queueEmpty(Queue *pq)
{
    // return pq->front == pq->rear -1 ;
    return !(pq->size);
}
int queueFull(Queue *pq)
{
    // return pq->front == pq->rear -1 ;
    return pq->size == 6;
}

int queueSize(Queue *pq)
{
    return pq->size;
}

// void displayCustomersInfo(Queue *pq)
// {
//     int x = 0;
//     while (!(x > pq->rear))
//     {
//         printf("%d\t", pq->entry[x]);
//         x = (x + 1) % MAX_SIZE;
//     }
//     printf("\n");
// }
