#include "stdio.h"
#define SET(arr, x)     memset(arr, x, sizeof(arr));

int main()
{
    // freopen("in.txt", "r", stdin);
    while(1)
    {
        int n;
        scanf("%d", &n);

        if(n==0)
            return 0;

        int a[n][n], row_sum[n], col_sum[n], i, j, oddcol, oddrow;

        SET(row_sum, 0);
        SET(col_sum, 0);

        for (i = 0; i < n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d", &a[i][j]);
                row_sum[i]+=a[i][j];
                col_sum[j]+=a[i][j];
            }
        }
        
        oddcol=-1, oddrow=-1;
        
        for(i=0; i<n; i++)
        {
            if(row_sum[i]&1)
            {
                if(oddrow== -1)
                {
                    oddrow=i;
                }
                else
                {
                    oddrow = -2;
                }
            }
            if(col_sum[i]&1)
            {
                if(oddcol==-1)
                {
                    oddcol=i;
                }
                else
                {
                    oddcol=-2;
                }
            }
        }
        
        if(oddcol==-1 && oddrow==-1)
        {
            puts("OK");
        }
        else if(oddcol!=-1 && oddrow!=-1 && oddcol!=-2 && oddrow!=-2)
        {
            printf("Change bit (%d,%d)\n", oddrow+1, oddcol+1);
        }
        else
        {
            puts("Corrupt");
        }
    }
    return 0;
}