#include<bits/stdc++.h>
using namespace std;

#define pii pair<long long int ,long long int>
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
vector<int>G[30005],cost[30005];
int visited[30005], level[30005];
int n;
int bfs(int src)
{
    queue<int>q;
    int node, max_cost=0;
    level[src]=0;
    visited[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        for(int k=0; k<G[u].size(); k++)
        {
            int v=G[u][k];
            if(!visited[v])
            {
                level[v]=cost[u][k]+level[u];
                if(level[v]>max_cost)
                {
                    max_cost=level[v];
                    node=v;
                }
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    return node;
}
int main()
{
    int t, i, j, k, src;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);
        for(j=1; j<n; j++)
        {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            if(j==1)
            {
                src=u;
            }
            G[u].push_back(v);
            G[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int sc=bfs(src);
        mem(visited,0);
        mem(level,0);
        int node=bfs(sc);
        int l[30005];
        for(k=0; k<n; k++)
        {
            l[k]=level[k];
        }
        mem(visited,0);
        mem(level,0);
        int nd=bfs(node);
        printf("Case %d:\n",i);
        for(k=0; k<n; k++)
        {
            int cost1=abs(l[sc]-l[k]);
            int cost2=abs(l[node]-l[k]);
            int mx1=max(cost1,cost2);
            cost1=abs(level[node]-level[k]);
            cost2=abs(level[k]-level[nd]);
            int mx2=max(cost1,cost2);
            int mx=max(mx1,mx2);
            printf("%d\n",mx);
        }
        mem(G,0);
        mem(cost,0);
        mem(visited,0);
        mem(level,0);
    }
    return 0;
}
