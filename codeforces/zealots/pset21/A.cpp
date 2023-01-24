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
  if (n == 1) {
    cout << "-1" << endl;
    return;
  }
  vi a(n);
  vi b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin(), b.end());

  for (int i = 0; i < n; i++) {
    if (a[i] == b[i] && i < n - 1) {
      int k = i + 1;
      while (a[i] != b[k] && k < n) {
        k++;
      }
      if (k < n) {
        int t = b[k];
        b[k] = b[i];
        b[i] = t;
      }
    }
    if (a[i] == b[i] && i == n - 1) {
      int k = i - 1;
      while (k < n && a[i] != b[k] && k >= 0) {
        k--;
      }
      if (k >= 0) {
        int t = b[k];
        b[k] = b[i];
        b[i] = t;
      }
    }
  }
  // check if array is still incorrect
  // for (int i = 0; i < n; i++) {
  // if (a[i] == b[i]) {
  // cout << "-1" << endl;
  // return;
  // }
  // }
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
