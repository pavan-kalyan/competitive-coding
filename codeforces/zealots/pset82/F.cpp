#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll t;
  cin>>t;
  vector<bool> ans;
  for (ll i = 0; i < t; i++) {
    ll n;
    cin>>n;
    vector<set<ll>> a(n, set<ll>());
    map<ll,ll> total;
    ll total_size = 0;
    for (ll j = 0; j < n; j++) {
      ll k;
      cin>>k;
      total_size+=k;
      for (ll b = 0; b < k; b++) {
        ll temp;
        cin >> temp;
        a[j].insert(temp);
        total[temp]++;
      }
    }
    bool found = false;
    for (ll j = 0; j < n; j++) {
      //assert(false && "hi");
      bool removeWontChange = true;
      for (auto xx : a[j]) {
        if (total[xx] == 1) {
          removeWontChange = false;
          break;
        }
      }
      if(removeWontChange) {
        found = true;
        break;
      }
    }
    ans.push_back(found);
  }

  for (ll i = 0; i < t; i++) {
    if (ans[i])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
