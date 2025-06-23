#include <stdio.h>
void main()
{
    //     55. WAP to define a C structure named Student (roll_no, name, branch and
    // batch_no) and also to access the structure members using Pointer.
    struct student
    {
        int rollno;
        int batchno;
        char name[20];
        char branch[10];
    };
    {
        struct student stu1;
        struct Student *ptr;
    }
}