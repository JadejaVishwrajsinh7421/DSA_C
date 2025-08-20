#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
// Write a program to convert infix notation to postfix notation using stack.

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


int stack_precedence(char c){
    if(c == '+' || c == '-')
        return 2;
    else if(c == '*' || c == '/')
        return 4;   
    else if(c == '^')
        return 5;
    else if(c == '(')
        return 0; 
    else
        return 8; 

}

int input_precedence(char c){
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 3;   
    else if(c == '^')
        return 6;
    else if(c == '(')
        return 9;
    else if(c == ')')
        return 0;
    else    
        return 7;   

}

int priority(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c =='^')
        return -1;
    else
        return 1;
}
void infixToPostfix(char infix[])
{
    push('(');
    
    int i = 0;
    char postfix[100];
    int j = 0;
    int rank=0;
// printf("%c", stack[i]);

    while (i != strlen(infix))
    {
        char new = infix[i];

        
        while (stack_precedence(stack[top]) > input_precedence(new))
        {
            char temp = pop();
            postfix[j++] = temp;
            rank = rank + priority(temp);
            if (rank < 1){
                printf("invalid2");
                return;
            }
        }
        if(stack_precedence(stack[top]) !=  input_precedence(new)){
            push(new);
        }
        else{
            char temp = pop();
        }
        i++;
    }
    postfix[j] ='\0';

    // printf("%d %d",top,rank);
    if(top != -1 || rank != 1){
      printf("invalid1");
    }
    else{
        printf("%s",postfix);
    }

}

void main()
{
    char infix_str[size];
    printf("enter the infix string");
    scanf("%[^\n]", infix_str);
    strcat(infix_str,")");
    infixToPostfix(infix_str);
}
