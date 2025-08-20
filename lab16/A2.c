#include<stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *createNode(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// this os not bst we apply input manual


struct node *Congruenttree(){}
void main(){
    struct node *root = NULL;
    
}