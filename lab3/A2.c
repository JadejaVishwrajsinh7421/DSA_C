#include<stdio.h>
void main(){
    //Write a program to calculate sum of numbers from m to n.

    int n=0;
    printf("enter array num:");
    scanf("%d",&n);

    int arr[n];
    //read
    for(int i=0;i<n;i++){
        printf("array index %d value is:",i);
        scanf("%d",&arr[i]);
    }
    //sum from index
    int start=0;
    int end=0;
    int sum=0;
    printf("give start and end index for sum the element");
    scanf("%d %d",&start,&end );

    for(int i=start;i<=end;i++){
        sum=sum+arr[i];
    }
    printf("the sum is %d",sum);

}