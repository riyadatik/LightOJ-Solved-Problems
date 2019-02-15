#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<int, int>
#define sc scanf
#define pf printf
#define pb push_back
#define uu first
#define vv second
#define DIST(x1,y1,x2,y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
vector<int>G[10005];
int dsc[10005], low[10005], onstk[10005], scc[10005];
stack<int>stk;
int c, cnt;
int vis[10005], ind[10004];
void targan(int u)
{
    c++;
    dsc[u]=c;
    low[u]=c;
    stk.push(u);
    onstk[u]=1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(dsc[v]==-1)
        {
            targan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(onstk[v])
        {
            low[u]=min(dsc[v],low[u]);
        }
    }
    if(low[u]==dsc[u])
    {
        cnt++;
        int v;
        do{
            v=stk.top();
            stk.pop();
            scc[v]=cnt;
            onstk[v]=0;
        }while(u!=v);
    }
}
void dfs(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!vis[v]&&scc[u]==scc[v])
        {
            vis[v]=1;
            dfs(v);
        }
        else if(scc[u]!=scc[v])
        {
            ind[scc[v]]++;
        }
    }
}
int main()
{
    int t, n, m, i, j;
    sc("%d",&t);
    for(i=1; i<=t; i++)
    {
        mem(dsc,-1);
        int ans=0;
        cnt=0;
        sc("%d%d",&n,&m);
        for(j=1; j<=m; j++)
        {
            int u, v;
            sc("%d%d",&u,&v);
            G[u].pb(v);
        }
        for(j=1; j<=n; j++)
        {
            c=0;
            if(dsc[j]==-1)
            {
                targan(j);
            }
        }
        for(j=1; j<=n; j++)
        {
            if(!vis[j])
            {
                vis[j]=1;
                dfs(j);
            }
        }
        for(j=1; j<=cnt; j++)
        {
            cout<<ind[j]<<' ';
            if(ind[j]==0)
            {
                ans++;
            }
        }
        pf("Case %d: %d\n",i,ans);
        mem(G,0);
        mem(vis,0);
        mem(low,0);
        mem(scc,0);
        mem(ind,0);
    }
    return 0;
}
