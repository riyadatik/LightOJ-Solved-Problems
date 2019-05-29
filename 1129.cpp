#include<bits/stdc++.h>
typedef struct node Node;
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<int, int>
#define sc scanf
#define pf printf
#define pb push_back
#define uu first
#define vv second
#define DIST(x1,y1,x2,y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define MAX_NODE 100005
#define MAX_LEN 100
char s[MAX_LEN];
int node[MAX_NODE][11];
int isNumber[MAX_NODE];
int sz, fg;
void Insert()
{
    int now=0, bl=0;
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(node[now][s[i]-'0']==0)
        {
            node[now][s[i]-'0']=++sz;
            bl=1;
        }
        now=node[now][s[i]-'0'];
        if(isNumber[now]==1)
        {
            fg=1;
        }
    }
    isNumber[now]=1;
    if(bl==0)
    {
        fg=1;
    }
}
int main()
{
    int t, i, j;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        int n;
        scanf("%d",&n);
        fg=0;
        sz=0;
        mem(node, 0);
        mem(isNumber, 0);
        for(j=1; j<=n; j++)
        {
            Insert();
        }
        printf("Case %d: ",i);
        if(fg==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

