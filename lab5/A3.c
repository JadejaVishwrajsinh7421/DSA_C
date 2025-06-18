#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//     . Design anagram game using array.
// • Allow a user to enter N words and store it in an array.
// • Generate a random number between 0 to N-1.
// • Based on the random number generated display the word stored at that
// index of an array and allow user to enter its anagram.
// • Check whether the word entered by the user is an anagram of displayed
// number or not and display an appropriate message.
// • Given a word A and word B. B is said to be an anagram of A if and only if
// the characters present in B is same as characters present in A,
// irrespective of their sequence. For ex: “LISTEN” == “SILENT”

// sort function (for ANAGRAM logic)
void sort(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void main()
{
    int n;
    printf("enter the number of string in the firt array");
    scanf("%d", &n);

    char arr[n][100];
    for (int i = 0; i < n; i++)
    {
        printf("enter a string in arr1");
        scanf("%s", arr[i]);
    }

    // random number logic
    srand(time(0));
    int index = rand() % n;
    printf("%s", arr[index]);

    // enter second string
    char guessWord[100];
    printf("enter second string");
    scanf("%s", guessWord);

    // check length is same or not
    int len1 = strlen(arr[index]);
    int len2 = strlen(guessWord);
    printf("show length %d %d", len1, len2);

    if (len1 != len2)
    {
        printf("given word is not anagram");
    }
    else
    {

        // sort the both string using function;
        sort(arr[index]);
        sort(guessWord);

        if (strcmp(arr[index], guessWord) == 0)
        {
            printf("Correct! It's an anagram.\n");
        }
        else
        {
            printf("Wrong! Not an anagram.\n");
        }
    }
}
