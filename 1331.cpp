#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double PI=acos(-1);
int main()
{
    double hritee_vaabkumari;
    double hritee, hritee1, hritee2, hritee3;
    double h, r, i, t, e;
    double a, b, c, d, s;
    int n, j;
    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        scanf("%lf%lf%lf",&h,&r,&i);
        a=r+i;
        b=h+i;
        c=h+r;
        s=(a+b+c)/2;
        hritee=sqrt(s*(s-a)*(s-b)*(s-c));
        t=acos((b*b+c*c-a*a)/(2*b*c));
        e=acos((a*a+c*c-b*b)/(2*a*c));
        d=((180*PI)/180)-t-e;
        hritee1=(h*h*t)/2;
        hritee2=(r*r*e)/2;
        hritee3=(i*i*d)/2;
        hritee_vaabkumari=hritee-(hritee1+hritee2+hritee3);
        printf("Case %d: %lf\n",j,hritee_vaabkumari);
    }
    return 0;
}
