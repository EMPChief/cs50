#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Definerer kø-strukturen
typedef struct
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Initialiserer køen
void initialize(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Sjekker om køen er full
int isFull(Queue *q)
{
    return (q->rear == MAX_SIZE - 1);
}

// Sjekker om køen er tom
int isEmpty(Queue *q)
{
    return (q->front == -1);
}

// Legger til et element i køen
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Køen er full!\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Lagt til i kø: %d\n", value);
}

// Fjerner et element fra køen
int dequeue(Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Køen er tom!\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        initialize(q);
    }
    printf("Fjernet fra kø: %d\n", item);
    return item;
}

int main()
{
    Queue q;
    initialize(&q);

    // Tester køoperasjoner
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    dequeue(&q);
    dequeue(&q);

    return 0;
}