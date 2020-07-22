#include"bits/stdc++.h"
using namespace std;
//we are using recursion in this code
void solve(int t)
{
    if(t==0)
        return;
    
    int n;
    cin>>n;
    
    (n&1) ? cout<<"odd\n" : cout<<"even\n";
    
    solve(t-1);
}

int main()
{
    int t;
    cin>>t;
    solve(t);
    return 0;
}