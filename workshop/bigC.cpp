#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    // vector<int> v;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        int digit=s[i]-'0';
        if(isalpha(s[i]))
        {
            digit=s[i]-'A'+10;
        }
        int exp=1;
        for(int j=i+1;j<s.size();j++)
        {
            exp*=36;
        }
        ans+=digit*exp;
    }
    cout<<ans<<"\n";
    return 0;
}