#include "bits/stdc++.h"
#define Sort(a)     sort(a.begin(), a.end())
#define Revs(a)     sort(a.rbegin(), a.rend())
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for (auto &x: a)
    {
        cin>>x;
    }
    for(auto &x: b)
    {
        cin>>x;
    }
    Revs(a);
    Sort(b);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]+b[i];
        if(i<n-1)
            cout<<" ";
    }
    return 0;
}