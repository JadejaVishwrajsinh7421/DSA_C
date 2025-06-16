#include <stdio.h>
void main()
{
    // B 29. Write a program to merge two unsorted arrays.

    // arr1
    int size1 = 0;
    printf("enter size of array:");
    scanf("%d", &size1);
    int arr1[size1];
    for (int i = 0; i < size1; i++)
    {
        printf("enter value in array%d:", i + 1);
        scanf("%d", &arr1[i]);
    }
    // arr2
    int size2 = 0;
    printf("enter size of array:");
    scanf("%d", &size2);
    int arr2[size2];
    for (int i = 0; i < size2; i++)
    {
        printf("enter value in array%d:", i + 1);
        scanf("%d", &arr2[i]);
    }

    // new array for merge
    int size3 = size1 + size2;
    int arr3[size3];
    for (int i = 0; i < size1; i++)
    {
        arr3[i] = arr1[i];
    }
    // add of second array
    for (int i = 0; i < size2; i++)
    {
        arr3[size1+i] = arr2[i];
    }
    // method-2
    // for(int i= size1;i<size2;i++){
    //     arr3[i]=arr2[i-size2];
    // }

    // updateed array
    printf("the updated array");
    for (int i = 0; i < size3; i++)
    {
        printf("arr[%d]:%d\n", i, arr3[i]);
    }
}