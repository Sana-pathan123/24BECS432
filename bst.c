#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Insert in the left subtree if the data is less than root
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // Insert in the right subtree if the data is greater than root
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// In-order traversal (Left, Root, Right)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the tree elements using In-order, Pre-order, and Post-order
void display(struct Node* root) {
    printf("\nIn-order Traversal: ");
    inOrder(root);

    printf("\nPre-order Traversal: ");
    preOrder(root);

    printf("\nPost-order Traversal: ");
    postOrder(root);
}

// Main function
int main() {
    struct Node* root = NULL;
    
    // Construct the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display the elements in the tree
    display(root);

    return 0;
}
