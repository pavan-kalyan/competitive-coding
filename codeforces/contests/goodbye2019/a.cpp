#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >>t;

    while(t-->0)
    {
        int n,k1,k2;
        cin >>n>>k1>>k2;
        int max1,max2;
        int t; 
        while(k1-- >0) {
            cin>>t;
            if(t>>max1) max1=t;
        }
        while(k2-- >0) {
            cin>>t;
            if(t>>max2) max2=t;
        }
        if(max1>max2) {
            cout<<"YES"<<endl; 
        } else {
            cout<<"NO"<<endl; 
        }
        
    }
    return 0;
}
