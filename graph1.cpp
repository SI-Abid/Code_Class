// A simple representation of graph using STL 
// #include<bits/stdc++.h> 
// using namespace std; 

// vector<int> *adj;

// void add_edge(int v, int w)
// {
//     adj[v].push_back(w);
//     adj[w].push_back(v);
// }

// void bfs(int s)
// {
//     int v=sizeof(adj);
//     // cout<<v<<endl;
//     bool visited[v+1];
//     memset(visited, false, v+1);
    
//     queue<int> q;

//     visited[s] = true;
//     q.push(s);

//     while(!q.empty())
//     {
//         s=q.front();
//         cout<<s<<" ";
//         q.pop();

//         for(auto i:adj[s])
//         {
//             if(!visited[i])
//             {
//                 visited[i]=true;
//                 q.push(i);
//             }
//         }
//     }
// }

#include "bits/stdc++.h"
using namespace std;

vector<int> *adj;

void addedge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void bfs(int s)
{
    int v = sizeof(adj);
    bool visited[v+1];
    memset(visited, false, v+1);
    
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
                visited[it]=true;
                q.push(it);
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int v, e;
        cin>>v>>e;
        adj = new vector<int>[v+1];
        while(e--)
        {
            int x, y;
            cin>>x>>y;
            addedge(x, y);
        }
        bfs(0);
        adj->clear();
        puts("");
    }
    return 0;
}