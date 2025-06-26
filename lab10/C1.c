#include <stdio.h>
#include <stdlib.h>

// Write a program to remove the duplicates nodes from given sorted Linked List
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
}

void insertAtLast()
{
    int x;
    printf("Enter number to insert at end: ");
    scanf("%d", &x);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL)
    {
        first = newNode;
        return;
    }

    struct node *temp = first;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newNode;
}

void display()
{
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp = first;
    printf("The nodes are:\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

// user already give sorted array 

void duplicateNodeDelete()
{
    if (first == NULL)
    {
        printf("linked lists is empty\n");
        return;
    }
    struct node *temp = first;
    while (temp->link != NULL)
    {
        if (temp->info == temp->link->info)
        {
            struct node *dupl = temp->link;
            temp->link = dupl->link;
            free(dupl);
        }
        else
        {
            temp = temp->link;
        }
    }
}

//for your sort of linked list
// void sortLinkedList() {
//     struct node *i, *j;
//     int temp;

//     if (first == NULL) {
//         printf("Linked list is empty\n");
//         return;
//     }

//     for (i = first; i->link != NULL; i = i->link) {
//         for (j = first; j->link != NULL; j = j->link) {
//             if (j->info > j->link->info) {
//                 temp = j->info;
//                 j->info = j->link->info;
//                 j->link->info = temp;
//             }
//         }
//     }
// }

void main()

{
    while (1)
    {
        int choice = 0;
        printf("\n--- Menu ---\n");
        printf("give a sorted linked list\n");
        printf("1. Insert into  first in Linked List\n");
        printf("2. Insert into  last in Linked List\n");
        printf("3. Display Linked list\n");
        printf("4.duplicate node delete\n");
        printf("5. Display Linked list after updation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtFirst();
            break;
        case 2:
            insertAtLast();
            break;
        case 3:
            display();
            break;
        case 4:
            duplicateNodeDelete();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    printf("Exiting program.\n");
}
