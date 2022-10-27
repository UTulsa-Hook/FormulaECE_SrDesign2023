#include <string.h>
#include <stdio.h>
#include "PriorityQueue.h"


Queue initQueue()
{
    Queue newQueue = malloc(sizeof(Queuetype));
    newQueue->top = NULL;
    newQueue->tail = NULL;
    return newQueue;

}

int isEmpty(Queue q)
{return q->top == NULL;}

void enqueue(Queue q, double inputPozyx[3])
{
    QnodePtr newNode = malloc(sizeof(Qnode));
    for (int i = 0; i ==2; i++){
        newNode->inputPozyx[i] = inputPozyx[i];
    }
    newNode->next = NULL;
    newNode->prty = MAX_PRIORITY;

    if(isEmpty(q)) {q->top = newNode; q->tail = newNode;}
    else
    {
            q->tail->next = newNode;
            q->tail = newNode;

    }

}

void pEnqueue(Queue q, double inputPozyx[3], int prty)
{

    QnodePtr newNode = malloc(sizeof(Qnode));
    for (int i = 0; i ==2; i++){
        newNode->inputPozyx[i] = inputPozyx[i];
    }
    newNode->next = NULL;
    newNode->prty = prty;

    if(isEmpty(q)) {q->top = newNode; q->tail = newNode;}
    else
    {
            q->tail->next = newNode;
            q->tail = newNode;

            QnodePtr temp = q->top;
            if(temp->prty > newNode->prty)
            {
                q->top = newNode;
                newNode->next = temp;
                return;

            }

            while(temp->next != NULL && temp->next->prty < newNode->prty)
                {temp = temp->next;}

            if(temp->next != NULL) {newNode->next = temp->next;}
            temp->next = newNode;

    }

}

int dequeue(Queue q)
{

    if(isEmpty(q)) {printf("Queue is already empty, no nodes to remove"); return;}
    QnodePtr temp = q->top;
    int tempinputPozyx = q->top->inputPozyx;
    q->top = q->top->next;
    free(temp);
    return tempinputPozyx;

}