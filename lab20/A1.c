// hashing hashset
#include <stdio.h>
#include <stdlib.h>
#define size 11
int hashtable[size];

int hashfunc(int key)
{
    return key % size;
}
void hashset()
{
    for (int i = 0; i < size; i++)
    {
        hashtable[i] = -1;
    }
}
void insert(int key)
{
    int index = hashfunc(key);
    int start = index;

    if (hashtable[index] == -1)
    {
        hashtable[index] = key;
    }
    else if (hashtable[index] == key)
    {
        printf("alredy key");
        return;
    }
    else
    {
        for (int probe = 0; probe < size; probe++)
        {
            int i = (index + probe) % size;
            if (hashtable[i] == -1)
            {
                hashtable[i] = key;
            }
            else if (hashtable[i] == key)
            {
                printf("alredy key");
                return;
            }
        }
    }
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        if (hashtable[i] >= 0)
            printf("[%d] → %d\n", i, hashtable[i]);
    }
}
void main()
{
    int choice, key;
    hashset();

    while (1)
    {
        printf("\n========= MENU =========\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            display();
            insert(key);

        case 3:
            printf("👋 Exiting program.\n");
            exit(0);
        }
    }
}