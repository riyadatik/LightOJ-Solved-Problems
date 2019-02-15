#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<int ,int>
#define uu first
#define vv second
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
char G[22][22];
int visited[22][22];
int level[22][22];
int m, n;
int bfs(int s1, int s2, int d1, int d2)
{
    queue<pii>q;
    q.push(pii(s1,s2));
    visited[s1][s2]=1;
    level[s1][s2]=0;
    while(!q.empty())
    {
        pii top=q.front();
        int u=top.uu;
        int v=top.vv;
        if(u==d1&&v==d2) return level[d1][d2];
        for(int i=0; i<4; i++)
        {
            int tx=top.uu+fx[i];
            int ty=top.vv+fy[i];
            if(!visited[tx][ty]&&G[tx][ty]!='#'&&G[tx][ty]!='m')
            {
                visited[tx][ty]=1;
                level[tx][ty]=level[u][v]+1;
                q.push(pii(tx,ty));
            }
        }
        q.pop();
    }
}
int main()
{
    int t, i, j, k, c, ans, res;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        vector<pii>v;
        int d1, d2;
        ans=0;
        scanf("%d %d",&m,&n);
        for(j=1; j<=m; j++)
        {
            getchar();
            for(k=1; k<=n; k++)
            {
                scanf("%c",&G[j][k]);
                if(G[j][k]=='a'||G[j][k]=='b'||G[j][k]=='c')
                {
                    v.push_back(pii(j,k));
                }
                if(G[j][k]=='h')
                {
                    d1=j;
                    d2=k;
                }
            }
        }
        for(j=0; j<v.size(); j++)
        {
            int s1=v[j].uu;
            int s2=v[j].vv;
            res=bfs(s1,s2,d1,d2);
            ans=max(ans,res);
            mem(visited,0);
            mem(level,0);
        }
        mem(G,0);
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
