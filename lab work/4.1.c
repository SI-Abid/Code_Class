// Print the fibonacci series
// 0 1 1 2 3 5 8 13 21
#include<stdio.h>
 
int main()
{
    int n, i=0, j=1, fib=0;
    printf("Enter a number ");
    scanf("%d",&n);
    int x;
    for(x=0; x<n; x++)
    {
        fib=i;
        printf("%d\n", fib);
        i=j;
        j=fib+i;
    }

    return 0;
}