//word
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
    cin >> s;
    int l = s.size();
    int lo=0, up=0;
    for(int i=0; i<l; i++)
    {
        if(isupper(s[i]))
            up++;
        else
            lo++;
    }
    char ch;
    if(up>lo)
        for(int i=0; i<l; i++)
        {
            ch=toupper(s[i]);
            cout<<ch;
        }

    else
        for(int i=0; i<l; i++)
        {
            ch=tolower(s[i]);
            cout<<ch;
        }

    cout<<endl;
}
int main()
{
    solve();
    return 0;
}
