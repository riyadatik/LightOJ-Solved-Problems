#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int hritee, vaabkumari;
    int x1, x2, y1, y2, i, t, j, n;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        printf("Case %d:\n",i);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&n);
        for(j=1; j<=n; j++)
        {
            scanf("%d%d",&hritee,&vaabkumari);
            if((hritee>x1&&hritee<x2)&&(vaabkumari>y1&&vaabkumari<y2))
            printf("Yes\n");
            else
            printf("No\n");
        }
    }
    return 0;
}
