#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n&1)
        {
            ll x=n/2+1;
            cout<<x*x<<endl;
        }
        else
        {
            ll x=n/2;
            cout<<x*(x+1)<<endl;
        }
    }
    return 0;
}