#include<bits/stdc++.h>
using namespace std;
int valid(int a, int b, int c)
{
    if((a+b)>c&&(b+c)>a&&(a+c)>b)
    {
        return 1;
    }
    return 0;
}
int main()
{
    long long int t, a, b, c, x, y, z, d, i;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(valid(a,b,c))
        {
            x=max(a,b);
            d=min(a,b);
            z=min(x,c);
            x=max(x,c);
            y=max(d,z);
            z=min(d,z);
            x=x*x;
            y=y*y;
            z=z*z;
            if(x==(y+z))
            {
                printf("Case %lld: yes\n",i);
            }
            else
            {
                printf("Case %lld: no\n",i);
            }
        }
        else
        {
            printf("Case %lld: no\n",i);
        }
    }
    return 0;
}
