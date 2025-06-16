#include<stdio.h>
void main(){
    // A 25. Write a program to delete a number from a given location in an array. 
    int arr[100];
    int usindex=0;
    int usnum=0;
    int n=0,del=0;
    
    printf("enter size of array");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter value in array");
        scanf("%d",&arr[i]);
    }
    printf("enter num to delete num at index");
    scanf("%d",&del);
    for(int i=del;i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;
    printf("update array is ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}