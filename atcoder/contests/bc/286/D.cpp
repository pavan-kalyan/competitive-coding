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

	int n,x;
	cin >> n >>x;
	vector<vector<int>> a(n,vector<int>(n));
	for (int i=0;i<n;i++) {
		int t, b;
		cin >> t >> b;
		a[i][0] = t;
		a[i][1] = b;
	}

	// sort using first element
	sort(a.begin(), a.end());

	int dp[51][10001];
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=x;j++) {
			dp[i][j] = -1;
		}
	}

	for (int i=1;i<=n;i++) {
		for (int j=1;j<=x;j++) {
			// cout << "i,j" << i << " " << j <<endl;
			// i=1,j=4

			// first check if satisfied with previous denominations
			if (i-1 >=0 && dp[i-1][j] >=0) {
				dp[i][j] = 0;
			} else {
				if (j - a[i-1][0] >=0 && dp[i][j-a[i-1][0]] >=0) {
					// cout << "found previous of the same denomination" <<endl;
					//checking if we have any coins of this demonination left
					if (dp[i][j-a[i-1][0]] + 1 <= a[i-1][1]) {
						dp[i][j] = dp[i][j-a[i-1][0]] + 1;
					}
				} else {
					// initialization section of the dp tabulation
					if (a[i-1][0] == j) {
						dp[i][j] = 1;
					}
				}
			}
		}
	}
	// for (int i=1;i<=n;i++) {
	// 	for (int j=0;j<=x;j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout <<endl;
	// }

	if (dp[n][x] == -1) {
		cout << "No" <<endl;
	} else {
		cout << "Yes" <<endl;
	}
	
}

int main() {
	solve();
	return 0;
}

