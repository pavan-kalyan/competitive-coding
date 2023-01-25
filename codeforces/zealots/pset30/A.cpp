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
	int maxRight =0;
	int maxLeft = 0;
	int maxUp = 0;
	int maxDown = 0;
	for (int i=0;i<n;i++) {
		int x, y;
		cin >> x >> y;
		if (x > 0) {
			maxRight = max(maxRight, x);
		} else if (x < 0) {
			maxLeft = max(maxLeft, -1*x);
		} else if (y > 0) {
			maxUp = max(maxUp, y);
		} else {
			maxDown = max(maxDown, -1*y);
		}
	}

	cout << 2*maxRight + 2*maxLeft + 2*maxUp + 2*maxDown <<endl;
}

int main() {
	int t;
	cin >>t;
	while (t-->0) {
		solve();
	}
	return 0;
}

