#include <stdio.h>
#include <stdlib.h>

// WAP to swap Kth node from beginning with Kth node from end in a singly linked list.

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

void insertAtFirst()
{
    int x;
    printf("Enter number to insert at front: ");
    scanf("%d", &x);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
    (*count++);
    
}

void swapData1()
{
    int i = 0;
    printf("enter the kth number from beginning ");
    scanf("%d", &i);
    struct node *save1 = first;
    for(int i=1;i<k;i++){
        save1=save1->link;
    }
    struct node *save2 = first;
    for(int i=1;i<*(count)-k+1)
//    baaki che



}
       


void main()
{
    int count =0;
}