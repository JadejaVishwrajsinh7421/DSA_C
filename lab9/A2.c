#include<stdio.h>
#include<stdlib.h>
void main(){
    // WAP to get and print the array elements using Pointer. 
    int size;
    printf("enter size of array");
    scanf("%d",&size);
    int *ptr = (int *)malloc (size *sizeof(int));


    for (int i=0;i<size;i++){
        printf("enter the elements in array[%d]",i);
        scanf("%d",ptr+i);
    }
    // print
     for (int i=0;i<size;i++){
        printf("enter the elements in array[%d]: %d",i,*(ptr+i));
    }
    free(ptr);

}