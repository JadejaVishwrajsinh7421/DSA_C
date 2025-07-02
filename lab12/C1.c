#include <stdio.h>
#include <stdlib.h>

// WAP to swap Kth node from beginning with Kth node from end in a singly linked list.

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

int count = 0;
void insertAtFirst()
{
    int x;
    printf("Enter number to insert at front: ");
    scanf("%d", &x);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
    count++;
}

// void swapData1()
// {
//     int i = 0;
//     printf("enter the kth number from beginning to change to the end");
//     scanf("%d", &i);
//     struct node *save = first;
//     while (save->link != NULL)
//     {
//         if (i == (count - i + 1))
//         {
//             save-
//             break;
//         }
//         save= save->link;
//         i++;
//     }
// }

void main()
{
}