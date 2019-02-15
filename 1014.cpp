#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long long int n, p, l, i, j, k, x;
    long long int a[10000];
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld%lld",&p,&l);
        x=0;
        printf("Case %lld:",i);
        if((p-l)<=l)
        {
            printf(" impossible");
        }
        else
        {
            for(j=1; j<=sqrt(p-l); j++)
            {
                if((p-l)%j==0)
                {
                    a[x]=j;
                    x=x+1;
                    if((p-l)/j!=j)
                    {
                    a[x]=(p-l)/j;
                    x=x+1;
                    }
                }
            }
            sort(a, a+x);
            for(k=0; k<x; k++)
            {
                if(a[k]>l)
                {
                    printf(" %lld",a[k]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

