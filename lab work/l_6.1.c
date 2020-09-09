#include "stdio.h"
#include "string.h"

int main()
{
    int row=3, col=3;
    int mat[row][col], row_sum[row], col_sum[col];
    memset(row_sum, 0, sizeof(row_sum));
    memset(col_sum, 0, sizeof(col_sum));
    
    puts("The matrix elements are:");
    
    for(int i=0; i<row; i++)
    {
        printf("\t");
        for(int j=0; j<col; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            row_sum[i]+=mat[i][j];
        }
        printf("Sum of row %d: %d\n", i+1, row_sum[i]);
    }
    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            col_sum[i]+=mat[j][i];
        }
        printf("Sum of column %d: %d\n", i+1, col_sum[i]);
    }
    return 0;
}