#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int s,a,b,c;
        int cnt=0;
        cin >>s>>a>>b>>c;
        if(s>=6) {
            cout<<1<<endl;
            continue;
        }
        if(s<a || s<b || s<c)
        {
            cout<<0<<endl;
            continue;
        }

        if(s>=(a+b+c))
        {
            cout<<1<<endl;
        }
        else if(s>=(a+b) && s>=c)
        {
            cout<<2<<endl;
        }
        else if(s>=(b+c) && s>=a)
        {
            cout<<2<<endl;
        }
        else if(s>=a && s>=b && s>=c)
        {
            cout<<3<<endl;
        }
    }
}

