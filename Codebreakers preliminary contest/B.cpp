//soldier and banannas
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
    int k, n, w;
    cin>>k>>n>>w;
    int total=0;
    for(int i=1; i<=w; i++)
    {
        total += (k*i);
    }
    if(total>n)
        cout<<total-n<<endl;
    else
        cout<<"0\n";
}
int main()
{
    solve();
    return 0;
}
