#include <bits/stdc++.h>

#include <iostream>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;

void solve() {
  int n;
  cin >> n;
  vi a(n + 1);
  bool flag = true;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    flag = flag & a[i] > a[i - 1];
  }
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
