#include "stdio.h"

int x;

void func();

int main()
{
    x=10;
    printf("x in main %d\n",x);
    func();
    printf("x in main %d\n",x);
    return 0;
}

void func()
{
    int x=20;
    printf("x in func() %d\n",x);
}