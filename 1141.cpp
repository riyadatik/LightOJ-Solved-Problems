#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
int a[10005], prime[10005];
int visited[10005];
int level[10005];
vector<int>G[10005];
void seive()
{
    int i, j;
    for(i=4; i<=10000; i=i+2)
    {
        a[i]=1;
    }
    for(i=3; i<=sqrt(10000); i++)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=10000; j=j+i+i)
            {
                a[j]=1;
            }
        }
    }
    a[0]=1;
}

void prime_fact()
{
    int n=10003;
    for(int k=1; k<=n; k++)
    {
        int sqrtn=sqrt(k);
        int d=k;
        for(int i=0; prime[i]<=sqrtn; i++)
        {
            if(d%prime[i]==0)
            {
                G[k].push_back(prime[i]);
                while(d%prime[i]==0)
                {
                    d=d/prime[i];
                }
            }
        }
        if(d>1&&d<k)
        {
            G[k].push_back(d);
        }
    }
}

void bfs(int src, int dest)
{
    queue<int>q;
    q.push(src);
    visited[src]=1;
    level[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0; i<G[u].size(); i++)
        {
            int v=u+G[u][i];
            if(visited[v]==0&&v<=dest)
            {
                visited[v]=1;
                level[v]=level[u]+1;
                q.push(v);
                if(v==dest)
                {
                    printf("%d\n",level[v]);
                    return;
                }
            }
        }
        q.pop();
    }
    printf("-1\n");
}
int main()
{
    int t, src, dest, i, j=0, k;
    seive();
    prime[j]=2;
    j++;
    for(i=3; i<=10000; i=i+2)
    {
        if(a[i]==0)
        {
            prime[j]=i;
            j++;
        }
    }
    prime_fact();
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        mem(visited,0);
        mem(level,0);
        scanf("%d %d",&src,&dest);
        printf("Case %d: ",i);
        if(src==dest)
        {
            printf("0\n");
        }
        else
        {
            bfs(src, dest);
        }
    }
    return 0;
}
