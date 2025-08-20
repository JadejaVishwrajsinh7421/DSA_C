#include<stdio.h>
#include<stdlib.h>
//  implement queue first in first out 
//  1234 inserrt 5 then  12345  delete then 2345 display is like 12345
struct node{
    int info;
    struct node *link;
};
struct node *first = NULL;

void insertAtLast() {
    int x;
    printf("Enter number to insert in queue: ");
    scanf("%d", &x);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
        return;
    }

    struct node *temp = first;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

void deleteAtFirst() {
    if (first == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp = first;
    first = first->link;
    printf("%d",temp->info);
    free(temp);
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

int main() {
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Inqueue insert in queue\n");
        printf("2. Display all nodes\n");
        printf("3. Dequeue delete in queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtLast(); break;
            case 2: display(); break;
            case 3: deleteAtFirst(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n"); break;
        }
    }
    return 0;
}
