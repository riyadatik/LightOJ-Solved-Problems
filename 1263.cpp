#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
vector<int>G[400000];
int visited[400000];
int cost[400000];
int node;
int bfs(int src)
{
    int sum;
    node=1;
    queue<int>q;
    q.push(src);
    visited[src]=1;
    sum=cost[src];
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(!visited[v])
            {
                visited[v]=1;
                sum=sum+cost[v];
                node++;
                q.push(v);
            }
        }
        q.pop();
    }
    return sum;
}
int main()
{
    int t, n, m, i, j;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        int sum=0, ans, res, flag=0, d;
        scanf("%d %d",&n,&m);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[j]);
            sum=sum+cost[j];
        }
        for(j=1; j<=m; j++)
        {
            int u, v;
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans=sum/n;
        printf("Case %d: ",i);
        if(ans*n!=sum)
        {
            printf("No\n");
        }
        else
        {
            for(j=1; j<=n; j++)
            {
                if(!visited[j])
                {
                    res=bfs(j);
                    d=res/node;
                    if(d!=ans||(d*node)!=res)
                    {
                        printf("No\n");
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                printf("Yes\n");
            }
        }
        mem(G,0);
        mem(visited,0);
        mem(cost,0);
    }
    return 0;
}
