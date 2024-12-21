#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototype for printList
void printList(struct Node* head);

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("After inserting %d at the beginning: ", data);
    printList(*head);
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("After inserting %d at the end: ", data);
    printList(*head);
}

// Insert at a specific position (Middle)
void insertAtMiddle(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("After inserting %d at position %d: ", data, position);
    printList(*head);
}

// Delete from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("After deleting from the beginning: ");
    printList(*head);
}

// Delete from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("After deleting from the end: ");
        printList(*head);
        return;
    }
    struct Node* temp = *head;
    while (temp->next && temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("After deleting from the end: ");
    printList(*head);
}

// Delete from a specific position (Middle)
void deleteFromMiddle(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (position == 0) {
        deleteFromBeginning(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    printf("After deleting from position %d: ", position);
    printList(*head);
}

int main() {
    struct Node* head = NULL;

    // Test cases to insert and delete
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtMiddle(&head, 15, 1);  // Insert at position 1 (middle)

    deleteFromBeginning(&head);  // Delete from beginning
    deleteFromEnd(&head);        // Delete from end
    deleteFromMiddle(&head, 0);  // Delete from position 0 (beginning)

    return 0;
}
