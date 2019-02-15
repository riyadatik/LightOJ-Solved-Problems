#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, j;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        string s, s1;
        cin>>s;
        s1=s;
        reverse(s.begin(),s.end());
        printf("Case %d: ",i);
        if(s==s1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
