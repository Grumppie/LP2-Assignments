#include "bits/stdc++.h"
using namespace std;
const int N=100;

bool vis[N];
vector<int> adj[N];

void recursive_bfs()
{
    int node=q.front();
        q.pop();
        cout<<node<<endl;
        vector<int>::iterator it;
        for(it=adj[node].begin(); it!=adj[node].end(); it++)
        {
            if(!vis[*it])
            {
                vis[*it]=1;
                q.push(*it);
            }
        }
}


int main()
{
    for(int i=0;i<N;i++)
        vis[i]=0;
    int n,m;
        cout<<"Enter the edges"<<endl;

    cin>> n >> m;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1]=true;

    while(!q.empty())
    {

        recursive_bfs();
        // int node=q.front();
        // q.pop();
        // cout<<node<<endl;
        // vector<int>::iterator it;
        // for(it=adj[node].begin(); it!=adj[node].end(); it++)
        // {
        //     if(!vis[*it])
        //     {
        //         vis[*it]=1;
        //         q.push(*it);
        //     }
        // }
    }

    return 0;
}