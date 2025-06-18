#include <stdio.h>
void main()
{
    //     32. Read two matrices, first 3x2 and second 2x3, perform multiplication operation
    // and store result in third matrix and print it.

    int a[3][2], b[2][3], c[3][3];

    // read a and b matrices
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("enter the value in matrix a[%d] [%d] ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("enter the value in matrix b[%d] [%d] ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    // multiply
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            // for(int k=0;k<2;k++){

            //     c[i][j] += a[i][k] * b[j][k];
            // }
            for (int k = 0; k < 1; k++)
            {
                c[i][j] = a[i][k] * b[k][j] + a[i][k + 1] * b[k + 1][j];
            }
        }
    }

    // print c 
     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d",c[i][j]);
        }
        printf("\n");
    }
  

}