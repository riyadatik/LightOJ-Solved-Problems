#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define mem(x,y) memset(x,y,sizeof(x))
#define infinity 1000000000
#define uu first
#define vv second
map<int, vector<int> >G, cost;
int node, n;
int visited[30001], level[30001];
int bfs(int src)
{
    int max_cost=0;
    vector<pii>d;
    queue<int>q;
    level[src]=0;
    visited[src]=1;
    d.push_back(pii(0,src));
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        for(int k=0; k<G[u].size(); k++)
        {
            int v=G[u][k];
            if(visited[v]==0)
            {
                level[v]=cost[u][k]+level[u];
                d.push_back(pii(level[v],v));
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    sort(d.begin(),d.end(),greater<pii>());
    max_cost=d[0].uu;
    node=d[0].vv;
    return max_cost;
}
int main()
{
    int t, i, j, k, src;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n;
        for(j=1; j<n; j++)
        {
                int u, v, x;
                cin>>u>>v>>x;
                if(j==1)
                {
                    src=u;
                }
                G[u].push_back(v);
                G[v].push_back(u);
                cost[u].push_back(x);
                cost[v].push_back(x);
        }

        int max_cost, sc;
        sc=bfs(src);
        mem(visited,0);
        mem(level,0);
        max_cost=bfs(node);
        cout<<"Case "<<i<<": "<<max_cost<<endl;
        G.clear();
        cost.clear();
        mem(visited,0);
    }
    return 0;
}
