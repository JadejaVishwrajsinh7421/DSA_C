#include <stdio.h>
#include <stdlib.h>
#define size 5

int rear = -1, front = -1;
int queue[size];

void enqueue()
{
    int x;
    printf("enter the elements in the queue");
    scanf("%d", &x);

    if (rear > size - 1)
    {
        printf("overflow");
        return;
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
        return;
    }
    else
    {
        queue[++rear] = x;
        return;
    }
}

int dequeue()
{

    if (front == -1)
    {
        printf("underflow");
        return -1;
    }
    int x = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return x;
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("| %d |\n", queue[i]);
    }
}
void main()
{
    int choice;

    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}