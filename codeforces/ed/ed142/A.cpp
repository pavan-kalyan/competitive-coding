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


void solve() {

	int n;
	cin >>n;
	vi h(n);
	unordered_map<int,int> m;
	for (int i=0;i<n;i++) {
		cin >>h[i];
		m[h[i]]++;
	}

	int ones = m[1];
	int res = ones / 2;
	m[1] -= res*2;
	for (auto it = m.begin();it!=m.end();it++) {
		res += it->second;
	}

	cout << res <<endl;
}

int main() {
	int t;
	cin >>t;
	while (t-->0) {
		solve();
	}
	return 0;
}

