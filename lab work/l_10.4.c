#include "stdio.h"

long long power2(int number, int pow)
{
    return number * (1<<pow);
}

int main()
{
    int n, p;
    scanf("%d%d",&n,&p);
    printf("%lld", power2(n, p));
    return 0;
}