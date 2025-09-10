// 35. How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a program to solve the above problem.

#include <stdio.h>

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

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return;
    }
    top--;
    // printf("Popped element is: %c\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", stack[i]);
    }
}

void validString(char str[])
{

    int i = 0;

   // Push characters until 'c' is found
    while (str[i] != '\0' && str[i] != 'c')
    {
        push(str[i]);
        i++;
    }

    if (str[i] != 'c')
    {
        // 'c' not found
        printf("its Not Valid String.");
        return ;
    }
    i++;

    while(str[i] != '\0'){
        if(str[i] == stack[top]){
            pop();            
        }
         else {
        // If not matching, it's an invalid string
        printf("its Not Valid String.\n");
        return;
    }

        i++;
    }

    if (top == -1)
    {
        printf("Its Valid Valid String. %s", str);
    }
    else
    {
        printf("its Not Valid String.");
    }
}

void main(){

    char str[100];

    printf("Enter String.\n");
    scanf("%s", str);

    validString(str);
}