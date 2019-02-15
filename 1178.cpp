#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double hritee_vaabkumari;
    double h, r, i, t, e;
    double a, l;
    int n, j;
    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        scanf("%lf%lf%lf%lf",&h,&r,&i,&t);
        if(h<i)
            swap(h,i);
        e=h-i;
        a=(r*r)-((((r*r)+(e*e)-(t*t))*((r*r)+(e*e)-(t*t)))/(4*e*e));
        l=sqrt(a);
        hritee_vaabkumari=((h+i)*l)/2;
        printf("Case %d: %lf\n",j,hritee_vaabkumari);
    }
    return 0;
}
