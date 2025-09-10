// 36. Write a program to determine if an input character string is of the form aibi
// where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’.

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

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return 0;
    }
    top--;
    return 1;
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

int isEqual(char str[])
{

    int i = 0;

    // Push All 'a'

    if (str[i] != 'a') return 0; // a thi j chalu thavi joie str

    while (str[i] == 'a')
    {

        push(str[i]);
        i++;
    }

    // Pop For All 'b'

    if (str[i] != 'b') return 0; // 'a' badha push thai gya to have pachi atleast ek b to hovo j joie

    while (str[i] == 'b')
    {

        if (!pop())
        {
            return 0;   // string ma 'b' vadhare che 'a' karta tyare  
        }
        i++;
    }

    return (top == -1) && (str[i] == '\0');
}

void main()
{

    char str[100];

    printf("Enter String.\n");
    scanf("%s", str);

    if (isEqual(str))
    {
        printf("Valid : Number of 'a' should be equal to number of 'b'.");
    }
    else
    {
        printf("Invalid: : Number of 'a' and 'b' is not equal.");
    }
}