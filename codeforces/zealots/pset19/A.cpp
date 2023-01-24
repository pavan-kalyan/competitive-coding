#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

bool check(int mice, vector<ll> x, ll n) {
  ll sum = 0;
  ll c = 0;
  for (int i = x.size() - 1; i >= 0; i--) {
    if (c >= mice) {
      return true;
    }
    ll dist = n - x[i];
    c++;
    sum += dist;
    if (sum >= n) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;

  while (t-- > 0) {
    ll n, k;
    cin >> n;
    cin >> k;
    unordered_map<ll, ll> m;
    vector<ll> x(k);
    for (ll i = 0; i < k; i++) {
      cin >> x[i];
    }
    sort(x.begin(), x.end());

    int l = 0;
    int r = k;
    int ans = 0;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (check(m, x, n)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}