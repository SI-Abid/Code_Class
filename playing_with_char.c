#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char c,s[1000],sen[1000];
    scanf("%c%s%*c%[^\n]%*c",&c,s,sen);
    
    printf("%c\n%s\n%s", c,s,sen);
    return 0;
}