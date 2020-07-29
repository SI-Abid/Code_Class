/*
print this    *
              **
              ***
              ****
              *****
*/
#include "stdio.h"

int main()
{
    // printf("*\n**\n***\n****\n*****\n");
    int i=1, j, n, k;
    scanf("%d",&n);
    while(i<=n)
    {
        j=1;
        k=n-i;
        while(k--)
        {
            printf(" ");
        }
        while(j <= 2*i-1)
        {
            printf("*");
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}