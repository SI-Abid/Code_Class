#include "stdio.h"

int fibonacci(int n)
{
    if(n==0 || n==1)    return n;
 
    return fibonacci(n-1) + fibonacci(n-2);

}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%dth fibonacci is %d\n", n, fibonacci(n));
}