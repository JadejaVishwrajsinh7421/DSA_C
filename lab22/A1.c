#include <stdio.h>
// Bubble sort

void BubbleSort(int arr[], int size)
{
    int last = size - 1;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < last; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        if (count == 0)
        {
            printf("the array is already sorted");
            return;
        }
        else
        {
            last--;
        }
    }
    return;
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
    BubbleSort(arr, size);

    printf("after sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("enter elements in aray[%d]:%d\n", i,arr[i]);
    }
}