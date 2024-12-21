#include <stdio.h>
#include <stdlib.h>

// Structure of the node
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

// Function to insert at the end
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

// Function to sort the linked list in ascending order (Bubble Sort)
void sortList(struct Node* head) {
    if (head == NULL) return;

    struct Node* i = head;
    struct Node* j;
    int temp;
    
    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    printf("Sorted List: ");
    printList(head);
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("Reversed List: ");
    printList(*head);
}

// Function to concatenate two linked lists
void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;
    printf("Concatenated List: ");
    printList(*head1);
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into list1
    insertAtEnd(&list1, 10);
    insertAtEnd(&list1, 20);
    insertAtEnd(&list1, 30);
    insertAtEnd(&list1, 40);
    insertAtEnd(&list1, 50);
    
    // Insert elements into list2
    insertAtEnd(&list2, 60);
    insertAtEnd(&list2, 70);

    // Print initial lists
    printf("Original List 1: ");
    printList(list1);
    printf("Original List 2: ");
    printList(list2);

    // Sort the first list
    sortList(list1);

    // Reverse the second list
    reverseList(&list2);

    // Concatenate list1 and list2
    concatenateLists(&list1, &list2);

    return 0;
}
