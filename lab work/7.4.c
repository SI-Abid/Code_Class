#include "stdio.h"
//find prime in range n1 to n2
int is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            // puts("not Prime");
            return 0;
        }
    }
    // puts("Prime");
    return 1;
}
int main()
{
    int low, high;
    printf("Enter range: ");
    scanf("%d %d",&low,&high);
    for(int i=low;i<=high;i++)
    {
        printf(is_prime(i) ? "%d\n" : "", i);
        // puts(is_prime(i)? "Prime" : "not Prime");
    }
    return 0;
}