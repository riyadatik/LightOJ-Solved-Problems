#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     int t, n, i, j, a, b, c, d, h, res;
     cin>>t;
     for(i=1; i<=t; i++)
     {
         int fg1=0, fg2=0, fg3=0, fg4=0, k=0;
         res=0;
         char ch1, ch2, ch3;
         string s;
         cin>>a>>ch1>>b>>ch2>>c>>ch3>>d;
         cin>>s;
         for(j=s.size()-1; j>=0; j--)
         {
             if(s[j]!='.')
             {
                 res=res+((s[j]-'0')*pow(2,k));
                 k++;
             }
             if(s[j]=='.'||j==0)
             {
                 if(fg1==0&&d==res)
                 {
                     fg1=1;
                 }
                 else if(fg2==0&&c==res&&fg1==1)
                 {
                     fg2=1;
                 }
                 else if(fg3==0&&b==res&&fg2==1)
                 {
                     fg3=1;
                 }
                 else if(fg4==0&&a==res&&fg3==1)
                 {
                     fg4=1;
                 }
                 else
                 {
                     break;
                 }
                 res=0;
                 k=0;
             }
         }
         if(fg1==1&&fg2==1&&fg3==1&&fg4==1)
         {
             printf("Case %d: Yes\n",i);
         }
         else
         {
             printf("Case %d: No\n",i);
         }
     }
     return 0;
 }
