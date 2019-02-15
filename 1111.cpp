#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
int visited[10001];
map<int, vector<int> >G;
int level[10001];
void bfs(int src)
{
    queue<int>q;
    level[src]=level[src]+1;
    //cout<<src<<' '<<level[src]<<endl;
    q.push(src);
    visited[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(!visited[v])
            {
                visited[v]=1;
                level[v]=level[v]+1;
                //cout<<v<<' '<<level[v]<<endl;
                q.push(v);
            }
        }
        q.pop();
    }
}
int main()
{
    int t, k, n, m, i, j, l;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d%d",&k,&n,&m);
        int a[k+2];
        for(j=1; j<=k; j++)
        {
            cin>>l;
            if(l<=n)
            {
                a[j]=l;
            }
        }
        for(j=1; j<=m; j++)
        {
            int u, v;
            cin>>u>>v;
            G[u].push_back(v);
        }
        for(j=1; j<=k; j++)
        {
            mem(visited,0);
            bfs(a[j]);
        }
        sort(level+1, level+n+1, greater<int>());
        int s=level[1];
        int ans=0;
        for(j=1; j<=n; j++)
        {
            //cout<<level[j]<<endl;
            if(s==level[j]&&level[j]>=k)
            {
                ans++;
            }
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
        G.clear();
        mem(level,0);
    }
    return 0;
}
