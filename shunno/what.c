#include<stdio.h>

#define what_is(x) printf("%s is %d\n",#x,x);

int main()
{
    char a = 'a';
    what_is(a);

    int x = 100;
    what_is(x);
    
    return 0;
}


