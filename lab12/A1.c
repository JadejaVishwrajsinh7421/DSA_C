#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;          
struct node *copyHead = NULL;       

void insertAtFirst();
void copyList();
void displayOriginal();
void displayCopy(struct node *);

void main() {
    int choice;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert into Linked List 1\n");
        printf("2. Copy the linked list and display copied nodes\n");
        printf("3. Display Original Linked List\n");
        printf("4. Display Copied Linked List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtFirst();
                break;
            case 2:
                copyList();
                break;
            case 3:
                displayOriginal();
                break;
            case 4:
                displayCopy(copyHead);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void insertAtFirst() {
    int x;
    printf("Enter number to insert at front: ");
    scanf("%d", &x);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
}

void copyList() {
    if (first == NULL) {
        printf("Original list is empty. Nothing to copy.\n");
        return;
    }

    struct node *save = first;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = save->info;
    newNode->link = NULL;

    copyHead = newNode;
    struct node *prev = newNode;

    save = save->link;

    while (save != NULL) {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = save->info;
        newNode->link = NULL;

        prev->link = newNode;
        prev = newNode;
        save = save->link;
    }

    printf("List copied successfully. Copied list:\n");
    displayCopy(copyHead);
}

void displayOriginal() {
    if (first == NULL) {
        printf("Original linked list is empty.\n");
        return;
    }
    struct node *temp = first;
    printf("Original List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

void displayCopy(struct node *begin) {
    if (begin == NULL) {
        printf("Copied linked list is empty.\n");
        return;
    }

    struct node *temp = begin;
    printf("Copied List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}
