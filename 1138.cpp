#include<bits/stdc++.h>
using namespace std;
long long int a[15];
long long int j;
long long int F(long long int x)
{
    long long int res=0, i;
    for(i=1; i<j; i++)
    {
        res=res+(x/a[i]);
    }
    return res;
}
long long int binary_src(long long int n)
{
    long long int lo=5, hi=800000000, res, mid, ans=-1;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        res=F(mid);
        if(res==n)
        {
            ans=mid;
            hi=mid-1;
        }
        else if(res>=n)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    return ans;
}
int main()
{
    long long int t, q, i, k, ans;
    j=1;
    for(i=5; i<=800000000; i=i*5)
    {
        a[j++]=i;
    }
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&q);
        ans=binary_src(q);
        printf("Case %lld: ",i);
        if(ans==-1)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%lld\n",ans);
        }
    }
    return 0;
}
