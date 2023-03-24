#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
       
signed main()
{
int t;   
cin >> t; 
while (t--)
{
 
 int n;
 cin>>n;
 string s;
 cin>>s;
 
 int f=0;
 for(int i=0;i<n/2;i++){
   if(f==0||f==2){
     if(s[i]!=s[n-i-1]){
       f++;
     }
   }
   else{
     if(s[i]==s[n-i-1]){
       f++;
      // break;
     }
   }
 }
 
 cout<<(f>2?"no":"yes")<<endl;
}
                
return 0;
} 
