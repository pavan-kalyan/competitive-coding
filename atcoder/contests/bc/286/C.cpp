#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;


void solve() {

	int n, a,b;
	cin >>n >> a >> b;
	string s;
	cin >> s;

	s = s + s;
	ll finalCost =LLONG_MAX;
	//cout << s <<endl;
	for (int i=0;i<n;i++) {
		ll cost = (ll) i* (ll)a;

		for (int j=0;j<n/2;j++) {
			//cout << "comp " << j+i << " and " <<i + n-j-1 <<endl;
			if (s[j + i] != s[i+n-j-1]) {
				cost +=b;
			}
			//cout << "cost " << cost << endl;
		}
		//cout << "cost " << cost << endl;

		finalCost = min(finalCost, cost);
	}
	cout << finalCost <<endl;
}

int main() {
	solve();
	return 0;
}

