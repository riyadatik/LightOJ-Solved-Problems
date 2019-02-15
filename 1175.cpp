#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<int ,int>
#define uu first
#define vv second
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int visited[205][205], level[205][205];
int llv[100005];
char G[205][205];
int r, c;
vector<pii>vc;
int bfs(int s1, int s2)
{
    queue<pii>q;
    q.push(pii(s1,s2));
    visited[s1][s2]=1;
    level[s1][s2]=0;
    int j=0;
    while(!q.empty())
    {
        pii top=q.front();
        int u=top.uu;
        int v=top.vv;
        if(llv[level[u][v]]==0)
        {
            llv[level[u][v]]=1;
            int sz=vc.size();
            for( ; j<sz; j++)
            {
                for(int i=0; i<4; i++)
                {
                    int tt=vc[j].uu+fx[i];
                    int to=vc[j].vv+fy[i];
                    if(tt>=1&&tt<=r&&to>=1&&to<=c&&G[tt][to]!='F'&&G[tt][to]!='#')
                    {
                        vc.push_back(pii(tt,to));
                        G[tt][to]='F';
                    }
                }
            }
        }
        for(int k=0; k<4; k++)
        {
            int tx=top.uu+fx[k];
            int ty=top.vv+fy[k];
            if(tx<1||tx>r||ty<1||ty>c)
            {
                return (level[u][v]+1);
            }
            if(!visited[tx][ty]&&G[tx][ty]=='.')
            {
                visited[tx][ty]=1;
                level[tx][ty]=level[u][v]+1;
                q.push(pii(tx,ty));
            }
        }
        q.pop();
    }
    return -1;
}
int main()
{
    int t, i, j, k, ans;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        int s1, s2;
        scanf("%d %d",&r,&c);
        for(j=1; j<=r; j++)
        {
            getchar();
            for(k=1; k<=c; k++)
            {
                scanf("%c",&G[j][k]);
                if(G[j][k]=='J')
                {
                    s1=j;
                    s2=k;
                }
                if(G[j][k]=='F')
                {
                    vc.push_back(pii(j,k));
                }
            }
        }
        ans=bfs(s1,s2);
        if(ans==-1) printf("Case %d: IMPOSSIBLE\n",i);
        else printf("Case %d: %d\n",i,ans);
        mem(G,0);
        mem(visited,0);
        mem(level,0);
        mem(llv,0);
        vc.clear();
    }
    return 0;
}
