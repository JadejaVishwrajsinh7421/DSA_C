#include<stdio.h>
#include<stdlib.h>


void push() {
    if (top >= size - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    int data;
    printf("Enter the element to push: ");
    scanf("%d", &data);
    stack[++top] = data;
}

int pop() {
    if (top <= -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int val = stack[top--];
    return val;
}

void main(){

}