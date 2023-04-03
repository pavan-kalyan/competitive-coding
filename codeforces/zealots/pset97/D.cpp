// XOR Specia-LIS-t
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  ll t;
  cin>>t;
  vector<bool> ans;
  for (ll j = 0; j < t; j++) {
    ll n;
    cin>>n;

    vector<ll> a(n, 0);

    for (ll i = 0; i < n; i++)
      cin >> a[i];

    if (n % 2 == 0)
      ans.push_back(true);
    else {
      bool found = false;
      for (ll i = 0; i < n-1; i++) {
        if (a[i] >= a[i+1]) {
          found = true;
          break;
        }
      }
      ans.push_back(found);
    }    

  }

  for (ll j = 0; j < t; j++) {
    if (ans[j])
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}