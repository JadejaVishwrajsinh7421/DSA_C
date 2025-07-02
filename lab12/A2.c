#include <stdio.h>
#include <stdlib.h>
//   Write a program to reverse a linked list. Write a program to reverse a linked list.

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

void reverseList()
{
    struct node *current;
    current = first;

    struct node *next = NULL;
    struct node *prev = NULL;
   
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    first = prev;
    printf("the reverse list prog is done ");
    return;
}

void display() {
    if (first == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp = first;
    printf("The nodes are:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Insert into Linked List 1\n");
        printf("2. Display Original Linked List\n");
        printf("3. reverse the list");
        printf("4. Display reverse Linked List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtFirst();
            break;
        case 2:
            display();
            break;
        case 3:
            reverseList();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}