#include<stdio.h>
#include<math.h>
#define PI 2*acos(0.0)
int main()
{
    int t, i;
    double hritee, h, r, e, a;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf",&r);
        h=r*2;
        e=h*h;
        a=PI*r*r;
        hritee=e-a;
        printf("Case %d: %.2lf\n",i,hritee);
    }
    return 0;
}
