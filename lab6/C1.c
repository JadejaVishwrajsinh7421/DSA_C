/* The code snippet you provided is describing the "Merge Intervals Problem". This problem involves
merging a set of time intervals that may overlap into mutually exclusive intervals. The goal is to
combine overlapping intervals into a single interval. */
// 38. Removing starts from a string Problem
// You are given a string s, which contains stars *. In one operation, you can:
// Choose a star in s. Remove the closest non-star character to its left, as well as
// remove the star itself. Return the string after all stars have been removed.

// Note :
// • The input will be generated such that the operation is always possible.
// • It can be shown that the resulting string will always be unique.

// Sample Example-1:
// Input: s = "leet**cod*e".
// Output: "lecoe"

// Sample Example-2:
// Input: s = "erase*****"
// Output: ""

#include <stdio.h>
#include <string.h>

char stack[100];
int size = 100;
int top = -1;

void push(char ch)
{
    if (top >= size - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    stack[++top] = ch;
    // printf("Pushed %c\n", ch);
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return 0;
    }

    return stack[top--];
    // printf("Popped element is: %c\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Ans :\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
}

void removeStars(char str[]){

    int count = 0;

    for(int i=0 ; str[i] != '\0' ; i++){

        if(str[i] == '*'){

            pop();            

        }
        else{

            push(str[i]);

        }
    }
    display();
}

void main(){

    char str[100];

    printf("Enter String.\n");
    scanf("%s", str);

    removeStars(str);
}