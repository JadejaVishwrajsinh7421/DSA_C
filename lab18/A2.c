// 80. WAP to find the smallest and largest elements in the Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{

    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode *insertNode(struct TreeNode *root, int val)
{

    if (root == NULL)
    { // when first element enter

        return createNode(val);
    }

    if (val < root->data)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }

    return root;
}

void findMinMax(struct TreeNode* root){

    struct TreeNode* curr = root;

    while(curr->left != NULL){
        curr = curr->left;
    }

    printf("Min : %d\n",curr->data);
    
    curr = root;

    while(curr->right != NULL){
        curr = curr->right;
    }

    printf("Max : %d\n",curr->data);

}

void inOrderTraversal(struct TreeNode *root)
{

    if (root != NULL)
    {
        inOrderTraversal(root->left);
        
        printf("%d ", root->data);
        
        inOrderTraversal(root->right);        
       
    }
}

void main()
{

    struct TreeNode *root = NULL;

    root = insertNode(root, 40);
    root = insertNode(root, 20);
    root = insertNode(root, 60);
    root = insertNode(root, 70);
    root = insertNode(root, 35);
    root = insertNode(root, 18);

    inOrderTraversal(root);

    printf("\n");

    findMinMax(root);

}
