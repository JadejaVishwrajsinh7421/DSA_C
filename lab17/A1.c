// 76. Write a program to check whether the given two trees are same or not. 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool isSymmentricHelp(struct TreeNode* left , struct TreeNode* right){

    if(left == NULL || right == NULL){
        return left == right;
    }
    else if(left->data != right->data){
        return false;
    }
    
    return isSymmentricHelp(left->left,right->right) && isSymmentricHelp(left->right,right->left);

}

bool isSymmentric(struct TreeNode* root){

   return root == NULL || isSymmentricHelp(root->left,root->right);
}


void main(){

    struct TreeNode* root = NULL;
    
    printf("Enter root 1 : ");
    printf("\n");
    
    root = insertNode(root);         

    printf("root 1 : ");
    inOrderTraversal(root);
    printf("\n");        

    if(isSymmentric(root)){

        printf("Tree Is Symmentric.");
    }
    else{
        
        printf("Tree Is Not Symmentric.");
    }
}