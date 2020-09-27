#include "stdio.h"
#define uc unsigned char

uc rotate_left(uc a)
{
    int mask=0x80;
    if(a&mask)
        return (a<<1)|1;
    return a<<1;
}

uc rotate_right(uc a)
{
    if(a&1)
        return (a>>1)|0x80;
    
    return a>>1;
}

int main()
{
    printf("%d\n", rotate_left(160));
    printf("%d\n", rotate_right(127));
    return 0;
}
// 1000 0000
// 8    0