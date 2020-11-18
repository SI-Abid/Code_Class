#include "bits/stdc++.h"

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<int> div;
        for(int i=2; i*i<=n; i++)
        {
            if(n%i==0 && div.count(i)==0)
            {
                div.insert(i);
                n /=i;
                break;
            }
        }
        for(int i=2; i*i<=n; i++)
        {
            if(n%i==0 && div.count(i)==0)
            {
                div.insert(i);
                n /=i;
                break;
            }
        }
        if(div.size()<2 || div.count(n) || n==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            div.insert(n);
            for(auto i:div)
            {
                cout<<i<<" ";
            }
            puts("");
        }
        
    }
    return 0;
}