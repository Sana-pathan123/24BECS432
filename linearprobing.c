#include <stdio.h>
#include <stdlib.h>

#define M 10  // Size of the hash table
#define N 5   // Number of employee records (example)

typedef struct {
    int empID;     // 4-digit unique employee ID (key)
    char name[30]; // Employee name
} Employee;

// Hash Table declaration
Employee *hashTable[M];

// Hash function: H(K) = K mod m
int hashFunction(int key) {
    return key % M;
}

// Linear probing to resolve collisions
int linearProbing(int key) {
    int index = hashFunction(key);
    int i = 0;

    // Search for an empty slot
    while (hashTable[(index + i) % M] != NULL) {
        i++;
    }

    return (index + i) % M;
}

// Insert an employee record into the hash table
void insert(Employee *emp) {
    int index = hashFunction(emp->empID);

    // If the slot is empty, insert directly
    if (hashTable[index] == NULL) {
        hashTable[index] = emp;
    } else {
        // Collision occurs, resolve using linear probing
        int newIndex = linearProbing(emp->empID);
        hashTable[newIndex] = emp;
    }
}

// Search for an employee by their ID
Employee* search(int empID) {
    int index = hashFunction(empID);
    int i = 0;

    // Linear probing search for the employee
    while (hashTable[(index + i) % M] != NULL) {
        if (hashTable[(index + i) % M]->empID == empID) {
            return hashTable[(index + i) % M];
        }
        i++;
    }

    return NULL;  // Employee not found
}

// Display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < M; i++) {
        if (hashTable[i] != NULL) {
            printf("Index %d: Employee ID: %d, Name: %s\n", i, hashTable[i]->empID, hashTable[i]->name);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    // Initialize hash table to NULL
    for (int i = 0; i < M; i++) {
        hashTable[i] = NULL;
    }

    // Employee records to insert
    Employee emp1 = {1234, "John Doe"};
    Employee emp2 = {2345, "Jane Smith"};
    Employee emp3 = {3456, "Alice Johnson"};
    Employee emp4 = {4567, "Bob Brown"};
    Employee emp5 = {5678, "Charlie Davis"};

    // Insert employees into the hash table
    insert(&emp1);
    insert(&emp2);
    insert(&emp3);
    insert(&emp4);
    insert(&emp5);

    // Display the hash table
    display();

    // Search for an employee
    int searchID = 3456;
    Employee *searchedEmp = search(searchID);
    if (searchedEmp != NULL) {
        printf("\nFound Employee ID %d: %s\n", searchedEmp->empID, searchedEmp->name);
    } else {
        printf("\nEmployee ID %d not found.\n", searchID);
    }

    return 0;
}
