#include <stdio.h>
#include <stdlib.h>

//  menu driven for circular lists



struct node
{
    int info;
    struct node *link;
};


struct node *first = NULL;
struct node *last = NULL;

void insertAtFirst()
{
    int x;
    printf("Enter number to insert at front: ");
    scanf("%d", &x);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    if (first == NULL)
    {
        first = last = newNode;
        return;
    }
    first = newNode;
    last->link = first;
}

void insertAtEnd()
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
        first = last = newNode;
        return;
    }
    newNode->link = first;
    last->link = newNode;
   
    last = newNode;
}

void deleteAtPos()
{
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    int pos, i = 1;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (pos == 1)
    {

        struct node *temp = first;
        first = first->link;
        last->link = first;
       
        
    }

    struct node *temp = first;
    struct node *prev = NULL;

    while (temp != last && i < pos)
    {
        prev = temp;
        temp = temp->link;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }
    

    prev->link = temp->link;
    last->link = first;
    free(temp);
}

void display() {
    if (first == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp = first;
    printf("The nodes are:\n");
    // while (temp != NULL ) {
        
    //     printf("%d -> ", temp->info);
    //     temp = temp->link;
    //     if(temp == first ){
    //         break;
    //     }
    // }
    do
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    } while (temp != first);
    
    printf("NULL\n");
}

void main()
{
    int choice;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Display all nodes\n");
        printf("4. Insert at end\n");
        printf("4. Delete node from specific position\n");

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
            insertAtEnd();
            break;
        case 4:
            deleteAtPos();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}