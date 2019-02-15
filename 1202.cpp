#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int main()
{
    LL t, i, c1, c2, r1, r2;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld%lld%lld",&r1,&c1,&r2,&c2);
        printf("Case %lld: ",i);
        if(r1==c1&&r2==c2)
            printf("1\n");
        else if(((r1%2==0&&c1%2==0)&&(r2%2==0&&c2%2==0))||((r1%2==1&&c1%2==1)&&(r2%2==1&&c2%2==1))||
            ((r1%2==1&&c1%2==1)&&(r2%2==0&&c2%2==0))||((r1%2==0&&c1%2==0)&&(r2%2==1&&c2%2==1)))
        {
            if(abs(r1-r2)==abs(c1-c2))
            {
                printf("1\n");
            }
            else
            {
                printf("2\n");
            }
        }
        else if(((r1%2==0&&c1%2==1)&&(r2%2==1&&c2%2==0))||((r1%2==0&&c1%2==1)&&(r2%2==0&&c2%2==1))||
            ((r1%2==1&&c1%2==0)&&(r2%2==0&&c2%2==1))||((r1%2==1&&c1%2==0)&&(r2%2==1&&c2%2==0)))
        {
            if(abs(r1-r2)==abs(c1-c2))
            {
                printf("1\n");
            }
            else
            {
                printf("2\n");
            }
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}
