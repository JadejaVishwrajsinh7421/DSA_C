#include<stdio.h>

void main() {
   int a,b; 

   printf("enter first value of Interval = ");
   scanf("%d",&a);

   printf("enter second value of Interval = ");
   scanf("%d",&b);

   for(int i=a+1; i<b ;i++) {
      int count = 0;
      for(int j=2; j<i; j++) {
         if(i%j == 0) {
            count++;
         }
      }
      if(count == 0) {
         printf("%d ",i);
      }
   }

}