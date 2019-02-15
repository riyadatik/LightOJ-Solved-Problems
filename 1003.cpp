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
map<string, vector<string> >G;
map<string, int>dsc, onstk;
int c=0;
int tarjan(string u)
{
    c++;
    dsc[u]=c;
    onstk[u]=1;
    for(int i=0; i<G[u].size(); i++)
    {
        string v=G[u][i];
        if(dsc[v]==0)
        {
            if(onstk[v]==1) return 1;
            int ans=tarjan(v);
            if(ans==-1)
            {
                return ans;
            }
        }
        else
        {
            return -1;
        }
    }
    return 1;
}
int main()
{
    int t, n, i, j;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        set<string>s;
        set<string>::iterator it;
        scanf("%d",&n);
        for(j=1; j<=n; j++)
        {
            string s1, s2;
            cin>>s1>>s2;
            G[s1].pb(s2);
            s.insert(s1);
        }
        int ans;
        for(it=s.begin(); it!=s.end(); it++)
        {
            if(onstk[*it]!=1)
            {
                c=0;
                ans=tarjan(*it);
                dsc.clear();
                if(ans==-1)
                {
                    break;
                }
            }
        }
        if(ans==1)
        {
            pf("Case %d: Yes\n",i);
        }
        else
        {
            pf("Case %d: No\n",i);
        }
        G.clear();
        onstk.clear();
    }
    return 0;
}
