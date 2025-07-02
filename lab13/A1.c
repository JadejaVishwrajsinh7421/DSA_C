#include<stdio.h>
#include<stdlib.h>

// . Write a program to sort elements of a linked list

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

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

void sortList(){
       struct node *i, *j;
    int temp;

    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }
// using simple sorting by swap number technique
    for (i = first; i->link != NULL; i = i->link) {
        for (j = first; j->link != NULL; j = j->link) {
            if (j->info > j->link->info) {
                temp = j->info;
                j->info = j->link->info;
                j->link->info = temp;
            }
        }
    }
}
void main(){
        int choice;
    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Insert into Linked List 1\n");
        printf("2. Display Linked List before sorting\n");
        printf("3. sorting the list\n");
        printf("4. Display Linked List after sorting\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtLast();
            break;
        case 2:
            display();
            break;
        case 3:
            sortList();
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