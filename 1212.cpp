//Bismillahir Rahmanir Rahim
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
int main()
{
    string hritee, b, c, d, e;
    b="pushLeft";
    c="pushRight";
    d="popLeft";
    e="popRight";
    int n, m, t, a, i, j, x;
    cin>>t;
    for(i=1; i<=t; i++){
        deque<int>q;
        x=0;
        cin>>n>>m;
        cout<<"Case "<<i<<":"<<endl;
        for(j=1; j<=m; j++){
            cin>>hritee;
            if((x==n)&&((hritee==b)||(hritee==c))){
                cin>>a;
                cout<<"The queue is full"<<endl;
            }
            else if(hritee==b){
                cin>>a;
                q.push_front(a);
                cout<<"Pushed in left: "<<a<<endl;
                x++;
            }
            else if(hritee==c){
                cin>>a;
                q.push_back(a);
                cout<<"Pushed in right: "<<a<<endl;
                x++;
            }
            else if(x==0){
                cout<<"The queue is empty"<<endl;
            }
            else if(hritee==d){
                cout<<"Popped from left: "<<q.front()<<endl;
                x--;
                q.pop_front();
            }
            else if(hritee==e){
                cout<<"Popped from right: "<<q.back()<<endl;
                x--;
                q.pop_back();
            }
        }
    }
    return 0;
}
