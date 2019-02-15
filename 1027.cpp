#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, j, x, sum=0, p, q, u, v, cnt, res;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        sum=0;
        cnt=0;
        scanf("%d",&n);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&x);
            if(x<0)
            {
                cnt++;
            }
            sum=sum+abs(x);
        }
        printf("Case %d: ",i);
        if(cnt==n)
        {
            printf("inf\n");
        }
        else
        {
            u=n*sum;
            v=(n-cnt)*n;
            res=__gcd(u,v);
            p=u/res;
            q=v/res;
            printf("%d/%d\n",p,q);
        }
    }
    return 0;
}
