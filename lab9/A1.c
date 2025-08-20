#include<stdio.h>
#include<stdlib.h>
void main(){
    // 49. WAP to allocate and de-allocate memory for int, char and float variable at 
// runtime.
int n;
printf("enter value of n") ;
scanf("%d",&n);

    int *ptr = (int *)malloc (1* sizeof(int));
    float *ptr1 = (float *)calloc(1,sizeof(float));
    char *ptr2= (char *)malloc(1 *sizeof(char));

    if(ptr && ptr1 && ptr2){
        *ptr = 9;
        printf("a:%d",*ptr);

        *ptr1=2;
        printf("a:%d",*ptr1);

        *ptr2 = 9;
        printf("a:%d",*ptr2);

    }
    free(ptr);
    free(ptr1);
    free(ptr2);
}