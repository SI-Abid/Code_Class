/*
number diamond
n = 3
        0
      0 1 0
    0 1 2 1 0
  0 1 2 3 2 1 0
    0 1 2 1 0
      0 1 0
        0  
*/
#include "stdio.h"

int main()
{
    int n;
    // printf("n = ");
    scanf("%d", &n);

    for(int i=0;i<=n;i++)
    {
        int sp=2*(n-i);
        while(sp--)
        {
            printf("  ");
        }
        int a=0;
        while(a<=i)
        {
            printf("%d",a++);
            if(a!=i)
            printf(" ");
        }
        a--;
        while(a<=0)
        {
            printf(" %d",a--);
        }
        puts("");
    }
    for(int i=n-1;i>=0;i--)
    {
        int sp=2*(n-i);
        while(sp--)
        {
            printf("  ");
        }
        int a=0;
        while(a<=i)
        {
            printf("%d",a++);
            if(a!=i)
            printf(" ");
        }
        a--;
        while(a<=0)
        {
            printf(" %d",a--);
        }
        puts("");
    }
    // {
    //     int s=2*(n-i+1);
    //     while(s--)
    //     {
    //         printf(" ");
    //     }
    //     int a=0;
    //     while(a<i)
    //     {
    //         printf((i=1)?"%d":"%d ",a++);
    //     }
    //     a=i-1;
    //     while(a>=0)
    //     {
    //         printf((a==0)?"%d":"%d ",a);
    //         a--;
    //     }
    //     puts("");
    // }
    // for(int i=n-1;i>=0;i--)
    // {
    //     int s=2*(n-i);
    //     while(s--)
    //     {
    //         printf(" ");
    //     }
    //     int a=0;
    //     while(a<=i)
    //     {
    //         printf((i==0)?"%d":"%d ",a);
    //         a++;
    //     }
    //     a-=2;
    //     while(a>=0)
    //     {
    //         printf((a==0)?"%d":"%d ",a);
    //         a--;
    //     }
    //     puts("");
    // }
    return 0;
}