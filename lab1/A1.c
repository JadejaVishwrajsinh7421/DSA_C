#include<stdio.h>
void main(){
    //area of circle
    int radii=0;
    float area=0.0; 
    printf("Enter the radius of the circle: ");
    scanf("%d", &radii);
    area = 3.14 * radii * radii;
    printf("The area of the circle with radius %d is: %.2f\n", radii, area);
}