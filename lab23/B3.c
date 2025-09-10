// insertion sort
#include <stdio.h>
void InsertionSort(int arr[], int size)
{
    int i = 1;
    while (i < size-1 )
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        i += 1;
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
    InsertionSort(arr, size);
    printf("after sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("enter elements in aray[%d]:%d\n", i, arr[i]);
    }
}