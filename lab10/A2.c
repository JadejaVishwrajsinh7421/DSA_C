#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void insertLinkedlist1()
{
    if (first1 == NULL)
    {
        printf("linked lists is empty\n");
    }
    int x;
    printf("enter number in list1\n");
    scanf("%d", &x);
    struct node *newNode1 = (struct node *)malloc(sizeof(struct node));
    newNode1->info = x;
    newNode1->link = first1;
    first1 = newNode1;
    return;
}

void insertLinkedlist2()
{
    if (first2 == NULL)
    {
        printf("linked lists is empty\n");
    }
    int x;
    printf("enter number in list2\n");
    scanf("%d", &x);
    struct node *newNode2 = (struct node *)malloc(sizeof(struct node));
    newNode2->info = x;
    newNode2->link = first2;
    first2 = newNode2;
    return;
}

void compareLists()
{
    int count = 0;
    struct node *save1;
    save1 = first1;
    struct node *save2;
    save2 = first2;

    while ((save1 != NULL) && (save2 != NULL))
    {
        if (save1->info != save2->info)
        {
            count++;
            break;
        }
        save1 = save1->link;
        save2 = save2->link;
    }
    if (count == 0)
    {
        printf("the LL is same ");
    }
    else
    {
        printf("the LL is not same ");
    }
}

void display1()
{
    if (first1 == NULL)
    {
        printf("linked lists is empty");
    }
    struct node *save;
    save = first1;

    while (save != NULL)
    {
        printf("the nodes are%d\n", save->info);
        save = save->link;
    }
}
void display2()
{
    if (first2 == NULL)
    {
        printf("linked lists is empty");
    }
    struct node *save;
    save = first2;

    while (save != NULL)
    {
        printf("the nodes are%d\n", save->info);
        save = save->link;
    }
}

void main()
{
    int choice = 0;

        while (1)
        {
            printf("\n--- Menu ---\n");
            printf("1. Insert into Linked List 1\n");
            printf("2. Insert into Linked List 2\n");
            printf("3. Compare the two linked lists\n");
            printf("4. Display Linked List 1 and 2\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                insertLinkedlist1();
                break;
            case 2:
                insertLinkedlist2();
                break;
            case 3:
                compareLists();
                break;
            case 4:
                printf("Displaying Linked List 1:\n");
                display1();
                printf("Displaying Linked List 2:\n");
                display2();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
          printf("Exiting program.\n");
    }
  