#include<bits/stdc++.h>
using namespace std;
unsigned long long int phi[5000005];
void seivephi(unsigned long long int n)
{
    unsigned long long int i, j;
    for(i=2; i<n; i++)
    {
        if(phi[i]==0)
        {
            phi[i]=i-1;
            for(j=i*2; j<n; j+=i)
            {
                if(phi[j]==0)
                {
                    phi[j]=j;
                }
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
int main()
{
    unsigned long long t, a, b, i, ans;
    seivephi(5000005);
    for(i=2; i<5000005; i++)
    {
        phi[i]=phi[i-1]+(phi[i]*phi[i]);
    }
    scanf("%llu",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%llu %llu",&a,&b);
        ans=phi[b]-phi[a-1];
        printf("Case %llu: %llu\n",i,ans);
    }
    return 0;
}
