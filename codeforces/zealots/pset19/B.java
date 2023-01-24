#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
  int n;
  int k;
  cin >> n >> k;
  vi forward;
  vi backward;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (temp > 0) {
      forward.push_back(temp);
    } else if (temp < 0) {
      backward.push_back(temp);
    }
  }
  sort(forward.begin(), forward.end());
  sort(backward.begin(), backward.end(), greater<int>());
  // calculate forward first
  ll sum = 0;
  int prev = 0;
  for (int i = forward.size() - 1; i >= 0; i = i - k) {
    // adding up previous movement (to go back to origin)
    sum += prev;
    int distance = forward[i];
    prev = distance;
    sum += distance;
  }
  prev = 0;
  for (int i = 0; i < backward.size(); i = i + k) {
    // adding up previous movement (to go back to origin)
    sum += prev;
    int distance = backward[i];
    prev = distance;
    sum += distance;
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