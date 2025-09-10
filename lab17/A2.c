// 78. Given a binary tree, determine if it is height-balanced (A height-balanced binary 
// tree is a binary tree in which the depth of the two subtrees of every node never 
// differs by more than one). 

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

int checkHeight(struct TreeNode* root){     //O(n)
    
    if(root == NULL){
        return 0;
    }
    
    int leftHeight = checkHeight(root->left);       //left subtree unbalanced
    if(leftHeight == -1){
        return -1;
    }
    
    int rightHeight = checkHeight(root->right);      //right subtree unbalanced
    if(rightHeight == -1){
        return -1;
    }

    if(abs(leftHeight - rightHeight) > 1){          // curr Node unbalanced
        return -1;
    }
    
    return ((leftHeight > rightHeight) ? leftHeight : rightHeight ) + 1;   // max hoi te return and + 1
    
}

bool isHeightBalance(struct TreeNode* root){

  return checkHeight(root) != -1;
        
}

void main(){

    struct TreeNode* root = NULL;
    
    printf("Enter root 1 : ");
    printf("\n");
    
    root = insertNode(root);         

    printf("root 1 : ");
    inOrderTraversal(root);
    printf("\n");        

    if(isHeightBalance(root)){
        printf("This Tree Is Balanced (TRUE)\n");
    }
    else{
        printf("This Tree Is Not Balanced (FALSE)\n");
    }
}