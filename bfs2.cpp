#include "bits/stdc++.h"

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

int grid[999][999];

using namespace std;
int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int t;
    for(cin>>t;t;t--)
    {
        memset(grid, 0, sizeof(grid));
        int m, n;
        cin>>m>>n;
        int x1, x2, y1, y2;
        x1 = y1 = 0;
        x2 = m-1, y2 = n-1;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>grid[i][j];
            }
        }

    }

    return 0;
}
