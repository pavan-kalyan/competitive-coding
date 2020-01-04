#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        long long n,a,s,b,c,d,e;
        cin>>n;
        cin>>a;
        long long res,max;
        max= pow(10,n);
        cout<< a+2*max<<endl;;
        cin>>b;
        cout<<max-b<<endl;
        cin>>d;
        cout<<max-d<<endl;
        cin>>res;
        if(res==-1) return 0; 
    }
}

