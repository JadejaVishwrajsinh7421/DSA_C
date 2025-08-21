#include <stdio.h>
#include <stdlib.h>
#define size 10

// priority queue implements
struct queue
{
    int data;
    int priority;
};
struct queue Proi[size];

int front = -1, rear = -1;

void insert(int data, int priority)
{

    if (rear > size - 1)
    {
        printf("overflow");
        return;
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        Proi[rear].data = data;
        Proi[rear ].priority= priority;
        return;
    }
    else
    {
        Proi[++rear].data = data;
        Proi[++rear].priority = priority;
        return;
    }
}

// void insert_with_priority(int data, int priority)
// {
//     if (rear == size - 1)
//     {
//         printf("overflow");
//         return;
//     }
//     // insert 1st element
//     if (front == -1)
//     {
//         front = rear = 0 Proi[rear].data = data;
//         Proi[rear].priority = priority;
//     }
//     // other upcoming will arrage orderwise with prority or we can also use buuble sort after all 
//     else
//     {
//         int pos = rear;

//         while (i >= front && Proi[i].priority < priority)
//         {
//             Proi[i + 1] = Proi[i];
//             i--;
//         }

//         Proi[i + 1].data = data;
//         Proi[i + 1].priority = priority;
//         rear++;
//     }
// }

void delete()
{
    if (front == -1)
    {
        printf("underflow");
        {
            return;
        }
    }
    int pos = front;
    // priority wise deletion
    for (int i = front + 1; i <= rear; i++)
    {
        if (
            Proi[i].priority > Proi[pos].priority)
        {
            pos = i;
        }
    }
    printf("deleted element %d %d", Proi[pos].data, Proi[pos].priority);
    // gap filling of deleted shell
    for (int i = pos; i <= rear; i++)
    {
        Proi[i] = Proi[i + 1];
    }
    rear--;

    if (front > rear)
    {
        front = -1;
        rear = -1;
        return;
    }
}
void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("| %d |\n", Proi[i]);
    }
}
void main()
{
    int choice, val, pri;

    while (1)
    {
        printf("\n---- Priority Queue Menu ----\n");
        printf("1. Insert\n");
        printf("2. Delete (highest priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter priority: ");
            scanf("%d", &pri);
            insert(val, pri);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            return ;

        default:
            printf("Invalid choice!\n");
        }
    }
}