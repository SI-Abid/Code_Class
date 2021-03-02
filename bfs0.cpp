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

using namespace std;

vi *adj;

void addedge(int v, int w)
{
    adj[v].pb(w);
    adj[w].pb(v);
}

void bfs(int s)
{
    int v = sizeof(adj);
    bool visited[v+1];
    memset(visited, false, v+1);
    int level[v+1];
    memset(level, 0, v+1);
   
    queue<int> q;
    visited[s]=true;
    q.push(s);

    while(!q.empty())
    {
        s=q.front();
        cout<<s<<" ";
        q.pop();
        for(auto it:adj[s])
        {
            if(!visited[it])
            {
                level[it]=level[s]+1;
                visited[it]=true;
                q.push(it);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);

    
    int n, m, c, t;
    cin>>n>>m>>c>>t;
    adj = new vector<int>(n+1);
    while(m--)
    {
        int u, v;
        cin>>u>>v;
        addedge(u, v);
    }
    int x, y;
    cin>>x>>y;
    
    bfs(x);

    return 0;
}