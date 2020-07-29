#include "stdio.h"
//find prime
int is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            // puts("Not prime");
            return 0;
        }
    }
    // puts("Prime");
    return 1;
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    puts(is_prime(n)? "Prime" : "Not prime");
    return 0;
}