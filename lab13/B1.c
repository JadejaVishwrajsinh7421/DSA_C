#include <stdio.h>
#include <stdlib.h>
// WAP to perform given operation in the linked list. There exist a Linked List. Add a node that contains the GCD of that two nodes between every pair adjacent node of Linked List.

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

void insertAtFirst();
void display();
void insertgcd();
int gcdNumber(int,int);

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

int  gcdNumber( int a , int b)
{
    
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
}

void insertgcd()
{
    struct  node *save = first;
    while (save->link!= NULL)
    {
      struct node *newNode = (struct node *)malloc(sizeof(struct node));
      newNode->info = gcdNumber(save->info,save->link->info);
      newNode->link = save->link;
      save->link = newNode;
      save->link=
      save = save->link->link;
    }    
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
        printf("2. Display Linked List before adding gcd\n");
        printf("3. insert gcd\n");
        printf("4. Display Linked List after gcd insert\n");
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
            insertgcd();
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