#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
    int front;
    int rear;
    int array[MAX_SIZE];

};

void initialize_queue(struct Queue* queue)
{
    queue->front=-1;
    queue->rear=-1;
}

int isEmpty(struct Queue* queue)
{
    return queue->front=-1;
}

int isFull(struct Queue* queue)
{
    return queue->rear == MAX_SIZE-1;
}

void enqueue(struct Queue* queue,int data)
{
    if (isFull(queue))
    {
        printf("Queue overflow\n");
        return;
    }
    if(isEmpty(queue)==1)
    {
        queue->front=0;
    }
    queue->array[++queue->rear] = data;
    printf("%d enqueued to queue\n",data);

}

int dequeue(struct Queue* queue)
{
    if(isEmpty(queue)==1)
    {
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue->array[queue->front];
    if(queue->front==queue->rear)
    {
        queue->front==queue->rear-1;
    }
    else
    {
        queue->front++;
    }
    return data;
}

int peek(struct Queue* queue) 
{
    if (isEmpty(queue)==1) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->front];
}

int main() 
{
    struct Queue queue; 

    initialize_queue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("%d dequeued from queue\n",dequeue(&queue));

    printf("Front element: %d\n", peek(&queue));

    return 0;
}



