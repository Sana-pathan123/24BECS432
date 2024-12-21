#include <stdio.h>
#include <stdlib.h>

// Structure for the node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Stack Operations

// Function to push an element onto the stack (insert at beginning)
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack\n", data);
}

// Function to pop an element from the stack (remove from beginning)
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to peek the top element of the stack
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Queue Operations

// Function to enqueue an element into the queue (insert at the end)
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        printf("%d enqueued to the queue\n", data);
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
    printf("%d enqueued to the queue\n", data);
}

// Function to dequeue an element from the queue (remove from beginning)
int dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        printf("Queue is now empty\n");
    }
    free(temp);
    return data;
}

// Function to get the front element of the queue
int front(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

// Function to print the stack
void printStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to print the queue
void printQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stackTop = NULL;  // Top of the stack
    struct Node* queueFront = NULL;  // Front of the queue
    struct Node* queueRear = NULL;   // Rear of the queue

    // Stack Operations
    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    printStack(stackTop);
    
    printf("Popped from stack: %d\n", pop(&stackTop));
    printf("Peek top of stack: %d\n", peek(stackTop));
    printStack(stackTop);

    // Queue Operations
    enqueue(&queueFront, &queueRear, 5);
    enqueue(&queueFront, &queueRear, 15);
    enqueue(&queueFront, &queueRear, 25);
    printQueue(queueFront);

    printf("Dequeued from queue: %d\n", dequeue(&queueFront));
    printf("Front of queue: %d\n", front(queueFront));
    printQueue(queueFront);

    return 0;
}
