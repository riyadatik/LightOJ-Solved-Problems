#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LL long long int
LL a[60005], prime[60000];
void seive(LL n)
{
    LL i, j;
    for(i=4; i<=n; i=i+2)
    {
        a[i]=1;
    }
    for(i=3; i<=sqrt(n); i++)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=n; j+=i*2)
            {
                a[j]=1;
            }
        }
    }
    j=1;
    prime[j++]=2;
    for(i=3; i<=n; i=i+2)
    {
        if(a[i]==0)
        {
            prime[j++]=i;
        }
    }
}
LL bigmod(LL N, LL P)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        LL res=bigmod(N,P/2);
        return ((res%MOD)*(res%MOD))%MOD;
    }
    else
    {
        return ((N%MOD)*bigmod(N,P-1)%MOD)%MOD;
    }
}
LL primefact(LL n, LL m)
{
    LL i, l=0, res=1;
    for(i=1; prime[i]<=sqrt(n); i++)
    {
        l=0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                l++;
            }
        l=(l*m)+1;
        res=(res*(bigmod(prime[i],l)-1+MOD))%MOD;
        res=(res*(bigmod(prime[i]-1,MOD-2)))%MOD;
        }
    }
    if(n>1)
    {
        res=(res*(bigmod(n,m+1)-1+MOD))%MOD;
        res=(res*(bigmod(n-1,MOD-2)))%MOD;
    }
    return res;
}
int main()
{
    LL t, n, m, i, ans;
    seive(60000);
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&m);
        ans=primefact(n,m);
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
