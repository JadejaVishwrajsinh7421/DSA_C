#include <stdio.h>

void selectionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}


void main()
{
    int size;
    printf("enter size of array /n");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("enter elements in aray[%d]:\n", i);
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, size);

    printf("after sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("enter elements in aray[%d]:%d\n", i, arr[i]);
    }
}