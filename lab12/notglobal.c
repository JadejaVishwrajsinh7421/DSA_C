#include<stdio.h>
#include<stdlib.h>
// add node at last using ptr

struct node
{
    int info;
    struct node *link;
};

struct node *addfirst(struct node *first, int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->link= NULL;
    if(first=NULL){
        return first;
    }
    while(first->link != NULL){
        first = newnode;
        return first;
    }
    
}
void printlist(){

}
void main(){

}