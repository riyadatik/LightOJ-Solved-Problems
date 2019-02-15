#include<bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
int main()
{
    int t, n, i;
    double r1, r2, d, ans;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf%d",&r1,&n);
        d=(180.0*PI)/180;
        d=d/n;
        ans=((r1*sin(d))/(1+sin(d)));
        printf("Case %d: %.10lf\n",i,ans);
    }
    return 0;
}
