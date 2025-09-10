#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *last = NULL;
struct node *first2 = NULL;
struct node *last2 = NULL;

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
        first = last = newNode;
        last->link = first; // make it circular
        return;
    }

    newNode->link = first;
    last->link = newNode;
    last = newNode;
}

void display(struct node *first)
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = first;
    printf("Nodes: ");
    do
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    } while (temp != first);
    printf("(back to %d)\n", first->info);
}

struct node* split() {
    if (first == NULL || first->link == first) {
        printf("Not enough elements to split.\n");
        return NULL;
    }

    struct node* slow = first;
    struct node* fast = first;

    // Use slow-fast with CSLL condition
    while (fast->link != first && fast->link->link != first) {
        slow = slow->link;
        fast = fast->link->link;
    }

    struct node* first2 = slow->link; // start of second half

    // Make first half circular
    slow->link = first;

    // Make second half circular
    struct node* curr = first2;
    while (curr->link != first) {
        curr = curr->link;
    }
    curr->link = first2;

    return first2; // return head of second half
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Insert at end\n2. Display\n3. Split circular linked list\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtEnd();
            break;
        case 2:
            display(first);
            break;
        case 3:
            split();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
