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
	string s;
	cin >> s;

	string r;
	for (int i=0;i<s.size();i++) {
		if ( i < s.size()-1 && s[i] == 'n' && s[i+1] == 'a') {
			r.append("ny");
		} else {
			r.push_back(s[i]);
		}
	}
	cout << r <<endl;
}

int main() {
	solve();
	return 0;
}

