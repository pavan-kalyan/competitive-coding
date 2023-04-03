// Permutation Operations
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  ll t;
  cin>>t;
  for (ll j = 0; j < t; j++) {
    ll n;
    cin>>n;
 
    vector<ll> a(n, 0);
 
    for (ll i = 0; i < n; i++)
        cin >> a[i];
 
    vector<ll> ans(n, 0);

    set<ll> available;

    for (ll i = 0; i < n; i++)
        available.insert(i+1);
 
    for (ll i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
            ll diff = a[i]-a[i+1];

            auto xx = available.lower_bound(diff);
            ans[*xx-1] = i+2;
            available.erase(xx);
        }
    }   
 
    for (ll i = 0; i < n; i++) {
        if (ans[i] == 0)
            ans[i] = 1;
        cout << ans[i] << " ";
    } 
 
    cout << "\n";
 
  }
 
 
 
  return 0;
}