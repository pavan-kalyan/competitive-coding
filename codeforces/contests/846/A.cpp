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
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}


	int oddCount =0;
	int evenCount =0;
	vi oddIdx;
	vi evenIdx;
	for (int i=0;i<n;i++) {
		if (a[i] % 2 == 1) {
			oddCount++;
			oddIdx.push_back(i + 1);
		} else {
			evenCount++;
			evenIdx.push_back(i + 1);
		}
	}

	if (oddCount >= 1 && evenCount >=2) {
		// 2e 1o = odd
		cout << "YES" << endl;
		for (int i=0;i<1;i++) {
			cout << oddIdx[i] << " ";
		}
		for (int i=0;i<2;i++) {
			cout << evenIdx[i] << " ";
		}
		cout <<endl;
	} else if (oddCount >=3) {
		// 3o = odd
		cout << "YES" << endl;
		for (int i=0;i<3;i++) {
			cout << oddIdx[i] << " ";
		}
		cout <<endl;
	} else {
		//even
		cout << "NO" <<endl;
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

