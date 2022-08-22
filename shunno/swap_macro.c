#include<stdio.h>

#define swap(a,b) a^=b;b^=a;a^=b;
#define what_is(x) printf("%s is %d\n",#x,x);

int main()
{
    printf("Hello World!\n");
    
    int a = 10;
    int b = 25;

    what_is(a);
    what_is(b);

    swap(a,b);
    puts("After swapping a with b...");

    what_is(a);
    what_is(b);

    return 0;
}


