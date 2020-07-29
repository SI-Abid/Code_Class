#include "stdio.h"
//gcd and lcm
int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
    {
        return gcd(b,a%b);
    }
}
int lcm(int a, int b)
{
    return(a*b)/gcd(a,b);
}
int main()
{
    int a, b;
    puts("Enter value of A and B");
    scanf("%d%d",&a,&b);
    printf("GCD is %d\nLCM is %d\n",gcd(a,b),lcm(a,b);
    return 0;
}