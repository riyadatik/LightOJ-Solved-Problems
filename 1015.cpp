#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, j, s, ans;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        ans=0;
        cin>>n;
        for(j=1; j<=n; j++)
        {
            cin>>s;
            if(s>0)
            {
                ans+=s;
            }
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
