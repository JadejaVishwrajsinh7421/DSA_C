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

void main(){
    
}
