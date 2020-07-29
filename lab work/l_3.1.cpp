#include<stdio.h>
int main()
{
    int i, n, m;
    printf("n: ");
    scanf("%d",&n);
    for(m=1;m<=n;m++)           // top half of the shape
    {
        int k=n-m;
        while(k--)
        {
            printf(" ");        
        }
        for(i=1 ; i<=2*m-1 ; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    for(m=n ; m>=1 ; m--)           // bottom half of the shape
    {
        int k=n-m+1;
        while(k--)
        {
            printf(" ");
        }
        for(i=2*m-3 ; i>=1 ; i--)
        {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}