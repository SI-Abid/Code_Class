#include "stdio.h"
#define ll long long

ll getsq(ll n)
{
    ll ret=0;
    while (n)
    {
        ret+=((n%10)*(n%10));
        n/=10;
    }
    return ret;
}

int solve(int n)
{
    int flag[100000]={0};
    while(1)
    {
        n = getsq(n);
        if(n==1)
        {
            return 1;
        }
        if(flag[n]==1)
        {
            return 0;
        }
        flag[n]=1;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf((solve(n))? "Happy\n":"Not Happy\n");
    }
    return 0;
}