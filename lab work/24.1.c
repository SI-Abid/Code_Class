#include "stdio.h"

int main()
{
    short int n, mask=0x8000;
    scanf("%hd", &n);
    while(mask)
    {
        printf((n & mask)?"1":"0");
        mask = mask>>1;
    }
    return 0;
}