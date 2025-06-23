#include <stdio.h>
#include <stdlib.h>
void main()
{
    // 53. WAP to sort the array elements using Pointer.
    int size;
    printf("enter size of array");
    scanf("%d", &size);
    int *ptr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("enter the elements in array[%d]", i);
        scanf("%d", ptr + i);
    }
    //  sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (*(ptr + j) > *(ptr + j + 1))
            {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("enter the elements in array[%d]: %d \n", i, *(ptr + i));
    }

}