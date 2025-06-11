#include<stdio.h>
void main(){
    //largest 3num
    int n1,n2,n3;
    printf("enter num1: ");
    scanf("%d",&n1);
     printf("enter num2: ");
    scanf("%d",&n2);
     printf("enter num3: ");
    scanf("%d",&n3);

    int largest = (n1>n2) ?(n1>n3 ? n1 : n3) : (n2>n3 ? n2 : n3);
    printf("largest num is %d", largest);
}