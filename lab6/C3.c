// 40. Vowel Anxiety Problem 
// Utkarsh has recently started taking English-language classes to improve his 
// reading and writing skills. However, he is still struggling to learn English. His 
// teacher gave him the following problem to improve his vowel-identification 
// skills:  
 
// There is a string S of length N consisting of lowercase English letters only.  
// Utkarsh has to start from the first letter of the string. 
// Each time he encounters a vowel; he has to reverse the entire substring that 
// came before the vowel. 
// Utkarsh needs help verifying his answer. Can you print the final string after 
// performing all the operations for him? 
 
// Input Format: 
// • First line will contain T, number of test cases. Then T test cases follow. 
// • The first line of each test case contains N, the length of the string. 
// • The second line contains S, the string itself. 
 
// Output Format: 
// For each test case, output in a single line the final string after traversing S from 
// left to right and performing the necessary reversals. 

#include <stdio.h>
#include <string.h>

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
    printf("Ans :\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
}

char peep(int idx)
{
    if (idx <= 0 || idx > top + 1)
    {
        printf("Invalid index. Stack Underflow.\n");
        return -1;
    }

    // printf("Peep %dth Element from Top is: %d\n", stack[top - idx + 1]);

    return stack[top - idx + 1];
}

void reverse(){
    for(int i=0 ; i<=top/2 ; i++){
        char temp = stack[i];
        stack[i] = stack[top-i];
        stack[top-i] = temp;
    }
}

void VowelAnxiety(char str[]){   

    int i=0;

    push(str[i++]);   // for 0th index

        while(str[i] != '\0'){

            

            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
            || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
             
                reverse();
                push(str[i]);                
                         
            }
            else{
                push(str[i]);
            }
            i++;
        }

        display();

    }

// public String VowelAnxiety(String s) {
        
//         StringBuilder sb = new StringBuilder();

//         for(char ch : s.toCharArray()){

//             if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
//             || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
             
//                     sb.reverse();
                
//                          
//             }
//             else{
//                 sb.append(ch);
//             }
//         }

//         return sb.toString();
//     }


void main(){

    char str[100];

    printf("Enter String.\n");
    scanf("%s", str);

    VowelAnxiety(str);
}