#include <stdio.h>
#include <stdlib.h>
#define size 5

int top = -1;
int stack[size];

void push() {
    if (top >= size - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    int data;
    printf("Enter the element to push: ");
    scanf("%d", &data);
    stack[++top] = data;
}

int pop() {
    if (top <= -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int val = stack[top--];
    return val;
}

void peep() {
    int index;
    printf("Enter index from top to peep (1 = top): ");
    scanf("%d", &index);
    if (index <= 0 || top - index + 1 < 0) {
        printf("Invalid position! Stack Underflow.\n");
        return;
    }
    printf("Element at position %d from top is: %d\n", index, stack[top - index + 1]);
}

void change() {
    int index, value;
    printf("Enter index from top to change (1 = top): ");
    scanf("%d", &index);
    if (index <= 0 || top - index + 1 < 0) {
        printf("Invalid position! Stack Underflow.\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &value);
    stack[top - index + 1] = value;
    printf("Value changed successfully.\n");
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents (top to bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("| %d |\n", stack[i]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Change\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            change();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
