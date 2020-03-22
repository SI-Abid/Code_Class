//football
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
    int o=0,z=0, l=s.size();
    bool dang=false;
    for(int i=0; i<l; i++)
    {
        if(s[i]=='0')
        {
            z++;
            o=0;
        }
        else
        {
            o++;
            z=0;
        }
        if(o==7 || z==7)
        {
            dang=true;
            break;
        }
    }
    if(dang)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main()
{
    solve();
    return 0;
}
