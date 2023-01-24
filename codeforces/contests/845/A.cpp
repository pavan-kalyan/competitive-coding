#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int sum = 0;
  bool odd;
  if (a[0] % 2 == 0)
    odd = false;
  else
    odd = true;

  int streak = 1;
  for (int i = 1; i < n; i++) {
    // cout << "streak " << streak << endl;
    if (a[i] % 2 == 0) {
      if (!odd) {
        // continue streak
        streak++;
      } else {
        // streak broken
        // cout << "strk broken" << endl;
        sum += (streak - 1);
        streak = 1;
        odd = !odd;
      }
    } else {
      if (!odd) {
        // streak broken
        // cout << "strk broken" << endl;
        sum += (streak - 1);
        streak = 1;
        odd = !odd;
      } else {
        streak++;
      }
    }
  }
  sum += (streak - 1);
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
