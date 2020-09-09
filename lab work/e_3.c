#include "stdio.h"

#define min(a,b)    (a<b)?a:b

int main()
{
    int n;

    scanf("%d", &n);

    int size = 2*n-1, mini;
    for(int row=0; row<size; row++)
    {
        for(int col=0; col<size; col++)
        {
            mini = min(row, col);
            
            if(mini>=size-row)
            {
                mini = size-row-1;
            }
            if(mini>=size-col)
            { 
                mini = size-col-1;
            }
            printf("%d ", n-mini);
        }
        puts("");
    }

    return 0;
}