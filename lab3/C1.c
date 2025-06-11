#include<stdio.h>


//    int n;
//    printf("enter number of row  = ");
//    scanf("%d",&n);
//    int a[n][n];
//    for(int i=0; i<n; i++) {
//       for(int j =0;j<=i; j++) {
//          if(i == j||j ==0) {
//             a[i][j] = 1;
//          }
//          else  {
//             a[i][j] = a[i-1][j]+a[i-1][j-1];
//          }
//       }
//    }
//    for(int i=0; i<n; i++) {
//       for(int j=0; j<n-i-1; j++) {
//          printf(" ");
//       }
//       for(int j=0; j<=i; j++) {
//          printf("%d ",a[i][j]);
//       }
//       printf("\n");
//    }
// }


int fact(int n);
int combi(int n,int r);

int fact(int n) {
   if(n == 1||n == 0) {
      return 1;
   }
   return n*fact(n-1);
}
int combi(int n,int r) {
   return (fact(n)/(fact(r)*fact(n-r)));
}
    void main() {
   int n;
   printf("enter a number = ");
   scanf("%d",&n);
   for(int i=0; i<n; i++) {
      for(int j = 0; j<n-i-1; j++) {
         printf(" ");
      }
      for(int j=0; j<=i; j++) {
         printf("%d ",combi(i,j));
      }
      printf("\n");
   }
}