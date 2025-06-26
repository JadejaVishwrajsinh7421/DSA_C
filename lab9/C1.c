
    //     55. WAP to define a C structure named Student (roll_no, name, branch and
    // batch_no) and also to access the structure members using Pointer.
#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    char branch[30];
    int batch_no;
};

int main() {
    struct Student s1;
    struct Student *ptr;

    ptr = &s1;

    printf("Enter Roll Number: ");
    scanf("%d", &ptr->roll_no);

    printf("Enter Name: ");
    scanf(" %[^\n]", ptr->name);  

    printf("Enter Branch: ");
    scanf(" %[^\n]", ptr->branch);

    printf("Enter Batch Number: ");
    scanf("%d", &ptr->batch_no);

    // Displaying the values
    printf("\n--- Student Details ---\n");
    printf("Roll Number: %d\n", ptr->roll_no);
    printf("Name: %s\n", ptr->name);
    printf("Branch: %s\n", ptr->branch);
    printf("Batch Number: %d\n", ptr->batch_no);

    return 0;
}
