#include <stdio.h>
#define MAX 4

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

void initializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}


int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow: Cannot insert %d. The queue is full.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
        printf("Inserted %d into the Circular queue.\n", value);
    }
}


void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: Cannot delete. The queue is empty.\n");
    } else {
        printf("Deleted %d from the queue.\n", q->items[q->front]);
        if (q->front == q->rear) {
           
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
    }
}


void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("The Circular queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        for (int i = q->front; ; i = (i + 1) % MAX) {
            printf("%d ", q->items[i]);
            if (i == q->rear) break;
        }
        printf("\n");
    }
}

int main() {
    CircularQueue q;
    initializeQueue(&q);
   
    display(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
   
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    dequeue(&q);
    display(&q);

    return 0;
}