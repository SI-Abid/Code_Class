#include "stdio.h"

int main()
{
    int n, m, f;
    printf("n: ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        m=n-i;
        while(m--)
        {
            printf(" ");
        }
        printf("/");
        f=(i-1)*2;
        
        if(i==n)
        {
            while(f--)
            {
                printf("_");
            }
        }
        else 
        {
            while(f--)
            {
                printf(" ");
            }
        }
        puts("\\");
    }

    return 0;
}