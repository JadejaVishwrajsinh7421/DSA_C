#include<stdio.h>

void main() {
   int n;
   printf("enter number = ");
   scanf("%d",&n);
   int reverse = 0;
    
   while(n!=0) {
      int rem = n%10;
      reverse = reverse*10+rem;
      n = n/10;
   }
   printf("%d",reverse);
}