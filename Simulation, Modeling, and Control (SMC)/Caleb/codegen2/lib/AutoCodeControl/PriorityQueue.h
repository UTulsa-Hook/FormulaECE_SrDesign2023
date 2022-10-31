#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIORITY 20;

typedef struct Qnode
{

  double inputPozyx[3];
  struct Qnode *next;
  int prty;

} Qnode, *QnodePtr;

typedef struct Queue
{

    QnodePtr top;
    QnodePtr tail;

} Queuetype, *Queue;

Queue initQueue();
int isEmpty(Queue q);
void enqueue(Queue q, double inputPozyx[3]);
void pEnqueue(Queue q, double inputPozyx[3], int prty);
int dequeue(Queue q);

#endif //PRIORITYQUEUEH