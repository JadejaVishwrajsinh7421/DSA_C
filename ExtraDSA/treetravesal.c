#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);         // Visit left subtree
        printf("%d ", root->data);            // Visit current node
        inorderTraversal(root->right);        // Visit right subtree
    }
}

// Main function
int main() {
    // Example binary tree:
    //         8
    //        / \
    //       3   10
    //      / \    \
    //     1   6    14

    struct Node* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->right->right = createNode(14);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
