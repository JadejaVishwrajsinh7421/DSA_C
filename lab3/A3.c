#include<stdio.h>
void main(){
    int num=0;
    int sum=0;
    printf("enter the num to the sum");
    scanf("%d",&num);

    for(int i=1;i<=num;i++){
      sum+=i;
    }
    float avg = (float)sum/num;
    printf("the avg upto the num %d is%d and avg is %f",num,avg);
}