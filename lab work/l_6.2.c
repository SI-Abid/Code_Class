#include "stdio.h"

int main()
{
    int row=3, col=3;
    puts("Original matrix:");
    int mat[row][col], tran[row][col];

    for(int i=0; i<row; i++)
    {
        printf("\t");
        for(int j=0; j<col; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    puts("Transpose matrix:");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            tran[i][j]=mat[j][i];
            printf("\t%d", tran[i][j]);
        }
        puts("");
    }
    return 0;
}