#include <bits/stdc++.h>

#include <iostream>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;


int count(unordered_map<int, int> map) {

  int cnt =0;
  for (auto it = map.begin();it != map.end();it++) {
    if (it->second > 0) {
      cnt++;
    }
  }
  return cnt;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // so that important numbers are at the end
  sort(a.begin(), a.end());

  int minDiff = INT_MAX;

  unordered_map<int, int> map;

  int l=0;
  int r=0;
  while (l<a.size()) {
    while (r <a.size() && count(map) < m) {
      //add a[r]

      // update topic map for all factors of a[r]
      for (int i=1;i <= m;i++) {
        if (a[r] % i ==0) {
        cout << "considering " << i <<endl;
          map[i % m]++;
          // if (a[r]/i==i) map[i]++;
          // else map[i]+=2;
        }
      }
      cout << "printing map at l,r " << l << " " << r <<endl;
      for (auto it = map.begin();it!=map.end();it++) {
        cout << it->first << " "<< it->second <<endl;
      }
      if (count(map)==m && r <a.size()) {
        minDiff = min(minDiff, a[r]-a[l]);
      }
      r++;
    }

    // if we reached here, then end of array or found *a* team
    if (count(map)==m && r <a.size()) {
      minDiff = min(minDiff, a[r]-a[l]);
    }

    // update topic map for all factors of a[l]
    for (int i=1;i*i<a[l];i++) {
      if (a[l] % i ==0) {
        map[i]--;
        // if (a[l]/i==i) map[i]--;
        // else map[i]-=2;
      }
    }
    l++;
  }
  if (minDiff == INT_MAX) cout << -1 << endl;
  else cout << minDiff <<endl;
}



int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
