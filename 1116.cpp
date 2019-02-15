#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LL long long int
int main()
{
    LL t, n, m, i, w;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        m=1;
        scanf("%lld",&w);
        printf("Case %lld: ",i);
        if(w%2==1)
        {
            printf("Impossible\n");
        }
        else
        {
            while(w%2==0)
            {
                m=m*2;
                w=w/2;
            }
            n=w;
            printf("%lld %lld\n",n,m);
        }
    }
    return 0;
}
