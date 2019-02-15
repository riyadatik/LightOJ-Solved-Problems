#include<bits/stdc++.h>
using namespace std;
long long int a[1000010], prime[90005];
void seive(long long int n)
{
    long long int i, j, sq;
    sq=sqrt(n);
    for(i=4; i<=n; i=i+2) a[i]=1;
    for(i=3; i<=sq; i=i+2)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=n; j+=i*2)
            {
                a[j]=1;
            }
        }
    }
    j=2;
    a[1]=1;
    prime[1]=2;
    for(i=3; i<=n; i=i+2)
    {
        if(a[i]==0)
        {
            prime[j++]=i;
        }
    }
}

long long int primefact(long long int n)
{
    long long int i, sq, c=0, p=0, res=1;
    //sq=sqrt(n);
    for(i=1; prime[i]<=sqrt(n); i++)
    {
        c=0;
        if(n%prime[i]==0)
        {
            p=prime[i];
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                c++;
            }
        }
        res=res*(c+1);
    }
    if(n>1)
    {
        res=res*2;
    }
    return res;
}
int main()
{
    long long int t, n, i, j, k, ans;
    map<long long int, long long int>m;
    seive(1000005);
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        if(m[n]==0)
        {
            ans=primefact(n);
            ans--;
            m[n]=ans;
        }
        else
        {
            ans=m[n];
        }
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
