#include "stdio.h"

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        for(int j=n; j>=i; j--)
        {
            printf("%d ", i);
        }
        puts("");
    }
    return 0;
}