#include <stdio.h>
#include <stdlib.h>

// WAP to delete alternate nodes of a doubly linked list.

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *L = NULL;
struct node *R = NULL;

void AlternateDelete()
{


    struct node *save = L;
    struct node *temp =  save->rptr;;


    while (temp != NULL)

        {

            save->rptr = temp->rptr;
            if(temp->rptr!= NULL){
                temp->rptr->lptr = save;
            }

            free(temp);
            save = save->rptr;
        }
}

// void deleteKthNodes(struct node *head, int k) {
//     struct node *curr = head;
//     int count = 1;

//     while (curr != NULL) {
//         if (count % k == 0) {
//             struct node *temp = curr;

//             // Link previous and next node
//             if (temp->lptr != NULL)
//                 temp->lptr->rptr = temp->rptr;
//             if (temp->rptr != NULL)
//                 temp->rptr->lptr = temp->lptr;

//             // Move to the next node before deleting
//             curr = curr->rptr;
//             free(temp);
//         } else {
//             curr = curr->rptr;
//         }
//         count++;
//     }
// }

