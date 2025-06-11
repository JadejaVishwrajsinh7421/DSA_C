#include<stdio.h>
#include<math.h>
#define pi 3.14
void main(){
    // wap circle area
    float radii,area;
    printf("enter radii of circle");
    scanf("%f",&radii);
    area = pi*radii*radii;
    printf("area of circle is %f",area);

}