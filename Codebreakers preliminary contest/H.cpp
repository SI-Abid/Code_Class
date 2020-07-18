//nearly lucky number
//solved by saiham aka dCoder

#include "bits/stdc++.h"
#define vector <int> vi
#define pair <int, int> pii
#define map <int, int> mpi
#define push_back pb
#define make_pair mp
typedef long long ll;
typedef unsigned int uint;

using namespace std;
void solve()
{
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='4' || s[i]=='7')
            cnt++;
    }
    if(cnt==4 || cnt==7)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main()
{
    solve();
    return 0;
}
