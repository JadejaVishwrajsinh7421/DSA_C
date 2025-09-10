// 43. Write a program for evaluation of postfix Expression using Stack.

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

void evaluate_Postfix(char postfix[]){

    for(int i=0 ; i < strlen(postfix) ; i++){

        if(isdigit(postfix[i])){
            push(postfix[i] - '0');
        }
        else{
            int operand2 = pop();
            int operand1 = pop();

            switch (postfix[i])
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
    char postfix[100];

    printf("Enter Postfix Expression : ");
    scanf("%s" , postfix);

    evaluate_Postfix(postfix);

    printf("Answer : %d",pop());

}