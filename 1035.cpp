#include<bits/stdc++.h>
using namespace std;
map<int, int>m;
set<int>s;
set<int>::iterator it;
int a[110], prime[50];
void seive(int n)
{
    int i, j;
    for(i=4; i<=n; i=i+2) a[i]=1;
    for(i=3; i<=sqrt(n); i++)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=n; j+=i*2)
            {
                a[j]=1;
            }
        }
    }
    a[1]=1;
    j=1;
    prime[j++]=2;
    for(i=3; i<=n; i++)
    {
        if(a[i]==0)
        {
            prime[j++]=i;
        }
    }
}
void primefact(int n)
{
    int i, j;
    for(i=1; prime[i]<=sqrt(n); i++)
    {
        if(n%prime[i]==0)
        {
            s.insert(prime[i]);
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                m[prime[i]]++;
            }
        }
    }
    if(n>1)
    {
        m[n]++;
        s.insert(n);
    }
}
int main()
{
    int t, n, i, j, flag;
    seive(105);
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        flag=0;
        scanf("%d",&n);
        for(j=2; j<=n; j++)
        {
            primefact(j);
        }
        printf("Case %d: %d = ", i, n);
        for(it=s.begin(); it!=s.end(); it++)
        {
            if(flag==1)
            {
                printf(" * ");
            }
            printf("%d (%d)",*it,m[*it]);
            flag=1;
        }
        printf("\n");
        m.clear();
        s.clear();
    }
    return 0;
}
