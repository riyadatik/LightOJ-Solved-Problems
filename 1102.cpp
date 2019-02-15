#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,int>
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
#define DIST (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
//#define I64 long long int
#define mod 1000000007
#define lll long long int
lll fact[2000015];
lll bigmod(lll n, lll p)
{
    if(p==0) return 1;
    if(p%2==0)
    {
        lll res=bigmod(n,p/2);
        return((res%mod)*(res%mod))%mod;
    }
    else
    {
        return ((n%mod)*(bigmod(n,p-1)%mod))%mod;
    }
}
int main()
{
    lll n, t, r, i, k, c, d, ans;
    fact[0]=1;
    for(i=1; i<=2000007; i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n>>r;
        k=n+r-1;
        c=r-1;
        d=(fact[n]*fact[c])%mod;
        ans=bigmod(d,mod-2);
        ans=(ans*fact[k])%mod;
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
