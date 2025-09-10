#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int arr[], int size)
{
    int  x=0 ;
    printf("enter elements to find in array");
    scanf("%d",&x);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }

        return -1;
    }
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
    
    
    int result = LinearSearch(arr,size);
    if(result == -1 ){
        printf("elements is not found in given array");

    }
    else{
        printf("we got result and index is arr[%d]",result);
    }

}
