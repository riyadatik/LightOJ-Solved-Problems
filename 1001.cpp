//Bismillahir Rahmanir Rahim
#include<iostream>
using namespace std;
int main()
{
    int hritee, n, a, b, i;
    cin>>hritee;
    for(i=1; i<=hritee; i++){
        cin>>n;
        a=n/2;
        b=n-a;
        cout<<a<<' '<<b<<endl;
    }
    return 0;
}
