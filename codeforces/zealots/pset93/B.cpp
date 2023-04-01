// Hossam and Combinatorics
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bignum = 1000000007;

int main(){
  ll t;
  cin>>t;
  vector<ll> ans(t, 0);
  for (ll j = 0; j < t; j++) {
    ll n;
    cin>>n;

    vector<ll> a(n, 0);

    map<ll, ll> count;

    ll mini = LLONG_MAX;
    ll maxi = LLONG_MIN;
    for (ll i = 0; i < n; i++){
      cin >> a[i];
      count[a[i]]++;
      mini = min(mini, a[i]);
      maxi = max(maxi, a[i]);
    }

    ll maxDiff = maxi - mini;

    if (maxDiff == 0)
      ans[j] = n * (n-1);
    else {
      for (ll i = 0; i < n; i++) {
        ans[j] += count[a[i] - maxDiff] + count[a[i] + maxDiff];
      }
    }
    
  }

  for (ll j = 0; j < t; j++)
    cout << ans[j] << "\n";

  return 0;
}