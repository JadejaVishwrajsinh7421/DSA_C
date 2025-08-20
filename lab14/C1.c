#include <stdio.h>
#include <stdlib.h>
// Write a program to perform addition of two polynomial equations using appropriate data structure.

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *last1 = NULL;
struct node *first2 = NULL;
struct node *last2 = NULL;
struct node *Nfirst = NULL;
struct node *Nlast = NULL;

int power1 = 0;
int power2 = 0;

void insertAtEnd(int temp)
{
    if (temp == 1)
    {
        printf("enter power of polynomial1 :\n");
        scanf("%d", &power1);
        for (int i = 0; i <= power1; i++)
        {
            int x;
            printf("Enter coefficent of x^%d: ", i + 1);
            scanf("%d", &x);
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->info = x;
            newNode->link = NULL;

            if (first1 == NULL)
            {
                first1 = newNode;
                first1 = last1 = newNode;
                return;
            }
            newNode->link = first1;
            last1->link = newNode;

            last1 = newNode;
        }
    }

    else
    {
        printf("enter power of polynomial2 :\n");
        scanf("%d", &power2);
        for (int i = 0; i <= power2; i++)
        {
            int x;
            printf("Enter coefficent of x^%d: ", i + 1);
            scanf("%d", &x);
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->info = x;
            newNode->link = NULL;

            if (first2 == NULL)
            {
                first2 = newNode;
                first2 = last2 = newNode;
                return;
            }
            newNode->link = first2;
            last2->link = newNode;

            last2 = newNode;
        }
    }
}

void display(int temp)
{
    if (temp = 1)
    {
        if (first1 == NULL)
        {
            printf("Linked list is empty.\n");
            return;
        }
        struct node *save1 = first1;
        printf("The nodes are:\n");

        do
        {
            printf("%d -> ", save1->info);
            save1 = save1->link;
        } while (save1 != first);

        printf("%d", save1->info);
    }

    else if (temp = 2)
    {
        if (first2 == NULL)
        {
            printf("Linked list is empty.\n");
            return;
        }
        struct node *save2 = first2;
        printf("The nodes are:\n");

        do
        {
            printf("%d -> ", save2->info);
            save2 = save2->link;
        } while (save2 != first2);

        printf("%d", save2->info);
    }
    // resultant newlist 
    else
    {
    }
}

void addpolynomial()
{
    struct node *save1 =first1;
    struct node *save2 =first2;

    if (power1 > power2)
    {
        //    struct node *newNode = (struct node *)malloc(sizeof(struct node));
        //     newNode->info = save1->info;
        //     newNode->link = save1->link;
            
        //     if (Nfirst == NULL)
        //     {
        //         Nfirst = newNode;
        //         Nfirst = Nlast = newNode;
        //         return;
        //     }
        //     newNode->link = Nfirst;
        //     Nlast->link = newNode;

        //     Nlast = newNode;


       
        
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n1. Insert polynomial 1\n2. Insert at polynomial 2\n3. Display 1\n4. Display 2\n5.addpolynomial\n6.display result polynomial\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtEnd(1);
            break;
        case 2:
            insertAtEnd(2);
            break;
        case 3:
            display(1);
            break;
        case 4:
            display(2);
            break;

        case 5:
            addpolynomial();
            break;

        case 6:
            display(3);
            break;

        case 7:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}