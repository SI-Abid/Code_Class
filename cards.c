#include "stdio.h"

int isprime(int n)
{
    if(n==1)
        return 0;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    char s[50];

    while(scanf("%d %s", &n, s))
    {
        for(int i=0; s[i]; i++)
        {
            if(s[i]=='R')
            {
                while(!isprime(i+1))
                    i++;
                printf("%d ", i+1);
            }
            else
            {
                while(isprime(i+1))
                    i++;
                printf("%d ", i+1);
            }
            
        }
        puts("");
    }
    return 0;
}