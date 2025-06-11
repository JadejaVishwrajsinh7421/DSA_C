#include<stdio.h>
int calcFact(int n);

int calcFact(int n) {
   if(n==1||n==0) {
      return 1;
   }
   return n*calcFact(n-1);
}
void main() {
   int n,fact=1; 
   printf("enter number to find factorial = ");
   scanf("%d",&n);
   int factorial = calcFact(n);
   printf("%d",factorial);

   for(int i=1; i<=n; i++) {
      fact*=i;
   }
   printf("%d",fact);
}