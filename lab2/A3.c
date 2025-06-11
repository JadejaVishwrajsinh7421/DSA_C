#include<stdio.h>

void main() {
   int n,count=0;
   printf("enter number = ");
   scanf("%d",&n);

   for(int i=2; i<=n-1; i++) {
      if(n%i == 0)  {
         count++;
      }
   }
   if(count == 0) {
      printf("%d is prime Number",n);
   }
   else {
      printf("%d is not prime Number",n);
   }
}