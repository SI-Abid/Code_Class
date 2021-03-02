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

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    
    char pos[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>pos[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(pos[i][j]=='.')
            {
                if((i+j)%2)
                    pos[i][j]='W';
                else 
                    pos[i][j]='B';
            }
        }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<pos[i][j];
        cout<<endl;
    }
    return 0;
}
