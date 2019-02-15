#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
long long int a[100005];
long long int binary_src1(long long int lo, long long int hi, long long target)
{
    long long int mid, index=-1;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(a[mid]==target)
        {
            index=mid;
            lo=mid+1;
        }
        else if(a[mid]>target)
        {
            hi=mid-1;
        }
        else if(a[mid]<target)
        {
            lo=mid+1;
        }
    }
    if(index!=-1) return index+1;
    return lo;
}
long long int binary_src2(long long int lo, long long int hi, long long target)
{
    long long int mid, index=-1;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(a[mid]==target)
        {
            index=mid;
            hi=mid-1;
        }
        else if(a[mid]>target)
        {
            hi=mid-1;
        }
        else if(a[mid]<target)
        {
            lo=mid+1;
        }
    }
    if(index!=-1) return index;
    return lo;
}
int main()
{
    long long int t, n, q, i, j, k, ans;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld",&n,&q);
        a[0]=-100;
        a[n+1]=100000005;
        for(j=1; j<=n; j++)
        {
            scanf("%lld",&a[j]);
        }
        printf("Case %lld:\n",i);
        for(j=1; j<=q; j++)
        {
            long long int u, v, mid, ans1, ans2;
            scanf("%lld%lld",&u,&v);
            long long int lo, hi;
            lo=0;
            hi=n+1;
            ans1=binary_src1(lo,hi,v);
            lo=0;
            hi=n+1;
            ans2=binary_src2(lo,hi,u);
            ans=ans1-ans2;
            printf("%lld\n",ans);
        }
        mem(a,-1);
    }
    return 0;
}
