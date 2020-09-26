#include "stdio.h"

void print(int n)
{
    if(n<1)
        return;
    
    print(n-2);
    printf("%d ", n);
}

int main()
{
    print(99);
    return 0;
}