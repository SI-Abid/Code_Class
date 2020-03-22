//theater square
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
    ll n, m, a;
    cin>>n>>m>>a;
    ll c=n/a;
    ll d=m/a;
    if(n%a!=0)  c++;
    if(m%a!=0)  d++;
    cout<<c*d<<endl;
}
int main()
{
    solve();
    return 0;
}
