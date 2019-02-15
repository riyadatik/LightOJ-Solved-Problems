#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
long long int dp[100][100];
int NCR(long long int n, long long int r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r];
    else
    {
        dp[n][r]=NCR(n-1,r)+NCR(n-1,r-1);
        return dp[n][r];
    }

}
int main()
{
    long long int t, n, i, j, k, ans;
    scanf("%lld",&t);
    mem(dp,-1);
    for(i=1; i<=t; i++)
    {
        ans=1;
        scanf("%lld%lld",&n,&k);
        printf("Case %lld: ",i);
        if(k>n)
        {
            printf("0\n");
        }
        else if(k==0)
        {
            printf("1\n");
        }
        else if(k==1)
        {
            printf("%lld\n",n*n);
        }
        else
        {
            ans=NCR(n,k);
            for(j=n; j>n-k; j--)
            {
                ans=ans*j;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
