#include<stdio.h>
void main(){
    //Write a program to insert a number at a given location in an array.
    int arr[100];
    int usindex=0;
    int usnum=0;
    int n =6;
    
    //scan array
    for(int i=0;i<n;i++){
        printf("enter value in array");
        scanf("%d",&arr[i]);
    }
    printf("enter value of num ");
    scanf("%d",&usnum);
    printf("enter and index");
    scanf("%d",&usindex);
    
    for(int i=n+1;i>usindex;i--){
        arr[i]=arr[i-1];
    }
    arr[usindex]=usnum;
    n++;
    printf("new array is");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }





}