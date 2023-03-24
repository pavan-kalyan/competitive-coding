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

const string pi = "3141592653589793238462643383279";

void solve() {
	string n; 
	cin >> n;

	int i=0;
	for (i=0;i<n.length();i++) {
		if (pi[i] != n[i]) {
			cout << i << endl;
			return;
		}
	}

	cout << i << endl;
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

