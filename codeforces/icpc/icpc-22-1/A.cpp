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

	ll x;
	cin >> x;
	for (int i=1;i<=x;i++) {

		ll b = x/i;
		if (b <= 2*i && i*b == x && i <= b) {
			cout << 1 << endl;
			return;
		}
	}
	cout << 0 <<endl;
	return;

}

int main() {
	int t;
	cin >>t;
	while (t-->0) {
	solve();
	}
	return 0;
}

