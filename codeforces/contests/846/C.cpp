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


class Compare {
public: 
	bool operator() (pii a, pii b) {
		return a.second > b.second;
	}

};

void solve() {

	int n,m;
	cin >> n >> m;
	vi a(n);
	for (int i=0;i<n;i++) cin >>a[i];
	vi c(m);
	for (int i=0;i<m;i++) cin >>c[i];

	priority_queue<int, vi> q;
	vi d(n);
	for (int i=0;i<n;i++)  d[a[i]-1]++;
	for (int i=0;i<n;i++) {
		if (d[i] > 0) q.push(d[i]);
	}

	sort(c.begin(), c.end(), greater<int>());

	int ans =0;
	for (int i=0;i<m && !q.empty();i++) {
		int max = q.top();
		q.pop();
		int sat = min(c[i], max);
		max -= sat;
		if (max > 0) q.push(max);
		ans +=sat;
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >>t;
	while (t-->0) {
		solve();
	}
	return 0;
}

