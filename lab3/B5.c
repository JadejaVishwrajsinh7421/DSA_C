#include<stdio.h>
void main(){
    //Write a program to find whether the array contains a duplicate number or not.
     int n=0;
    printf("enter array num:");
    scanf("%d",&n);

    int arr[n];
    //read
    for(int i=0;i<n;i++){
        printf("array index %d value is:",i);
        scanf("%d",&arr[i]);
    }

    int dupl= 0;
    printf("enter the to check duplicity in array");
    scanf("%d",&dupl);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]==dupl){
                break;
            }
        }
    }
    printf("the array contains duplicate num:%d",dupl);
}