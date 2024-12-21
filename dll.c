#include <stdio.h>
#include <stdlib.h>

// Structure for the node of the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a new node before a specific node
void insertBefore(struct Node** head, int value, int data) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }
    temp->prev = newNode;
}

// Function to delete a node based on a specific value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;  // If deleting the head node
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to display the contents of the doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Creating a doubly linked list with hardcoded values
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    // Display the list after creation
    printf("After creating the list:\n");
    display(head);

    // Insert 25 before the node with value 30
    insertBefore(&head, 30, 25);
    printf("After inserting 25 before 30:\n");
    display(head);

    // Delete the node with value 20
    deleteNode(&head, 20);
    printf("After deleting 20:\n");
    display(head);

    // Delete a non-existent node with value 50
    deleteNode(&head, 50);
    printf("After trying to delete 50 (non-existent):\n");
    display(head);

    return 0;
}
