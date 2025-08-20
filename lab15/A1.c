#include <stdio.h>
#include <stdlib.h>
//  Write a menu driven program to implement following operations on the doubly linked list.
// Insert a node at the front of the linked list.
// • Delete a node from specified position.
// • Insert a node at the end of the linked list.
// • Display all nodes

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *L = NULL;
struct node *R = NULL;

void insertAtFirst()
{
    int x;
    printf("Enter number to insert at front: ");
    scanf("%d", &x);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (R == NULL)
    {
        newNode->lptr = NULL;
        newNode->rptr = NULL;
        L = R = newNode;
        return;
    }
    newNode->lptr = NULL;
    newNode->rptr = L;
    L->lptr = newNode;
    L = newNode;
}

void insertAtEnd()
{

    int x;
    printf("Enter number to insert at end: ");
    scanf("%d", &x);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (R == NULL)
    {
        newNode->lptr = NULL;
        newNode->rptr = NULL;
        L = R = newNode;
        return;
    }
    newNode->lptr = R;
    newNode->rptr = NULL;
    R->rptr = newNode;
    R = newNode;
}

void deleteAtPos()
{
    int pos, i = 1;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (L == NULL)
    {
        printf("Underflow: List is empty.\n");
        return;
    }

    struct node *temp = L;

    // Del first
    if (pos == 1)
    {
        if (L == R) // only single list
        {
            free(L);
            L = R = NULL;
        }
        else
        {
            L = L->rptr;
            free(temp);
            L->lptr = NULL;
        }
        return;
    }

    while (temp != NULL && i < pos)
    {
        temp = temp->rptr;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }
    // deleting last node
    if (temp == R)
    {
        R = R->lptr;
        R->rptr = NULL;
    }
    else
    {
        temp->lptr->rptr = temp->rptr;
        temp->rptr->lptr = temp->lptr;
    }

    free(temp);
}

void display()
{
    struct node *old = L;
    printf("the nodes are:\n");
    while (old->rptr != NULL)
    {
        printf("%d <-> ", old->info);
        old = old->rptr;
    }
    printf("NULL\n");
}

// void reverseDisplay()
// {
//     struct node *temp = R;
//     if (temp == NULL)
//     {
//         printf("List is empty.\n");
//         return;
//     }

//     printf("The nodes in reverse are:\n");
//     while (temp != NULL)
//     {
//         printf("%d -> ", temp->info);
//         temp = temp->lptr;
//     }
//     printf("NULL\n");
// }


// void searchNode()
// {
//     int value, pos = 1, found = 0;
//     printf("Enter value to search: ");
//     scanf("%d", &value);

//     struct node *temp = L;
//     while (temp != NULL)
//     {
//         if (temp->info == value)
//         {
//             printf("Value %d found at position %d\n", value, pos);
//             found = 1;
//         }
//         temp = temp->rptr;
//         pos++;
//     }

//     if (!found)
//         printf("Value %d not found in the list.\n", value);
// }

// 

// void deleteDuplicates()
// {
//     if (L == NULL)
//     {
//         printf("List is empty.\n");
//         return;
//     }

//     struct node *current = L;
//     while (current != NULL)
//     {
//         struct node *runner = current->rptr;
//         while (runner != NULL)
//         {
//             if (runner->info == current->info)
//             {
//                 struct node *toDelete = runner;
//                 runner = runner->rptr;

//                 if (toDelete == R)
//                 {
//                     R = toDelete->lptr;
//                     R->rptr = NULL;
//                 }
//                 else
//                 {
//                     toDelete->lptr->rptr = toDelete->rptr;
//                     toDelete->rptr->lptr = toDelete->lptr;
//                 }

//                 free(toDelete);
//             }
//             else
//             {
//                 runner = runner->rptr;
//             }
//         }
//         current = current->rptr;
//     }

//     printf("All duplicate values deleted.\n");
// }


void main()
{
    int choice;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Insert at front\n");
        printf("2.Insert at end\n");
        printf("3.. Delete node from specific position\n");
        printf("4. Display all nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtFirst();
            break;

        case 2:
            insertAtEnd();
            break;
        case 3:
            deleteAtPos();
            break;

        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}

// void insertSorted()
// {
//     int x;
//     printf("Enter value to insert in sorted order: ");
//     scanf("%d", &x);

//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->info = x;
//     newNode->lptr = newNode->rptr = NULL;

//     // Case 1: Empty list
//     if (L == NULL)
//     {
//         L = R = newNode;
//         return;
//     }

//     // Case 2: Insert at front
//     if (x < L->info)
//     {
//         newNode->rptr = L;
//         L->lptr = newNode;
//         L = newNode;
//         return;
//     }

//     // Traverse to find position
//     struct node *temp = L;
//     while (temp->rptr != NULL && temp->rptr->info < x)
//     {
//         temp = temp->rptr;
//     }

//     // Case 3: Insert at end
//     if (temp->rptr == NULL)
//     {
//         temp->rptr = newNode;
//         newNode->lptr = temp;
//         R = newNode;
//     }
//     else
//     {
//         newNode->rptr = temp->rptr;
//         newNode->lptr = temp;
//         temp->rptr->lptr = newNode;
//         temp->rptr = newNode;
//     }
// }
