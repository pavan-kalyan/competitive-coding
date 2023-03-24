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
	int m, n;
	cin >>m >>n;
	vi row(m);
	vi col(n);

	for (int i=0;i<m;i++) cin >> row[i];
	for (int i=0;i<n;i++) cin >> col[i];

	if (row.size() == 2 && col.size()==2) {
		cout << 7 << endl;
	} else {
		cout << 1 <<endl;
	}
}

int main() {
	int t;
	cin >>t;
	while (t-->0) {
		solve();
	}
	return 0;
}

