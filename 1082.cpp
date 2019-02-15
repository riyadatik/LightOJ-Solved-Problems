#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
int a[100005];
int tree[100002*4];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=min(tree[Left],tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
    if(b>j||e<i)
    {
        return 1000005;
    }
    if(b>=i&&e<=j)
    {
        return tree[node];
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    int mn=min(p1,p2);
    return mn;
}
int main()
{
    int t, i, n, j, q, u, v;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d",&n,&q);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a[j]);
        }
        init(1,1,n);
        printf("Case %d:\n",i);
        for(j=1; j<=q; j++)
        {
            scanf("%d%d",&u,&v);
            int mn=query(1,1,n,u,v);
            printf("%d\n",mn);
        }
    }
        return 0;
}
