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
	cin>>n;
	vi a(n);
	for (int i=0;i<n;i++) {
		cin >>a[i];
	}
	vi pre(n);
	for (int i=0;i<n;i++) {
		if (i==0) pre[i] = a[i];
		else pre[i] = pre[i-1] + a[i];
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

