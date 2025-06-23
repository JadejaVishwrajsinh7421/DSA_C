#include<stdio.h>
#include<stdlib.h>
void main(){
    // 51. WAP to calculate the sum of n numbers using Pointer. 
    int size;
    printf("enter size of array");
    scanf("%d",&size);
    int *ptr = (int *)malloc (size *sizeof(int));

    int sum =0;
    for (int i=0;i<size;i++){
        printf("enter the elements in array[%d]",i);
        scanf("%d",ptr+i);
        sum +=*(ptr+i);
    }
  // print sum

    printf("the sum of elements of array: %d",sum);
    free(ptr);
}