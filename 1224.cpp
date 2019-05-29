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
#define MAX_NODE 1500000
#define MAX_LEN 205
char s[MAX_LEN];
int node[MAX_NODE][6];
int tot[MAX_NODE];
//int isWord[MAX_NODE];
int sz, ans;
void Insert(int j)
{
    scanf("%s",s);
    int len=strlen(s);
    for(int j=0; j<len; j++)
    {
        if(s[j]=='C')
        {
            s[j]='B';
        }
        else if(s[j]=='G')
        {
            s[j]='C';
        }
        else if(s[j]=='T')
        {
            s[j]='D';
        }
    }
    ans=max(ans,len);
    int now=0, i;
    int cnt=0, fg=0;
    for(i=0; i<len; i++)
    {
        if(node[now][s[i]-'A']==0)
        {
            fg=1;
            node[now][s[i]-'A']=++sz;
        }
        else if(fg==0)
        {
            cnt++;
        }
        now=node[now][s[i]-'A'];
        tot[now]++;
        ans=max(ans, tot[now]*cnt);
    }
}
int main()
{
    int t, n, i, j, k;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        ans=0;
        sz=0;
        scanf("%d",&n);
        for(j=1; j<=n; j++)
        {
            Insert(j);
        }
        mem(node,0);
        mem(tot,0);
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
