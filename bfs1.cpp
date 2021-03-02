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

bool visited[100][100];
string khoni[100];
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
int m, n;

void grid(int, int);
//
int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    // int x, y;
    while(cin>>m>>n && m+n!=0)
    {
        memset(visited, false, sizeof(visited));
        string s;
        for(int i=0; i<m; i++)
        {
            cin>>khoni[i];
        }
        int cnt=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j] && khoni[i][j]=='@')
                {
                    cnt++;
                    grid(i, j);
                }
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}

void grid(int x, int y)
{
    visited[x][y]=true;
    for(int a=0; a<8; a++)
    {
        int x1=x+dx[a];
        int y1=y+dy[a];
        
        if(x1>=0 && x1<m && y1>=0 && y1<n && !visited[x1][y1] && khoni[x1][y1]=='@')
            grid(x1, y1);   
        
    }
}