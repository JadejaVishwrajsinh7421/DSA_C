#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// insert node at last
struct node* insertAtLast(struct node* first, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL)
    {
        return newNode;   // return new head if list was empty
    }

    struct node *temp = first;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newNode;
    return first;   // return unchanged head
}

// display linked list
void display(struct node* first)
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

// swap nodes in pairs
struct node* SwapPair(struct node* first)
{
    if (first == NULL || first->link == NULL)
    {
        return first;
    }

    struct node *temp1 = first;
    struct node *temp2 = first->link;
    struct node *prev = NULL;

    // new head will be second node
    first = temp2;

    while (temp1 != NULL && temp2 != NULL)
    {
        struct node *temp3 = temp2->link;

        temp2->link = temp1;
        if (temp3 == NULL || temp3->link == NULL)
        {
            temp1->link = temp3;
        }
        else
        {
            temp1->link = temp3->link;
        }

        if (prev != NULL)
        {
            prev->link = temp2;
        }

        // update pointers
        prev = temp1;
        temp1 = temp3;
        if (temp1 != NULL)
        {
            temp2 = temp1->link;
        }
    }

    return first;
}

int main()
{
    struct node *h1 = NULL;

    h1 = insertAtLast(h1, 12);
    h1 = insertAtLast(h1, 6);
    h1 = insertAtLast(h1, 9);
    h1 = insertAtLast(h1, 18);
    h1 = insertAtLast(h1, 5);
    h1 = insertAtLast(h1, 25);

    display(h1);

    h1 = SwapPair(h1);

    display(h1);

    return 0;
}
