#include<stdio.h>
int main()
{
    long long int n, i, j, k, f;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        j=0;
        scanf("%lld",&k);
        while(k/2!=0)
        {
            f=k%2;
            if(f==1)
                j++;
            k=k/2;
        }
        if(k==1)
            j++;
        if(j%2==0)
            printf("Case %lld: even\n",i);
        else
            printf("Case %lld: odd\n",i);
    }
    return 0;
}
