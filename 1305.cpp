#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t, a1, a2, b1, b2, c1, c2, d1, d2, i, hritee_vaabkumari;
    double area;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d%d%d%d%d",&a1,&a2,&b1,&b2,&c1,&c2);
        d1=a1+c1-b1;
        d2=a2+c2-b2;
        area=.5*(((a1*b2)+(b1*c2)+(c1*d2)+(d1*a2))-((a2*b1)+(b2*c1)+(c2*d1)+(d2*a1)));
        hritee_vaabkumari=abs(area);
        printf("Case %d: %d %d %d\n",i,d1,d2,hritee_vaabkumari);
    }
    return 0;
}
