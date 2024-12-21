#include <stdio.h>
#define MAX 5 // Maximum size of the queue

// Queue structure
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to insert an element into the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow: Cannot insert %d. The queue is full.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; // Initialize front when first element is added
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Function to delete an element from the queue
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: Cannot delete. The queue is empty.\n");
    } else {
        printf("Deleted %d from the queue.\n", q->items[q->front]);
        q->front++;
    }
}

// Function to display the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    display(&q);
   
    dequeue(&q);
    display(&q);
    dequeue(&q);
    dequeue(&q);


    enqueue(&q,30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // This should trigger overflow
    display(&q);
   
    return 0;
}