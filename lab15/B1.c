// 73. WAP to delete alternate nodes of a doubly linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *rptr;
    struct Node *lptr;
};

struct Node *insertAtFirst(struct Node *first, int x)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->rptr = first;

    if (first == NULL)
    {
        newNode->lptr = NULL;
        first = newNode;
        return first;
    }

    first->lptr = newNode;
    first = newNode;
    return first;
}

struct Node *insertAtLast(struct Node *first, int x)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->rptr = NULL;

    if (first == NULL)
    {
        first = newNode;
        return first;
    }

    struct Node *curr = first;

    while (curr->rptr != NULL)
    {

        curr = curr->rptr;
    }

    curr->rptr = newNode;
    newNode->lptr = curr;

    return first;
}

void display(struct Node *first)
{

    struct Node *curr = first;

    if (curr == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    while (curr != NULL)
    {
        printf("%d -> ", curr->info);
        curr = curr->rptr;
    }
    printf("NULL\n");
}

struct Node *deleteNodeFromPosition(int n, struct Node *first)
{

    struct Node *curr = first;

    if (first == NULL)
    {
        printf("List Is Empty");

        return NULL;
    }

    if (n < 1)
    {
        printf("Invalid position\n");
        return first;
    }

    if (n == 1)
    { // First Node Ne Delete Karva
        struct Node *temp = first;
        first = first->rptr;
        first->lptr = NULL;
        free(temp);

        return first;
    }

    int i = 1;

    struct Node *temp2; // curr->rptr ne free karva mate apde temp variable lidhel che

    while (curr->rptr != NULL)
    {

        if (i == (n - 1))
        {
            break;
        }

        curr = curr->rptr;
        i++;
    }

    temp2 = curr->rptr;

    curr->rptr = curr->rptr->rptr;
    curr->rptr->rptr->lptr = curr;

    free(temp2);

    return first;
}

struct Node *deleteAlternatNode(struct Node *first)
{

    struct Node *curr = first;

    if (first == NULL)
    {
        printf("List Is Empty");

        return NULL;
    }

    while (curr != NULL && curr->rptr != NULL)
    {

        struct Node *temp = curr->rptr;
        curr->rptr = curr->rptr->rptr;

        if (curr->rptr->rptr != NULL)
        {

            curr->rptr->rptr->lptr = curr;
        }

        curr = curr->rptr;
        free(temp);
    }

    return first;
}

void main()
{

    struct Node *h1 = NULL;

    h1 = insertAtFirst(h1, 8);
    h1 = insertAtFirst(h1, 7);
    h1 = insertAtFirst(h1, 6);
    h1 = insertAtFirst(h1, 5);
    h1 = insertAtFirst(h1, 4);
    h1 = insertAtFirst(h1, 3);
    h1 = insertAtFirst(h1, 2);
    h1 = insertAtFirst(h1, 1);

    display(h1);

    h1 = insertAtLast(h1, 9);
    display(h1);

    h1 = deleteAlternatNode(h1);
    display(h1);
}


// void deleteKthNodes(struct node *first, int k) {
//     struct node *curr = first;
//     int count = 1;

//     while (curr != NULL) {
//         if (count % k == 0) {
//             struct node *temp = curr;

//             // Link lptrious and rptr node
//             if (temp->lptr != NULL)
//                 temp->lptr->rptr = temp->rptr;
//             if (temp->rptr != NULL)
//                 temp->rptr->lptr = temp->lptr;

//             // Move to the rptr node before deleting
//             curr = curr->rptr;
//             free(temp);
//         } else {
//             curr = curr->rptr;
//         }
//         count++;
//     }
// }

