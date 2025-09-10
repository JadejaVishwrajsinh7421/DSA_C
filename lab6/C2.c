// 39.Merge Intervals Problem
// Given a set of time intervals in any order, our task is to merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals.
// Sample Example-1:
// Input: Intervals = {{1,3},{2,4},{6,8},{9,10}}
// Output: {{1, 4}, {6, 8}, {9, 10}}
// Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], [9,10]
// Sample Example-2:
// Input: Intervals = {{6,8},{1,9},{2,4},{4,7}}
// Output: {{1, 9}}

#include <stdio.h>

struct Interval
{
    int st, end;
};
int size = 100;
int stack[100];
int top = -1;

void push(int ch)
{

    if (top >= size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = ch;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[top--];
}

void sortIntervals(struct Interval arr[], int n)
{
    struct Interval temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].st > arr[j].st)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void merge(struct Interval arr[], struct Interval ans[], int n, int *count)
{
    sortIntervals(arr, n);
   
    push(arr[0].st);
    push(arr[0].end);
    // int count=0;

    for (int i = 1; i < n; i++)
    {
        if (stack[top] >= arr[i].st)
        {
            if (stack[top] < arr[i].end)
            {
                int x = pop();
                push(arr[i].end);
            }
        }
        else
        {

            ans[*count].end = pop();
            ans[*count].st = pop();
            (*count)++;
            // index++;
            // arr[index]=arr[i];
            push(arr[i].st);
            push(arr[i].end);
        }
    }
    ans[*count].end = pop();
    ans[*count].st = pop();
    (*count)++;
}

void display(int count, struct Interval ans[])
{
    // if (top == -1){
    //     printf("Stack is empty\n");
    //     return;
    // }
    printf("Stack elements are:\n");
    for (int i = 0; i < count; i++)
    {
        printf("{%d,%d}", ans[i].st, ans[i].end);
    }
}

int main()
{
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval arr[n];
    struct Interval ans[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter start and end of interval %d: ", i + 1);
        scanf("%d %d", &arr[i].st, &arr[i].end);
    }
    int count = 0;
    merge(arr, ans, n, &count);
    display(count, ans);
    return 0;
}