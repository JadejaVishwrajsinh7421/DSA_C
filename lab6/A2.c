#include <stdio.h>
#include <stdlib.h>

#define size 100
//  How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a program to solve the above problem.
char stack[size];
int top = -1;

void push()
{
    if (top >= size - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    char data;
    printf("Enter the element to push: ");
    scanf("%[^\n]", &data);
    stack[++top] = data;
}

void check(char str[])
{
    int i = 0;
    stack[++top] = 'c';
    while (str[i] != 'c')
    {
        if
    }
}

char pop()
{
    if (top <= -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

// void display() {
//     if (top == -1) {
//         printf("Stack is empty.\n");
//         return;
//     }
//     printf("Stack contents (top to bottom):\n");
//     for (int i = top; i >= 0; i--) {
//         printf("| %d |\n", stack[i]);
//     }
// }

int main()
{
    char str[size];
    printf("enter the string of grammar");
    scanf("%[^\n]", &str);

    check(str[size]);
    return 0;
}