#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, s, i, j, k, n, ans;
    double d;
    scanf("%lld",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%lld",&s);
        n=sqrt(s);
        d=sqrt(s);
        if(n!=d)n++;
        ans=(n*n)-(n-1);
        if(n%2==0)
        {
            j=n;
            i=n;
            if(s<ans)
            {
                while(ans!=s)
                {
                    i--;
                    ans--;
                }
            }
            else if(s>ans)
            {
                while(ans!=s)
                {
                    j--;
                    ans++;
                }
            }
        }
        else
        {
            j=n;
            i=n;
            if(s<ans)
            {
                while(ans!=s)
                {
                    j--;
                    ans--;
                }
            }
            else if(s>ans)
            {
                while(ans!=s)
                {
                    i--;
                    ans++;
                }
            }
        }
        printf("Case %lld: %lld %lld\n",k,i,j);
    }
    return 0;
}
