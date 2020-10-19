#include "stdio.h"

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int m=n-i;
        while(m--)
        {
            printf("#");
        }
        int s=2*i+1;
        while(s--)
        {
            printf(" ");
        }
        m=n-i;
        while(m--)
        {
            printf("#");
        }
        puts("");
    }
    return 0;
}