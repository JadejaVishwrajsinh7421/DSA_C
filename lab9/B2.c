#include<stdio.h>
#include<stdlib.h>
void main(){
//     54. WAP to check whether the string is Palindrome or not using Pointer. 
    
    int length;
    printf("enter length of string");
    scanf("%d", &length);

    char *ptr = (char *)malloc((length +1)* sizeof(char));
    printf("enter a string");
    scanf("%s",ptr);

    int* start = (int*)ptr;
    int* end = (int*)ptr+(length-1);
    int isPalindrome = 1;
    while (start < end) {
        if (*start != *end) {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }
    printf("The string is %s\n", isPalindrome ? "Palindrome" : "Not Palindrome");
   
    free(ptr);
    


}