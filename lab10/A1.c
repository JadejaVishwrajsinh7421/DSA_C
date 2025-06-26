#include <stdio.h>
#include <stdlib.h>

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

void insertAtLast() {
    int x;
    printf("Enter number to insert at end: ");
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

void deleteAtFirst() {
    if (first == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp = first;
    first = first->link;
    free(temp);
}

void deleteAtEnd() {
    if (first == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    if (first->link == NULL) {
        free(first);
        first = NULL;
        return;
    }

    struct node *temp = first;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }

    free(temp->link);
    temp->link = NULL;
}

void deleteAtPosition() {
    if (first == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    int pos, i = 1;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteAtFirst();
        return;
    }

    struct node *temp = first;
    struct node *prev = NULL;

    while (temp != NULL && i < pos) {
        prev = temp;
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
}

void countNode() {
    int count = 0;
    struct node *temp = first;

    while (temp != NULL) {
        count++;
        temp = temp->link;
    }

    printf("Total nodes in linked list: %d\n", count);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Display all nodes\n");
        printf("3. Delete first node\n");
        printf("4. Insert at end\n");
        printf("5. Delete last node\n");
        printf("6. Delete node from specific position\n");
        printf("7. Count nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtFirst(); break;
            case 2: display(); break;
            case 3: deleteAtFirst(); break;
            case 4: insertAtLast(); break;
            case 5: deleteAtEnd(); break;
            case 6: deleteAtPosition(); break;
            case 7: countNode(); break;
            case 8: exit(0);
            default: printf("Invalid choice.\n"); break;
        }
    }
    return 0;
}
