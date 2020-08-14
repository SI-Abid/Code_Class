#include "stdio.h"

int is_prime(int n);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(is_prime(n))
    {
        puts("Prime");
    }
    else
    {
        puts("Not prime");
    }
    return 0;
}

int is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}