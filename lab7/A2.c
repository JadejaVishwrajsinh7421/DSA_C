#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
// Write a program to convert infix notation to prefix notation using stack.

char stack[size];
int top = -1;

void push(char data)
{
    if (top >= size - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = data;
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

int stack_precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '^')
        return 6;
    else if (c == '(')
        return 0;
    else
        return 8;
}

int input_precedence(char c)
{
    if (c == '+' || c == '-')
        return 2;
    else if (c == '*' || c == '/')
        return 4;
    else if (c == '^')
        return 5;
    else if (c == '(')
        return 9;
    else if (c == ')')
        return 0;
    else
        return 7;
}

int priority(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return -1;
    else
        return 1;
}
void infixToprefix(char infix[])
{
     push('(');
    int i = 0;
    char prefix[100];
    int j = 0;
    int rank = 0;

    while (infix[i]!='\0')
    {
        char new = infix[i];
        // printf("%c",new);
       

        while (stack_precedence(stack[top]) > input_precedence(new))
        {
            char temp = pop();
            prefix[j++] = temp;
            rank = rank + priority(temp);
            if (rank < 1)
            {
                printf("invalid1");
                return;
            }
        }
        if (stack_precedence(stack[top]) != input_precedence(new))
        {
            push(new);
        }
        else
        {
            char temp = pop();
        }
        i++;
    }
    prefix[j] = '\0';
    if (top != -1 || rank != 1)
    {
        printf("%d %d",top,rank);
        printf("invalid2");
    }
    else
    {
        printf("%s", strrev(prefix));
    }
}

void main()
{
    char infix_str[size];
    printf("enter the infix string");
    scanf("%[^\n]", &infix_str);
    
    int k = 0;
    char revese[size];
    for (int i = strlen(infix_str) - 1; i >= 0; i--)
    {
        if (infix_str[i] == '(')
        {
            revese[k] = ')';
        }
        else if(infix_str[i] == ')')
        {
            revese[k] = '(';
        }
        else{
            revese[k]= infix_str[i];
        }
        k++;

    }
    revese[k]='\0';
    strcat(revese, ")");
    // printf("%s main",revese);
    infixToprefix(revese);
}
