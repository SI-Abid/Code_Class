//wrong subtraction
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
    int n, k;
    cin>>n>>k;
    while(k--)
    {
        if(n%10==0)
            n/=10;

        else
            n--;
    }
    cout<<n<<endl;
}
int main()
{
    solve();
    return 0;
}
