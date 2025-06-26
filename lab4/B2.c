#include <stdio.h>
void main()
{
    // . Write a program to delete duplicate numbers from an array.

    int size = 0;
    printf("enter size of array:");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("enter value in array%d:", i + 1);
        scanf("%d", &arr[i]);
    }

    // check duplicate number
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size;)
        {
            if (arr[i] == arr[j])
            {
                int ind = j;
                
                for (int k = ind; k < size - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                size--;
            }

            else
            {
                j++;
            }
        }
    }

    // updated
    printf("the updated array");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d]:%d\n", i, arr[i]);
    }
}