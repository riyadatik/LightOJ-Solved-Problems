#include<bits/stdc++.h>
using namespace std;
#define dd double
double F(double c1, double d1, double c2, double d2)
{
    double res;
    res=((c1-c2)*(c1-c2))+((d1-d2)*(d1-d2));
    res=sqrt(res);
    return res;
}
double ternary_src(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double midx1, midy1, midx2, midy2, midx3, midy3, midx4, midy4;
    double res1, res2, ans=10000000.0;
    int c=100;
    while(c--)
    {
        midx1=x1+((x2-x1)/3.0);
        midy1=y1+((y2-y1)/3.0);
        midx2=x2-((x2-x1)/3.0);
        midy2=y2-((y2-y1)/3.0);
        midx3=x3+((x4-x3)/3.0);
        midy3=y3+((y4-y3)/3.0);
        midx4=x4-((x4-x3)/3.0);
        midy4=y4-((y4-y3)/3.0);
        res1=F(midx1,midy1,midx3,midy3);
        res2=F(midx2,midy2,midx4,midy4);
        ans=min(ans,res1);
        ans=min(ans,res2);
        if(res1<res2)
        {
            x2=midx2;
            y2=midy2;
            x4=midx4;
            y4=midy4;
        }
        else
        {
            x1=midx1;
            y1=midy1;
            x3=midx3;
            y3=midy3;
        }
    }
    return ans;
}
int main()
{
    int t, i;
    double x1, x2, x3, x4, y1, y2, y3, y4, ans;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        ans=ternary_src(x1,y1,x2,y2,x3,y3,x4,y4);
        printf("Case %d: %lf\n",i,ans);
    }
    return 0;
}
