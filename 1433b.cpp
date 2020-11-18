#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> v;
        int n, x, cnt=0;
        cin>>n;
        while(n--)
        {
            cin>>x;
            v.push_back(x);
        }
        while(!v.back())
        {
            v.pop_back();
        }
        reverse(v.begin(), v.end());
        while(!v.back())
        {
            v.pop_back();
        }
        for(auto x:v)
        {
            if(x==0)    
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}