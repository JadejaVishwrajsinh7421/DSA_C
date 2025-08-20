#include <stdio.h>
#include <stdlib.h>
#define size 5
// double ended dequeue
int front = -1, rear = -1;
int dequeue[size];

void dqinsert_front()
{
    int x;
    printf("enter the elements in the dequeue");
    scanf("%d", &x);
    if (front == 0)
    {
        printf("overflow");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }
    dequeue[front] = x;
    return;
}

void dqinsert_rear()
{
    int x;
    printf("enter the elements in the dequeue");
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
        dequeue[rear] = x;
        return;
    }
    else
    {
        dequeue[++rear] = x;
        return;
    }
}

int dqdelete_front()
{
    if (front == -1)
    {
        printf("underflow");
        return -1;
    }
    int x = dequeue[front];
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

int dqdelete_rear()
{
    if (rear == -1)
    {
        printf("underflow");
        return -1;
    }
    int x = dequeue[rear];
    if (rear == front)
    {
        rear = front = -1;
    }
    else
    {
        rear--;
    }
    return x;
}
void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("| %d |\n", dequeue[i]);
    }
}
void main()
{

    int choice;

    while (1)
    {
        printf("\n--- dequeue Menu ---\n");
        printf("1. dqinsert_front\n");
        printf("2. dqinsert_rear\n");
        printf("3. dqdelete_front\n");
        printf("4. dqdelete_rear\n");
        printf("5. display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            dqinsert_front();
            break;
        case 2:
            dqinsert_rear();
            break;
        case 3:
            dqdelete_front();
            break;
        case 4:
            dqdelete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}