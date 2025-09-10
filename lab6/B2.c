
// 37. Valid Parenthesis Problem
// Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.
// Now Chef wants to know if the given string is balanced or not.
// If is balanced then print 1, otherwise print 0.
// A balanced parenthesis string is defined as follows:
// • The empty string is balanced
// • If P is balanced then (P), {P}, [P] is also balanced
// • if P and Q are balanced PQ is also balanced
// • "([])", "({})[()]" are balanced parenthesis strings
// • "([{]})", "())" are not balanced.

// Input Format:
// The first line of the input contains a single integer T denoting the number of
// test cases. The description of T test cases follows. The first and only line of
// each test case contains a single string

// Output Format:
// For each test case, print a single line containing the answer.

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
    printf("Stack elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", stack[i]);
    }
}

int isValid(char str[])
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        // printf("%c\n", str[i]);
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            push(str[i]);
        }
        else
        {

            if (top == -1)
            {
                // printf("Stack underflow ...");
                return 0;
            }

            char ch = pop();

            if ((str[i] == '}' && ch != '{') ||
                (str[i] == ')' && ch != '(') ||
                (str[i] == ']' && ch != '['))
            {

                // printf("Invalid opening ...");
                return 0;
            }
        }
    }

    return top == -1;
}

void main()
{
    while (1)
    {

        char str[100];

        printf("Enter String.\n");
        // scanf("%[][{}()]s", str);
        scanf("%s", str);

        if (str[0] != '}' || str[0] != '{' ||
            str[0] != ')' || str[0] != '(' ||
            str[0] != ']' || str[0] != '[')
        {
            printf("Existing..");
            break;
        }

        if (isValid(str))
        {
            printf("Valid Parenthesis");
        }
        else
        {
            printf("Invalid Parenthesis");
        }
    }
}
