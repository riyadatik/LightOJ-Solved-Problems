#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,int>
#define mem(x,y) memset(x,y,sizeof(x))
#define u first
#define v second
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int level[11][11];
int n;
char G[11][11];
int src1;
int src2;
int flag;
int bfs(char ch)
{
    int x, y;
    flag=0;
    mem(level,0);
    queue<pii>q;
    q.push(pii(src1,src2));
    while(!q.empty())
    {
        pii top=q.front();
        x=top.u;
        y=top.v;
        for(int k=0; k<4; k++)
        {
            int tx=top.u+fx[k];
            int ty=top.v+fy[k];
            if(G[tx][ty]==ch)
            {
                G[tx][ty]='.';
                level[tx][ty]=level[x][y]+1;
                src1=tx;
                src2=ty;
                flag=1;
                return level[tx][ty];
            }
            if(tx>=0&&tx<n&&ty>=0&&ty<n&&level[tx][ty]==0&&G[tx][ty]=='.')
            {
                level[tx][ty]=level[x][y]+1;
                q.push(pii(tx,ty));
            }
        }
        q.pop();
    }
    return 0;
}
int main()
{
    int t, i, j, k, c;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        mem(G,0);
        set<char>s;
        set<char>::iterator it;
        int cost=0;
        cin>>n;
        for(j=0; j<n; j++)
        {
            c=0;
            for(k=0; k<n; k++)
            {
                cin>>G[j][k];
                if(G[j][k]=='A')
                {
                    G[j][k]='.';
                    src1=j;
                    src2=k;
                }
                if('B'<=G[j][k]&&G[j][k]<='Z')
                {
                    s.insert(G[j][k]);
                }
            }
        }
        cout<<"Case "<<i<<": ";
        for(it=s.begin(); it!=s.end(); it++)
        {
            cost+=bfs(*it);
            if(flag==0)
            {
                cout<<"Impossible"<<endl;
                c=1;
                break;
            }
        }
        if(c==0)
        {
            cout<<cost<<endl;
        }
    }
    return 0;
}
