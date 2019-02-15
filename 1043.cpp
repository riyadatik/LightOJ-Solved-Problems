#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t, j;
    double hritee_vaabkumari, h, r, i, e;
    scanf("%d",&t);
    for(j=1; j<=t; j++)
    {
        scanf("%lf%lf%lf%lf",&h,&i,&e,&r);
        hritee_vaabkumari=h*sqrt(r/(r+1));
        printf("Case %d: %lf\n",j,hritee_vaabkumari);
    }
    return 0;
}
