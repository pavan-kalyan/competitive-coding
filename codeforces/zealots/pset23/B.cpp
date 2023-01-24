#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;

int main() {
  int n;
  cin >> n;
  vi b(n);
  vi d(n);
  vector<vector<int>> a;
  for (int i = 0; i < n; i++) {
    int born, dead;
    cin >> born;
    cin >> dead;
    a.push_back({born, 1});
    a.push_back({dead, -1});
  }
  sort(a.begin(), a.end());
  int year = 0;
  int num = 0;
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += a[i][1];
    if (num < sum) {
      year = a[i][0];
      num = sum;
    }
  }
  cout << year << " " << num << endl;

  return 0;
}
