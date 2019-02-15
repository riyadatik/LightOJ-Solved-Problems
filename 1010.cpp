#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LL long long int
int main()
{
    LL t, n, m, i, res=0, ans, c, d, a, b, u;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld",&m,&n);
        if(m==2&&n==2)
        {
            ans=4;
        }
        else if(m==1||n==1)
        {
            ans=max(m,n);
        }
        else if(n==2)
        {
            res=m/4;
            ans=res*4;
            u=m-(res*4);
            if(u==1)
            {
                ans=ans+2;
            }
            else if(u>1)
            {
                ans=ans+4;
            }
        }
        else if(m==2)
        {
            res=n/4;
            ans=res*4;
            u=n-(res*4);
            if(u==1)
            {
                ans=ans+2;
            }
            else if(u>1)
            {
                ans=ans+4;
            }
        }
        else
        {
            c=n/2;
            d=c;
            if(n%2==1)
            {
                c++;
            }
            b=m/2;
            a=m/2+m%2;
            ans=a*c;
            res=d*b;
            ans=ans+res;
        }
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
