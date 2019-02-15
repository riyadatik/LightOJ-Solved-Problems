#include<bits/stdc++.h>
using namespace std;
#define dd double
dd x, y, z;
dd F(dd a, dd b, dd c)
{
    double res;
    res=(((x-a)*(x-a))+((y-b)*(y-b))+((z-c)*(z-c)));
    res=sqrt(res);
    return res;
}
dd ternary_src(dd x1, dd y1, dd z1, dd x2, dd y2, dd z2)
{
    dd midx1, midy1, midz1, midx2, midy2, midz2, res1, res2, ans=100000000.00;
    int c=100;
    while(c--)
    {
        midx1=x1+((x2-x1)/3.0);
        midy1=y1+((y2-y1)/3.0);
        midz1=z1+((z2-z1)/3.0);
        midx2=x2-((x2-x1)/3.0);
        midy2=y2-((y2-y1)/3.0);
        midz2=z2-((z2-z1)/3.0);
        res1=F(midx1,midy1,midz1);
        res2=F(midx2,midy2,midz2);
        ans=min(ans,res1);
        ans=min(ans,res2);
        if(res1<res2)
        {
            x2=midx2;
            y2=midy2;
            z2=midz2;
        }
        else
        {
            x1=midx1;
            y1=midy1;
            z1=midz1;
        }
    }
    return ans;
}
int main()
{
    int t, i;
    dd x1, y1, z1, x2, y2, z2, ans;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&z1,&x2,&y2,&z2,&x,&y,&z);
        ans=ternary_src(x1,y1,z1,x2,y2,z2);
        printf("Case %d: %lf\n",i,ans);
    }
    return 0;
}
