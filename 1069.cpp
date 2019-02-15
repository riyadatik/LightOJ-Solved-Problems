#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, a, b, i, c, ans;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        c=0;
        ans=0;
        cin>>a>>b;
        if(a>b)
        {
            c=c+(a-b);
        }
        n=max(a,b);
        c=c+n;
        ans=ans+(c*4); // time for lift up down
        ans=ans+9; // time for lift open & close
        ans=ans+10; // time for enter & get out
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
