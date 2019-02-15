#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    double hritee_vaabkumari;
    double hritee;
    double hritee1, hritee2, hritee3, hritee4;
    int h, r, i, t, e;
    int h1, r1, i1, t1; //e1
    scanf("%d",&t);
    for(e=1; e<=t; e++)
    {
        scanf("%d%d%d%d%d%d",&h,&h1,&r,&r1,&i,&i1);
        t1=((h-r)*(h-r))+((h1-r1)*(h1-r1));
        hritee4=sqrt(double(t1));
        hritee1=sqrt(double(((h-r)*(h-r))+((h1-r1)*(h1-r1))));
        hritee2=sqrt(double(((h-i)*(h-i))+((h1-i1)*(h1-i1))));
        hritee3=sqrt(double(((r-i)*(r-i))+((r1-i1)*(r1-i1))));
        hritee=acos(((hritee1*hritee1)+(hritee2*hritee2)-(hritee3*hritee3))/(2*hritee1*hritee2));
        hritee_vaabkumari=hritee4*hritee;
        printf("Case %d: %lf\n",e,hritee_vaabkumari);
    }
    return 0;
}
