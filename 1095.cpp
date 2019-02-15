#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,int>
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
#define DIST (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define LL long long int
#define MOD 1000000007
LL dp[1005][1005];
LL dy[1005];
//NCR
LL NCR(LL n, LL r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r];
    else
    {
        dp[n][r]=(NCR(n-1,r)%MOD+NCR(n-1,r-1)%MOD)%MOD;
        return dp[n][r];
    }
}
LL solve(LL n, LL k)
{
    LL res, i;
    res=dy[n];
    for(i=1; i<=k; i++)
    {
        if(i%2==1)
        {
            res=res-(NCR(k,i)*dy[n-i])%MOD;
        }
        else
        {
            res=res+(NCR(k,i)*dy[n-i])%MOD;
        }
        res=(res+MOD)%MOD;
    }
    return res;
}
int main()
{
    LL t, n, m, k, i, ans;
    dy[0]=1;
    for(i=1; i<=1003; i++)
    {
        dy[i]=(dy[i-1]*i)%MOD;
    }
    scanf("%lld",&t);
    mem(dp,-1);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld %lld",&n,&m,&k);
        ans=(NCR(m,k)*solve(n-k,m-k))%MOD;
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
