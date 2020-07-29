#include <stdio.h>

int main()
{
    int n=0;

    do
    {
        n++;
        if(n%4==0)
            continue;

        printf("%d\n", n);
        
    } while (n<20);
    
    return 0;
}