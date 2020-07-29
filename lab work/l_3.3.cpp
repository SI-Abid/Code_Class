#include "stdio.h"

int main()
{
    int n, m, i, j;
    char c = 'a';
    printf("n: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        m=n-i;
        while(m--)
        {
            printf(" ");
        }

        for(j=1; j<=i; j++)
        {
            printf("%c",c);
        }
        
        (c=='z') ? c='a' : c++;         //ternary operator
    
        printf("\n");
    }
    return 0;
}