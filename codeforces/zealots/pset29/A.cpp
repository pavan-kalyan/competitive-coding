#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;


// referred to official editorial when I got stuck
// https://codeforces.com/blog/entry/97288

void solve() {

	int n;
	cin >>n;

	vi a(n);
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}
	if (a[0] != n && a[a.size()-1] != n) {
		cout << -1 << endl;
		return;
	}
	for (auto it = a.rbegin(); it <a.rend();it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >>t;
	while (t-->0) {
		solve();
	}
	return 0;
}

