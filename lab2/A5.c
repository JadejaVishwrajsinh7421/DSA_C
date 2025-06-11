#include<stdio.h>

void main() {
   int n,power;
   printf("enter a number = ");
   scanf("%d",&n);
   printf("enter power = ");
   scanf("%d",&power);
   int ans = 1;
   for(int i=1; i<=power; i++) {
      ans*=n;
   }
   printf("%d",ans);
}