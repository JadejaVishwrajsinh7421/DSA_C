#include <stdio.h>
#include <string.h>
void main()

{
    // WAP to replace lowercase characters by uppercase & vice-versa in a user
    // specified string.

    char str1[100], str2[100];
    printf("Enter a string: ");
    gets(str1);
    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            str2[i] = str1[i] - 32;
        }
        else if (str1[i] >= 'A' && str1[i] <= 'Z')
        {
            str2[i] = str1[i] + 32;
        }
        else
        {
            str2[i] = str1[i];
        }
        i++;
    }
    str2[i] = '\0';
    printf("Modified string: %s\n", str2);
}