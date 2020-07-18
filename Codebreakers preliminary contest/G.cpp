//HQ9+
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
    bool ok=false;
    cin>>s;
    int l=s.size();
    for(int i=0; i<l; i++)
        if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
            ok=true;
    ok?cout<<"YES\n":cout<<"NO\n";
}
int main()
{
    solve();
    return 0;
}
