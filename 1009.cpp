#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
vector<int>G[400000];
int visited[400000];
char self[400000];
int bfs(int src)
{
    queue<int>q;
    int c=0, l=0;
    c++;
    self[src]='V';
    q.push(src);
    visited[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        for(int k=0; k<G[u].size(); k++)
        {
            int v=G[u][k];
            if(!visited[v])
            {
                visited[v]=1;
                if(self[u]=='L')
                {
                    self[v]='V';
                    c++;
                }
                else
                {
                    self[v]='L';
                    l++;
                }
                q.push(v);
            }
        }
        q.pop();
    }
    return max(c,l);
}
int main()
{
    int t, n, i, k, ans, res;
    set<int>s;
    set<int>::iterator it;
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            int u, v;
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
            s.insert(u);
            s.insert(v);
        }
        for(it=s.begin(); it!=s.end(); it++)
        {
            if(!visited[*it])
            {
                res=bfs(*it);
                ans=ans+res;
            }
        }
        printf("Case %d: %d\n",k,ans);
        mem(G,0);
        mem(visited,0);
        mem(self,'1');
        s.clear();
    }
    return 0;
}
