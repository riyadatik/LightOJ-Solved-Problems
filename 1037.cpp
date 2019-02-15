#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
int a[20];
string s[20];
int dp[(1<<15)+10];
int n;
int SET(int N, int pos){return N=N|(1<<pos);}
bool check(int N, int pos){return (bool)(N&(1<<pos));}
int call(int mask)
{
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int mn=1<<28;
    for(int i=0; i<n; i++)
    {
        if(check(mask,i)==0)
        {
            int cost=a[i];
            int tt=0;
            for(int j=0; j<n; j++)
            {
                if(check(mask,j)!=0&&i!=j)
                {
                    tt=max(tt,s[j][i]-'0');
                }
            }
            if(tt>1)
            {
                cost=a[i]/tt;
                if(a[i]%tt!=0)
                {
                    cost++;
                }
            }
            int res=cost+call(SET(mask,i));
            mn=min(mn,res);
        }
    }
    return dp[mask]=mn;
}
int main()
{
    int t, i, j, k, c, ans;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        mem(dp,-1);
        scanf("%d",&n);
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[j]);
        }
        for(j=0; j<n; j++)
        {
            cin>>s[j];
        }
        ans=call(0);
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
