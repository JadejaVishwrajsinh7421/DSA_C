#include<stdio.h>
void main(){
    // Write a program to delete a number from an array that is already sorted in an ascending order.

    int size=0;
    int del=0;
    int i=0;
    printf("enter size of array");
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++){
        printf("enter value of arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("enter number to delete in the array");
    scanf("%d",&del);

    int ind=0;
    while(ind<size && arr[ind]<del){
        ind++;
    }
    for(i=ind;i<size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    printf("the updated array");
    for(i=0;i<size;i++){
        printf("arr[%d]:%d\n",i,arr[i]);
    }



}