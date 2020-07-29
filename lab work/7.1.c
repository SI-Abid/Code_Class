#include "stdio.h"
// factorial
int main()
{
    int n, f=1;
    printf("N = ");
    scanf("%d",&n);
    while(n>0)
    {
        f*=n--;
    }
    printf("Factorial = %d\n",f);
    return 0;
}