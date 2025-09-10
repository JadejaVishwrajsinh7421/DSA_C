#include <stdio.h>

// itterative
int BinarySearch(int arr[], int size)
{

    int x;
    printf("enter the elements to search:");
    scanf("%d", &x);

    int left = 0, right = size - 1, mid;
    while (left <= right)
    {
        mid = ((left + right) / 2);

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

void main()
{
      int size;
    printf("enter size of array /n");
    scanf("%d",&size);

    int arr[size];
    for(int i=0;i<size;i++){
        printf("enter elements in aray[%d]:\n",i);
        scanf("%d",&arr[i]);
    }
    
    
    int result = BinarySearch(arr,size);
    if(result == -1 ){
        printf("elements is not found in given array");

    }
    else{
        printf("we got result and index is arr[%d]",result);
    }
}