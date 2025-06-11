#include <stdio.h>
void main()
{
    int year = 0, week = 0, day = 0;
    printf("enter no. of days:");
    scanf("%d", &day);
    
    while (day >= 365)
    {
        if (day >= 365)
        {
            year++;
            day -= 365;
        }
        if (day >= 7)
        {
            week++;
            day -= 7;
        }
    }
    printf("%d:%d:%d", year, week, day);
}
