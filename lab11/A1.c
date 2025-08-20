#include<stdio.h>
#include <stdlib.h>
// stack implement in singly list
//last in first out same postion insertion and delete operation
//input 1234 then display is 4321 and delete from 4 
struct node { 
    int info;
    struct node *link;
};

struct node *first = NULL;

void insertAtFirst() {
    int x;
    printf("Enter number to insert at front: ");
    scanf("%d", &x);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
}

struct node* deleteAtFirst(){
    if (first == NULL) {
        printf("Linked list is empty.\n");
        return first;
    }
    struct node *temp = first;
    first = first->link;
    return temp;
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

void main(){
   int choice;
    struct node *temp;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. push insert in stack\n");
        printf("2. Display all nodes\n");
        printf("3. pop delete in stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtFirst(); break;
            case 2: display(); break;
            case 3:  temp = deleteAtFirst();
            printf("%d",temp->info);
             break;
            case 4: exit(0);
            default: printf("Invalid choice.\n"); break;
        }
    }   
}