//way too long word
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
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int l = s.size();
        if(l>10)
            cout<<s[0]<<l-2<<s[l-1]<<endl;
        else
            cout<<s<<endl;
    }
}
int main()
{
    solve();
    return 0;
}
