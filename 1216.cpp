#include<iostream>
#include<cstdio>
#include<cmath>
#define PI acos(-1)
using namespace std;
int main()
{
    double hritee_vaabkumari;
    int h, r, i, t;
    double e;
    int n, j;
    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        scanf("%d%d%d%d",&h,&r,&i,&t);
        e=r+((h-r)*t)/(double)i;  //radius of water level
        hritee_vaabkumari=(1/3.0)*PI*t*(e*e+e*r+r*r);
        printf("Case %d: %lf\n",j,hritee_vaabkumari);
    }
    return 0;
}
