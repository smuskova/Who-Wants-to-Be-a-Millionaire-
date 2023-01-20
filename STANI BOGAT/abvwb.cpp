#include<bits/stdc++.h>
using namespace std;
void func( int &a, int &b, int c)
{
    int x; x=a;
    a=b; b=x; c=5;
    cout<<"func: a="<<a<<endl;
    cout<<"func: b="<<b<<endl;
    cout<<"func: c="<<c<<endl;
return;
}
int main ()
{
    int p=1;
    int q=2;
    int r=3;
    cout<<"main: p="<<p<<endl;
    cout<<"main: q="<<q<<endl;
    cout<<"main: r="<<r<<endl;
    func(p, q, r);
    func(r, p, q);
    func(q, r, p);
    cout<<"main: p="<<p<<endl;
    cout<<"main: q="<<q<<endl;
    cout<<"main: r="<<r<<endl;



 return 0;
}
