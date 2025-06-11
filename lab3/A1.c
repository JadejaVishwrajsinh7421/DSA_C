//Write a program to read and display n numbers using an array.
#include<stdio.h>
void main(){
    int n=0;
    printf("enter array num:");
    scanf("%d",&n);

    int arr[n];
    //read
    for(int i=0;i<n;i++){
        printf("array index %d value is:",i);
        scanf("%d",&arr[i]);
    }
    // display
    for(int i=0;i<n;i++){
        printf("the value at index %d",arr[i]);
    }
    


}