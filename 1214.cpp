#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, n, i, j, res=0, b;
    string s;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        res=0;
        cin>>s;
        cin>>b;
        for(j=0; j<s.size(); j++)
        {
            if(s[j]!='-')
            {
                res=(res*10)+(s[j]-'0');
                res=res%b;
            }
        }
        printf("Case %lld: ",i);
        if(res==0)
        {
            printf("divisible\n");
        }
        else
        {
            printf("not divisible\n");
        }
    }
    return 0;
}
