// 45. You have an array A of integers of size N, an array B (initially empty) and a stack
// S (initially empty). You are allowed to do the following operations:

// • Take the first element of array A and push it into S and remove it from A.
// • Take the top element from stack S, append it to the end of array B and
// remove it from S.

// You have to tell if it possible to move all the elements of array A to array B using
// the above operations such that finally the array B is sorted in ascending order.

// Input Format :
// • First line will contain T, number of testcases. Then the testcases follow.
// • First line of each testcase contains a single integer N.
// • Second line of each testcase contains N distinct integers : A1,A2...AN.

// Output Format :
// For each testcase, if it possible to move all the elements of array A to array B
// using the above operations such that finally, the array B is sorted in ascending
// order, print "YES" (without quotes), else print "NO" (without quotes).

#include <stdio.h>

int stack[100];
int size = 100;
int top = -1;

void push(int ch)
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

    return stack[top--];
    // printf("Popped element is: %c\n", stack[top--]);
}

int peek()
{

    return stack[top];
}

int isSorted(int b[], int n)
{

    for (int i = 1; i < n; i++)
    {

        if (b[i - 1] > b[i])
        {
            return 0;
        }
    }   

    return 1;
}

int solve(int a[], int n)
{

    int b[n];

    int j = 0;

    for (int i = 1; i < n; i++)
    {

        if (i == (n - 1))
        {
            push(a[i]);
            break;
        }

        push(a[i - 1]);

        if (peek() < a[i])
        {
            b[j++] = pop();
        }
    }

    while (top != -1)
    {
        b[j++] = stack[top--];
    }

    return isSorted(b, n);
}

void main()
{

    int n, t;

    printf("Enter Number Of tescase : \n");
    scanf("%d", &t);

    while (t != 0)
    {

        printf("Enter size n : \n");
        scanf("%d", &n);
        int a[n];

        for (int i = 0; i < n; i++)
        {
            printf("Enter Elemet %d\n :", (i + 1));
            scanf("%d", &a[i]);
        }

        if (solve(a, n))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

        t--;
    }
}