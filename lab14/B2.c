#include <stdio.h>
#include <stdlib.h>

// split circular list in two halves

struct node
{
    int info;
    struct node *link;
};


struct node *first = NULL;
struct node *last = NULL;
struct node *first1 = NULL;
struct node *last1 = NULL;

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

void display() {
    if (first == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp = first;
    printf("The nodes are:\n");

    do
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    } while (temp != first);
    
    printf("%d",first->info);
}

int  count() {
    int count = 0;
    struct node *temp = first;

    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    return count;
   
}

void seperate(){
    int n = count();
    if(first == NULL || n < 2) {
        printf("List too small to split\n");
        return;
    }

    if(n%2==0){
        struct node *temp;
        int counter = 0;
        while(counter < n / 2) {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->info = first->info;

            if(first1 == NULL) {
                newnode->link = newnode;
                first1 = last1 = newnode;
            } else {
                newnode->link = first1;
                last1->link = newnode;
                last1 = newnode;
            }
            temp = first;
            first = first->link;
            last->link = first;
            free(temp);

            counter++;
        }
    }
}
void main(){

    int choice;
    while (1)
    {
        printf("\n1. Insert at front\n2. Insert at end\n3. Display\n4. Split circular linked list\n5. Exit\n");
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
            display();
            break;
        case 4:
            seperate();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}