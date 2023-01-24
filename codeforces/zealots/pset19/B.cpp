#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void printV(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void solve() {
  int n;
  int k;
  cin >> n >> k;
  vi forward;
  vi backward;
  int maxDist = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (temp > 0) {
      forward.push_back(temp);
      maxDist = max(maxDist, temp);
    } else if (temp < 0) {
      backward.push_back(temp);
      maxDist = max(maxDist, -1 * temp);
    }
  }
  sort(forward.begin(), forward.end());
  sort(backward.begin(), backward.end());

  // calculate forward first
  ll sum = 0;
  for (int i = forward.size() - 1; i >= 0; i = i - k) {
    sum += 2 * forward[i];
  }

  for (int i = 0; i < backward.size(); i = i + k) {
    sum += -2 * backward[i];
  }

  cout << sum - maxDist << endl;
}

int main() {
  int t;
  cin >> t;

  while (t-- > 0) {
    solve();
  }
  return 0;
}
