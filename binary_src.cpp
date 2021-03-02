#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define be begin()
#define en end()
#define all(x) (x).begin(),(x).end()

typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int INF = 1e9;
vi v;

int bs(vi a, int l, int r, int x)
{
    if(r>=l)
    {
        int mid=l+(r-l) /2; // 0+18/2=9 0->18 // 4

        if(a[mid]==x) //a[9]=10 !=8 [4]= 5
        {
            return mid;
        }
        if(a[mid]>x)    // 10>8
        {
            return bs(a, l, mid-1, x); // 0 - 8
        }
        return bs(a, mid+1, r, x);
    }
    return -1;
}

void solve()
{
    int n;
    cin>>n;
    cout<<"    "<<bs(v,0,v.size()-1, n)<<endl;
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    srand(time(NULL));

    for(int i=0; i<10000000; i++)
    {
        v.pb(2*i+1);
    }

    int t;
    for(cin>>t;t;t--)
        solve();

    return 0;
}

/*
1 2 3 4  5     6 7 8   9   10 11      12    13    14 15       16 17 18 19
*/