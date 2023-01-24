#include <bits/stdc++.h>

#include <iostream>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;

void solve() {
  ll n;
  cin >> n;

  ll sum = 0;
  ll prod = 1;
  for (ll i = 2; i <= n; i++) {
    prod = ((prod % mod) * (i % mod));
    // cout << (prod % mod) * ((i % mod) * ((i % mod - 1 % mod) % mod)) % mod
    //     << endl;
  }
  sum = prod % mod * (n % mod * (n % mod - 1 % mod) % mod) % mod;
  cout << sum << endl;
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
