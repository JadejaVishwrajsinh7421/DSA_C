#include<stdio.h>
#include<stdlib.h>
void main(){
    // 52. WAP to find the largest element in the array using Pointer.
    int size;
    printf("enter size of array");
    scanf("%d",&size);
    int *ptr = (int *)malloc (size *sizeof(int));

    
    for (int i=0;i<size;i++){
        printf("enter the elements in array[%d]",i);
        scanf("%d",ptr+i);
      
    }

    //largest
    int maxnum=*ptr;
    for (int i=0;i<size;i++){
      if(maxnum <(*ptr+i)){
        maxnum=*ptr+i;
      }
    }
    printf("the largest num is:%d",maxnum);
    free(ptr);

}