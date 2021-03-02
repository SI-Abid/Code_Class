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

int cats[100000];
vi edges[100000];
bool visited[100000];
int catcnt[100000];
int cnt[100000];
int m, res=0;

void add_edge(int, int);
void dfs(int, int);

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>cats[i];
    }
    for(int i=0; i<n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        add_edge(x-1, y-1);
    }
    dfs(0,cats[0]);
    cout<<res<<endl;
    return 0;
}

void add_edge(int v, int w)
{
    edges[v].pb(w);
    edges[w].pb(v);
}

void dfs(int s, int cc)
{
    visited[s]=true;
    // cout<<cc<<" "<<s+1<<endl;
    for(auto it:edges[s])
    {
        if(!visited[it])
        {
            if(cats[it]==0)
                dfs(it, 0);        
            else if(cc+cats[it]<=m)
                dfs(it, cc+cats[it]);

        }
    }
    if(edges[s].size()==1 && cc<=m && s!=0)  //if node is leaf
    {
        res++;
    }
}