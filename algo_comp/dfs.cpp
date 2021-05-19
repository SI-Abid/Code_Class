#include "bits/stdc++.h"
using namespace std;

vector<int> *adjlist;
bool *vis;

void addedges(int x, int y)
{
    adjlist[x].push_back(y);
}

void dfs(int r)
{
    vis[r]=true;
    cout<<r<<" --> ";
    for(auto x: adjlist[r])
    {
        if(!vis[x])
        {
            dfs(x);
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    int node, edge;
    cout << "Number of vertices: ";
    cin >> node;
    cout << "Number of edges: ";
    cin >> edge;
    adjlist = new vector<int>[node + 1];
    vis = new bool[node + 1];
    int p, q;
    for (int i = 0; i < edge; i++)
    {
        cin >> p >> q;
        addedges(p, q);
    }

    int root;
    cout << "Enter root vertex: ";
    cin >> root;

    dfs(root);
    cout<<endl;
}