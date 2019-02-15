#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int main()
{
    LL t, n, i, j, k, c;
    double a[100005];
    double sum;
    a[1]=0;
    a[2]=2;
    a[3]=2;
    for(i=4; i<=100000; i++)
    {
        k=i;
        sum=0;
        c=0;
        for(j=2; j<=sqrt(k); j++)
        {
            if(k%j==0)
            {
                sum=sum+a[j]+1;
                c++;
                if(k/j!=j)
                {
                    sum=sum+a[k/j]+1;
                    c++;
                }
            }
        }
        c=c+2;
        sum=sum+2;
        sum=sum*c;
        c=c*(c-1);
        a[i]=sum/c;
    }
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        printf("Case %lld: %lf\n",i,a[n]);
    }
    return 0;
}
