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
	vi a(n);
	vi pos(n+1);
	for (int i=0;i<n;i++) {
		cin >>a[i];
		pos[a[i]] = i;
	}

	int ans=0;
	if (n % 2 ==0) {
		int l = n/2;
		int r = n/2 +1;

		while (l >=0 && r <=n) {
			// cout << "considering " << l << " and " << r <<endl;

			if (l==r || pos[l] < pos[l+1] && pos[r] > pos[r-1]) {
				// if they are in the right place
				l--;
				r++;
				continue;
			} else {
				//anything else, we need to do a lot of operations
				// cout << "inc for " << r << endl;
				ans = (n-r+1);
				break;
			}
		}
	} else {
		// ignore middle element;
		int l = n/2;
		int r = n/2 +2;

		while (l >=0 && r <=n) {
			// cout << "considering " << l << " and " << r <<endl;
			if (l==r || pos[l] < pos[l+1] && pos[r] > pos[r-1]) {
				// if they are in the right place
				l--;
				r++;
				continue;
			} else {
				//anything else, we need to do a lot of operations
				// cout << "inc for " << r << endl;
				ans = (n-r+1);
				break;
			}
		}
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

