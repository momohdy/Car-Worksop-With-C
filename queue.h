#ifndef QUEUE_H
#define QUEUE_H
#include "global.h"

typedef Customer QueueEntry;

typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAX_SIZE];
} Queue;

void createQueue(Queue *pq);
void append(QueueEntry e, Queue *pq);
void serve(Queue *pq , QueueEntry *e);
int queueEmpty(Queue *pq);
int queueFull(Queue *pq);
int queueSize(Queue *pq);
// THIRD REQUIREMENT : DISPLAY INFORMATION OF CUSTOMERS WITHOUT SERVING THEM 
// void displayCustomersInfo(Queue *pq);

#endif /*QUEUE_H*/
