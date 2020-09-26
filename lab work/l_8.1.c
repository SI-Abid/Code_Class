#include "stdio.h"

int get_gcd(int a, int b)
{
    if(b==0)
        return a;
    
    return get_gcd(b, a%b);
}

int main()
{
    int x, y;
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);

    printf("GCD of %d and %d is %d\n", x, y, get_gcd(x, y));
    return 0;
}