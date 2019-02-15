#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LL long long int
int main()
{
    LL t, n, m, i, res, ans, a, b, c, d, pod;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&m);
        a=(m*((2*1)+((m-1)*1)))/2;
        c=m+m+1;
        b=(m*((2*c)+(m-1)*1))/2;
        d=b-a;
        pod=n/m;
        pod=pod/2;
        res=(pod*((2*a)+((pod-1)*d)))/2;
        c=m+1;
        a=(m*((2*c)+((m-1)*1)))/2;
        c=m+m+m+1;
        b=(m*((2*c)+((m-1)*1)))/2;
        d=b-a;
        ans=(pod*((2*a)+((pod-1)*d)))/2;
        ans=ans-res;
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
