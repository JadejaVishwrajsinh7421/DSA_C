#include <stdio.h>
#include <stdlib.h>
#define size 5

int rear = -1, front = -1;
int cirqueue[size];

void cqinsert()
{
    int x;
    printf("enter the elements in the cirqueue: ");
    scanf("%d", &x);

    if ((rear + 1) % size == front)
    {
        printf("overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = (rear + 1) % size;
    cirqueue[rear] = x;
}

int cqdelete()
{
    if (front == -1)
    {
        printf("underflow\n");
        return -1;
    }

    int x = cirqueue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    return x;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1)
    {
        printf("| %d |\n", cirqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
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
            cqinsert();
            break;
        case 2:
            cqdelete();
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
