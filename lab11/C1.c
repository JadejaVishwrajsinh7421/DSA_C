#include <stdio.h>
#include <stdlib.h>
// duplicate elements from list

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

void deleteAtFirst()
{
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp = first;
    first = first->link;
    free(temp);
}

void deleteAtEnd()
{
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    if (first->link == NULL)
    {
        free(first);
        first = NULL;
        return;
    }

    struct node *temp = first;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }

    free(temp->link);
    temp->link = NULL;
}

void removeDuplicate()
{
    // idea 1
    //  also we can go first sort the whole list and 
    // then we have to delete the next element only if it is same to previous 
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *save1 ,*save2;
    save1 = first;


    while(save1->link!= NULL){
        save2 = save1;
        struct node *temp;
        while(save2->link!= NULL){
            if(save1->info ==  save2->link->info){
                temp = save2->link;
                save2->link = temp->link;
                 free(temp);
            }
            else{
                save2 = save2->link;
            }
        }
        save1 = save1->link;
    }

}

void main()
{
    int choice;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Display all nodes\n");
        printf("3. Delete first node\n");
        printf("4. Insert at end\n");
        printf("5. Delete last node\n");
        printf("6. duplicate remove");
        printf("7. Exit\n");
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
            deleteAtFirst();
            break;
        case 4:
            insertAtLast();
            break;
        case 5:
            deleteAtEnd();
            break;
            case 6:
            removeDuplicate();
             break;
        case 7 :
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}