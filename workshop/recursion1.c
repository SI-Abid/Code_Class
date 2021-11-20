#include<stdio.h>
//  node         1  2  3  4  5
int par[] = {-1, 0, 1, 4, 1, 3};

void print(int n)
{
    if(par[n]>0)
        print(par[n]);

    printf("%d ",n);
}


int main()
{
    print(5);
    puts("");
    return 0;
}