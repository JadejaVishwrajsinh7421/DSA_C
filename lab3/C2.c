#include<stdio.h>
#include<string.h>
void main(){
    //  WAP to sort the N names in an alphabetical order.
    int n, i, j;
    printf("Enter the number of names: ");
    scanf("%d", &n);
    char names[n][100]; 
    printf("Enter the names:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", names[i]);
}   
    // Sorting names 
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(strcmp(names[j], names[j+1]) > 0) {
                // Swap 
                char temp[100];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }
    printf("Names in alphabetical order:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }





    


}