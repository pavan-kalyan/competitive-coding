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

	vector<bool> visited;
	vector<int> res;

void dfs(vector<vector<int>> adj, int v) {
	visited[v] = true;
	for (int u : adj[v]) {
		if (!visited[u]) {
			dfs(adj, u);
		}
	}
	res.push_back(v);
}

void solve() {

	int n;
	cin >>n;
	vector<vector<int>> a(n, vector<int>(n-1));
	vector<vector<int>> adj(1001);
	res.clear();
	visited.assign(n+1, false);
	
	for (int i=0;i<n;i++) {
		for (int j=0;j<n-1;j++) {
			cin >> a[i][j];
		}
	}

	for (int i=0;i<n;i++) {
		for (int j=0;j<n-2;j++) {
			int src = a[i][j];
			int dst = a[i][j+1];
			// cout <<"adding s:" << src << " d: " << dst << endl;
			// if (find(adj[src].begin(), adj[src].end(),dst) == adj[src].end() ) {
				adj[src].push_back(dst);
			// }

		}
	}
	// for (int i=1;i<=n;i++) {
	// 	cout << "src: " << i << " : ";
	// 	for (int j=0;j<adj[i].size();j++) {
	// 		cout << adj[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	for (int i=1;i<=n;i++) {
		if (!visited[i]) {
			dfs(adj, i);
		}
	}
	for (int i=n-1;i>=0;i--) {
		cout << res[i] <<  " ";
	}
	cout <<endl;

}

void topsort() {
}

int main() {
	int t;
	cin >>t;
	while (t-->0) {
		solve();
	}
	return 0;
}

