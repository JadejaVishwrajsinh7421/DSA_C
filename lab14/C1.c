
// 71. Write a program to perform addition of two polynomial equations using 
// appropriate data structure. 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtFirst(struct Node *head, int x)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = head;

    head = newNode;

    return head;
}

struct Node *insertAtLast(struct Node *head, int x)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    struct Node *curr = head;

    while (curr->next != NULL)
    {

        curr = curr->next;
    }

    curr->next = newNode;

    return head;
}

void display(struct Node *head)
{

    struct Node *curr = head;

    if (curr == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    while (curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

struct Node* addPoly(struct Node* poly1 , struct Node* poly2 , struct Node* res){

    if(poly1==NULL && poly2==NULL){
        return NULL;
    }

    struct Node* curr=poly1;
    struct Node* curr2=poly2;

    
    while(curr!=NULL || curr2!=NULL){
        int sum = 0;

        sum+=((curr!=NULL)?(curr->data):(0)) + ((curr2!=NULL)?(curr2->data):(0));
        res = insertAtLast(res,sum);

        if(curr!=NULL){
            
            curr = curr->next;
        }

        if(curr2!=NULL){

            curr2= curr2->next;

        }

    }

    return res;
}

void main()
{

    struct Node *h1 = NULL;
    struct Node *h2 = NULL;
    struct Node *res = NULL;

  h1 = insertAtLast(h1,1);
  h1 = insertAtLast(h1,2);
  h1 = insertAtLast(h1,3);
  h1 = insertAtLast(h1,3);

  h2 = insertAtLast(h2,2);
  h2 = insertAtLast(h2,1);
  h2 = insertAtLast(h2,3);

  display(h1);
  display(h2);
  
  res = addPoly(h1,h2,res);
  display(res);
}
