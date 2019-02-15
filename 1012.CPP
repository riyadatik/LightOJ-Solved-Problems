#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define pii pair<int, int>
#define mem(x,y) memset(x,y,sizeof(x))
#define u first
#define v second
int fx[]={+1,-1,+0,-0};
int fy[]={+0,+0,+1,-1};
char G[21][21];
int ans;
int h, w;
void BFS(int a, int b)
{
    ans=0;
    queue<pii>q;
    q.push(pii(a,b));
    while(!q.empty())
    {
        pii top=q.front();
        for(int k=0; k<4; k++)
        {
            int tx=top.u+fx[k];
            int ty=top.v+fy[k];
            if(tx>=0&&tx<h&&ty>=0&&ty<w&&G[tx][ty]=='.')
            {
                ans++;
                G[tx][ty]='#';
                q.push(pii(tx,ty));
            }
        }
        q.pop();
    }
}
int main()
{
    int t, i, j, k, a, b;
    cin>>t;
    rep(i,t)
    {
        mem(G,0);
        cin>>w>>h;
        cin.ignore();
        rep(j,h)
        {
            rep(k,w)
            {
                cin>>G[j][k];
                if(G[j][k]=='@')
                {
                    a=j;
                    b=k;
                }
            }
        }
        BFS(a,b);
        cout<<"Case "<<i+1<<": "<<ans+1<<endl;
    }
    return 0;
}
