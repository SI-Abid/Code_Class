#include "bits/stdc++.h"
using namespace std;

vector<int> *adjlist, *revlist;
bool *vis;
stack<int> S;
string scc="";

void addedges(vector<int> *(&v), int x, int y)
{
    v[x].push_back(y);
}

void dfs_2nd(int r)
{
    vis[r]=true;
    scc+=to_string(r);
    for(auto x:revlist[r])
    {
        if(!vis[x])
        {
            dfs_2nd(x);
        }
    }
    scc+=" ";
}

void dfs(int r)
{
    vis[r] = true;

    for (auto x : adjlist[r])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
    S.push(r);
}

int main()
{
    //-------------------------TOPOLOGICAL SORT---------------------
    puts("------TOPOLOGICAL SORT------");
    int node, edge;
    cout << "Number of vertices: ";
    cin >> node;
    cout << "Number of edges: ";
    cin >> edge;
    adjlist = new vector<int>[node + 1]();
    vis = new bool[node + 1];
    int p, q;
    for (int i = 0; i < edge; i++)
    {
        cin >> p >> q;
        addedges(adjlist, p, q);
    }

    int root;
    cout << "Enter root vertex: ";
    cin >> root;

    for (int i = 1; i < node + 1; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    while (!S.empty())
    {
        int s = S.top();
        cout << s << " ";
        S.pop();
    }
    cout << endl;
    delete [] adjlist;
    delete vis;
    //-----------------------STRONGLY CONNECTED COMPONENT------------------
    puts("------STRONGLY CONNECTED COMPONENT------");
    cout << "Number of vertices: ";
    cin >> node;
    cout << "Number of edges: ";
    cin >> edge;
    adjlist = new vector<int>[node + 1];
    revlist = new vector<int>[node + 1];
    vis = new bool[node + 1];
    
    for (int i = 0; i < edge; i++)
    {
        cin >> p >> q;
        addedges(adjlist, p, q);
        addedges(revlist, q, p);
    }

    for (int i = 1; i < node+1; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    memset(vis, false, node+1);
    while(!S.empty())
    {
        int s=S.top();
        if(!vis[s])
            dfs_2nd(s);
        S.pop();
    }
    cout<<"Strongly Connected Components are: "<<scc<<endl;
}