#include<stdio.h>
void main(){

    //Read n numbers in an array then read two different numbers, replace 1st
//number with 2nd number in an array and print its index and final array.

     int n=0;
    printf("enter array num:");
    scanf("%d",&n);

    int arr[n];
    //read
    for(int i=0;i<n;i++){
        printf("array index %d value is:",i);
        scanf("%d",&arr[i]);
    }
    int n1 =0;
    printf("enter num to change ");
    scanf("%d",&n1);

    for(int i=0;i<n1;i++){
        if(arr[i]==n1){
            printf("enter the number to change");
            scanf("%d",&arr[i]);
            break;
        }
 
    }
      printf("the new array is ");
    for(int i=0;i<n;i++){
        printf("{:%d}",arr[i]);
    }

}