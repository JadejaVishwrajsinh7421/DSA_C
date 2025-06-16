#include <stdio.h>
void main()
{
    // Write a program to insert a number in an array that is already sorted in an
    // ascending order.
    int size = 0;
    printf("enter size of array:");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("enter value in array%d:", i + 1);
        scanf("%d", &arr[i]);
    }

    int add = 0;
    int i = 0;

    printf("enter number to add  in the array");
    scanf("%d", &add);

    // sort for asscending order before the number is add
    for (i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            // swap logic
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // check index of add element
    int ind = 0;
    while (ind < size && arr[ind] < add)
    {
        ind++;
    }
    // shift of element
    for (i = size; i > ind; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[ind] = add;
    size++;

    printf("the updated array");
    for (i = 0; i < size; i++)
    {
        printf("arr[%d]:%d\n", i, arr[i]);
    }
}