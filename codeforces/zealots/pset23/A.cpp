#include <bits/stdc++.h>

#include <iostream>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;

int getSym(int a, int b) {
  if (a == 0 && b == 0)
    return 0;
  else if (a == 1 && b == 1)
    return 1;
  else
    return 2;
}
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a;
  cin >> b;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int cur = getSym(a[i] - '0', b[i] - '0');
    if (i + 1 <= n - 1) {
      int next = getSym(a[i + 1] - '0', b[i + 1] - '0');
      if ((cur == 0 && next == 1) || (cur == 1 && next == 0)) {
        sum += 2;
        i++;
      } else {
        if (cur == 0)
          sum += 1;
        else if (cur == 2)
          sum += 2;
      }
    } else {
      if (cur == 0)
        sum += 1;
      else if (cur == 2)
        sum += 2;
    }
  }
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
