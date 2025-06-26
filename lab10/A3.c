#include <stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;
void main()

{
    // Write a program to implement a node structure for singly linked list. Read the
    // data in a node, print the node

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data for the node: ");
    scanf("%d", &newNode->info);

    newNode->link = NULL;

    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *temp = first;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
    printf("Node created with data: %d\n", newNode->info);
    printf("Node link: %p\n", newNode->link);
}