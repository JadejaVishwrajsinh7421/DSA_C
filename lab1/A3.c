#include<stdio.h>
void main(){
    char name;
    printf("enter letter :");
    scanf("%c",&name);

    if(name=='a' || name=='e' || name=='i' || name=='o' || name=='u' ||
       name=='A' || name=='E' || name=='I' || name=='O' || name=='U'){
        printf("letter is vowel");
    }
    else{
        printf("letter is consonant");
    }
}