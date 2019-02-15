#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int ,int>
int fx[]={-1,0,0,+1};
int fy[]={0,-1,+1,0};
char G[505][505];
int visited[505][505], dp[505][505];
int n, m;
void bfs(int i, int j, int value)
{
    queue<pii>q;
    q.push(pii(i,j));
    dp[i][j]=value;
    while(!q.empty())
    {
        pii top=q.front();
        for(int k=0; k<4; k++)
        {
            int tx=top.first+fx[k];
            int ty=top.second+fy[k];
            if(G[tx][ty]!='#'&&tx>=1&&tx<=m&&ty>=1&&ty<=n&&dp[tx][ty]==-1)
            {
                dp[tx][ty]=value;
                q.push(pii(tx,ty));
            }
        }
        q.pop();
    }
}
int bfs(int i, int j)
{
    queue<pii>q;
    int res=0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
        q.push(pii(i,j));
        visited[i][j]=1;
        while(!q.empty())
        {
            pii top=q.front();
            for(int k=0; k<4; k++)
            {
                int tx=top.first+fx[k];
                int ty=top.second+fy[k];
                if(G[tx][ty]!='#'&&tx>=1&&tx<=m&&ty>=1&&ty<=n&&visited[tx][ty]==0)
                {
                    visited[tx][ty]=1;
                    q.push(pii(tx,ty));
                    if(G[tx][ty]=='C')
                    {
                        res++;
                    }
                }
            }
            q.pop();
        }
        bfs(i,j,res);
    }
    return res;
}
int main()
{
    int t, i, j, k, q, c, d, ans;
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%d %d %d",&m,&n,&q);
        mem(dp,-1);
        for(i=1; i<=m; i++)
        {
            getchar();
            for(j=1; j<=n; j++)
            {
                scanf("%c",&G[i][j]);
            }
        }
        printf("Case %d:\n",k);
        for(i=1; i<=q; i++)
        {
            scanf("%d %d",&c,&d);
            ans=bfs(c,d);
            printf("%d\n",ans);
        }
        mem(visited,0);
    }
    return 0;
}
