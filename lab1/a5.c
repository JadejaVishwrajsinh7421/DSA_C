#include<stdio.h>
void main(){
    //leap year
    int year;
    printf("enter a year: ");
    scanf("%d",&year);
    if(year%400 == 0 && year%100 == !0 || year%4 == 0){
        printf("given year is leap year");
    }
}