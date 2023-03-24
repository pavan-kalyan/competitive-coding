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

	int n, s, r;
	cin >> n >> s >> r;
	vi a;
	int max = s-r;
	a.push_back(max);
	int div = r/(n-1);
	int rem = r % (n-1);

	for (int i=1;i<n;i++) {
		int val = div;
		if (rem > 0) val++;
		rem--;
		a.push_back(val);
	}

	for (int i=0;i<n;i++) {
		cout << a[i] << " ";
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

