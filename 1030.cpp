#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int main()
{
    LL t, n, i, j, k, c;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        double a[105], b[105];
        double d;
        scanf("%lld",&n);
        for(j=1; j<=n; j++)
        {
            scanf("%lf",&b[j]);
        }
        a[n]=b[n];
        for(j=n-1; j>=1; j--)
        {
            c=0;
            d=0;
            for(k=j+1; k<=j+6; k++)
            {
                if(k>n)
                {
                    break;
                }
                d=d+((a[k]+b[j])/6);
                c++;
            }
            c=6-c;
            a[j]=(d*6)/(6.0-c);
        }
        cout<<a[3]<<endl;
        printf("Case %lld: %lf\n",i,a[1]);
    }
    return 0;
}
