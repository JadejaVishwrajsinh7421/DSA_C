// quick sort
#include <stdio.h>
#include <stdbool.h>
void quickSort(int lb, int ub, int arr[])
{
    bool flag = true;
    if (lb < ub)
    {
        int i = lb;
        int j = ub + 1;
        int key = arr[lb];
        while (flag == true)
        {
            i += 1;
            while (arr[i] < key)
            {
                i += 1;
            }
            j -= 1;
            while (arr[j] > key)
            {
                j -= 1;
            }
            if (i < j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else
            {
                flag = false;
            }
        }

        int temp = arr[lb];
        arr[lb] = arr[j];
        arr[j] = temp;
        quickSort(lb, j - 1, arr);
        quickSort(j + 1, ub, arr);
    }
}
void main()
{
    int i;
    int size;
    printf("enter size of array /n");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("enter elements in aray[%d]:\n", i);
        scanf("%d", &arr[i]);
    }
    quickSort(0, size - 1, arr);

    printf("after sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("enter elements in aray[%d]:%d\n", i, arr[i]);
    }
}
