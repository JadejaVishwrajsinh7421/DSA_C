#include <stdio.h>
void main()
{
    //     31. Read two 2x2 matrices and perform addition of matrices into third matrix and
    // print it
    int a[2][2], b[2][2], c[2][2];

    // read a and b matrices
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("enter the value in matrix a[%d] [%d] ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("enter the value in matrix b[%d] [%d] ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    // add
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    // print c matrix
    printf("the sum of two matrix is:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
}
