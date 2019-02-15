#include<iostream>
using namespace std;
int main()
{
    int n, i, a, b, c;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        c=a+b;
        cout<<"Case "<<i<<": "<<c<<endl;
    }
    return 0;
}
