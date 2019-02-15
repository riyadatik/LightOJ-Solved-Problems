#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define infinity 1000000000
#define pii pair<int ,int>
#define uu first
#define vv second
map<int, vector<int> >G, cost;
int node, n;
int dijkstra(int src, int n)
{
    int d[102];
    for(int i=0; i<102; i++)
    {
        d[i]=infinity;
    }
    priority_queue<pii>q;
    q.push(pii(0,src));
    d[src]=0;
    while(!q.empty())
    {
        pii top=q.top();
        int u=top.vv;
        if(u==n)
        {
            return d[n];
        }
        for(int k=0; k<G[u].size(); k++)
        {
            int v=G[u][k];
            if(d[u]+cost[u][k]<d[v])
            {
                d[v]=d[u]+cost[u][k];
                q.push(pii(-d[v],v));
            }
        }
        q.pop();
    }
    return -1;
}
int main()
{
    int t, i, j, n, m, src;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n>>m;
        for(j=1; j<=m; j++)
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
        int res=dijkstra(1,n);
        printf("Case %d: ",i);
        if(res==-1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n",res);
        }
        G.clear();
        cost.clear();
    }
    return 0;
}
