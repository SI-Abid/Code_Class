#include <stdio.h>
int main ()
 
{
    int n, m, f ,i ;
    printf("n: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++);
    {
        m=n-i;
        while(m-->0)
        {
            printf(" ");
        }
        printf("/");
        f=(i-1)*2;
 
        if(i==n)
        {
            while (f--)
            {
            printf("_");
            }
        }
        else
        {
            while (f--)
            {
            printf(" ");
            }
        }
        printf ("\\ \n");
    }
    return 0;
}