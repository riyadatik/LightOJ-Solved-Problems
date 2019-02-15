#include<bits/stdc++.h>
using namespace std;
double a[1000005];
int main()
{
    long long int t, n, i, b, ans;
    for(i=1; i<=1000004; i++)
    {
        a[i]=a[i-1]+log10(i);
    }
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&b);
        ans=a[n]/log10(b);
        ans++;
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
