//Write a program to find position of the smallest number & the largest number
// from given n numbers.in array 
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
    int max = arr[0];
    int min = arr[0];
    int indexmax =0,indexmin =0;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++){
            if(max< arr[j]){
            max = arr[j];
            indexmax =j;
            }
            if(min>arr[j]){
            min = arr[j];
            indexmin = j;
            }
        }
    }
    printf("the max num in array is%d and index %d:",min,indexmax);
    printf("the min num in array is%d and index %d:",min,indexmin);
}