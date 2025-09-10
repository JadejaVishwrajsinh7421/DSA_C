#include <stdio.h>

// recuusrive
int BinarySearchRecuusrive(int arr[], int size, int x, int left, int right)
{

    int mid;
    while (left <= right)
    {
        mid = ((left + right) / 2);

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            // left = mid + 1 
            return BinarySearchRecuusrive(arr,size,x,mid+1,right);
        }
        else{
           return  BinarySearchRecuusrive(arr,size,x,left,mid-1);
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
     int x;
    printf("enter the elements to search:");
    scanf("%d", &x);
    
    int result = BinarySearchRecuusrive(arr,size,x,0,size-1);
    if(result == -1 ){
        printf("elements is not found in given array");

    }
    else{
        printf("we got result and index is arr[%d]",result);
    }
}