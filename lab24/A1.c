#include <stdio.h>
#define SIZE 5
int arr[SIZE];

void merge(int low, int mid, int high)
{
    int h, i, j, k;
    int b[SIZE]; // temp array

    h = low;
    i = low;
    j = mid + 1;

    // Step 1: Compare and copy smaller elements
    while (h <= mid && j <= high)
    {
        if (arr[h] <= arr[j])
        {
            b[i] = arr[h];
            h++;
        }
        else
        {
            b[i] = arr[j];
            j++;
        }
        i++;
    }

    // Step 2: Handle remaining elements
    if (h > mid)
    {
        for (k = j; k <= high; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }

    // Step 3: Copy back into original array
    for (k = low; k <= high; k++)
    {
        arr[k] = b[k];
    }
}

void MergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter element arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    MergeSort(0, SIZE - 1);

    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
