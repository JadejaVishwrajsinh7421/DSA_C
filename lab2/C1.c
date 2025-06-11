#include<stdio.h>

void main() {
   for(int i=1; i<=1000; i++) {
      int n = 0,ans =0;
      int temp = i;
      while(temp!=0) {
         temp/=10;
         n++;
      }
      int temp1 = i;
      while(temp1!=0) {
         int rem1 =  temp1%10;
         int ans1 = 1;
         for(int j=1; j<=n; j++) {
            ans1*= rem1;
         }
         ans+=ans1;
         temp1/=10;
      } 
      if(ans == i) {
         printf("%d ",i);
      }
   }
}