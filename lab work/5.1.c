//print all number from 1 to 100
//except those that are divisable by 3 or 5
//but not both
#include "stdio.h"

int main()
{
    int i;
    for(i=1; i<=100; i++)
    {
        if(i%3==0 ^ i%5==0)     //use xor
            continue;
            
        printf("%d\n", i);
    }
    return 0;
}
