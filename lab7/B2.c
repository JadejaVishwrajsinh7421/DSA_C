// 44. Write a program for evaluation of prefix Expression using Stack.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int stack[100];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

void evaluate_prefix(char prefix[]){

    for(int i=0 ; i < strlen(prefix) ; i++){

        if(isdigit(prefix[i])){
            push(prefix[i] - '0');
        }
        else{
            int operand1 = pop();
            int operand2 = pop();

            switch (prefix[i])
            {
            case '+' :
                push(operand1 + operand2);
                break;
            case '-' : 
                push(operand1 - operand2);
                break;            
            case '*' : 
                push(operand1 * operand2);
                break;
            case '/' :
                push(operand1/operand2);
                break;
            case '^' : 
                push(pow(operand1,operand2));
            }
        }
    }
}

void main(){
    char prefix[100];

    printf("Enter prefix Expression : ");
    scanf("%s" , prefix);

    strrev(prefix);

    evaluate_prefix(prefix);

    printf("Answer : %d",pop());

}