// 76. Write a program to check whether the given two trees are same or not. 

#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insertNode(struct TreeNode* root) {
    int data;
    printf("Enter the data (-1 for no node): ");
    scanf("%d", &data);
    
    if (data == -1) {
        return NULL;
    }
    
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    printf("Enter data for inserting in left of %d\n", data);
    newNode->left = insertNode(newNode->left);
    
    printf("Enter data for inserting in right of %d\n", data);
    newNode->right = insertNode(newNode->right);

    printf("\n");

    return newNode;
}


void inOrderTraversal(struct TreeNode* root){

    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);        
    }

}

int isSame(struct TreeNode* root,struct TreeNode* root2){

    if(root == NULL || root2 == NULL){
        return root == root2;
    }

    return (root->data == root2->data) && isSame(root->left,root2->left) && isSame(root->right,root2->right);

}


void main(){

    struct TreeNode* root = NULL;
    struct TreeNode* root2 = NULL;

    printf("Enter root 1 : ");
    printf("\n");
    
    root = insertNode(root);   
    
    printf("Enter root 2 : ");
    printf("\n");

    root2 = insertNode(root2);     

    printf("root 1 : ");
    inOrderTraversal(root);
    printf("\n");
    
    printf("root 2 : ");
    inOrderTraversal(root2);
    printf("\n");

    if(isSame(root,root2)){

        printf("Both Are Same.");
    }
    else{
        
        printf("Not Same.");
    }


    
}