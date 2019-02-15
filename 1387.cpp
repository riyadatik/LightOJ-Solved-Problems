#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, n, a, i, j, ans;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        ans=0;
        scanf("%lld",&n);
        printf("Case %lld:\n",i);
        for(j=1; j<=n; j++)
        {
            string s;
            cin>>s;
            if(s=="donate")
            {
                cin>>a;
                ans+=a;
            }
            else
            {
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
