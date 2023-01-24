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

	ll a1,a2,a3,a4;
	cin >>a1 >> a2 >> a3 >> a4;

	ll aMood = 0;
	ll bMood = 0;

	if (a1 + a2 + a3 + a4 ==0) {
		cout << 0 <<endl;
		return;
	}
	if (a1 == 0) {
		cout << 1 <<endl;
		return;
	}

	aMood += a1;
	bMood += a1;
	ll res = a1;

	ll next = min(a2, a3);
	res += (next + next);
	a2 -= next;
	a3 -= next;

	// both have same mood right now
	if (a2 >0) {
		//alice can enjoy more
		next = min(a1, a2);
		res += next;
		bMood -=next;
		aMood +=next;
		a2 -=next;
	} else if (a3 > 0) { 
		next = min(a1, a3);
		res += next;
		aMood -=next;
		bMood +=next;
		a3 -=next;
	}


	if (aMood >0 && bMood >0) {
		next = min(a4, min(aMood, bMood));
		res +=next;
		a4 -= next;
		aMood -=next;
		bMood -=next;
	}
	if ((a4+ a2 + a3) > 0) res += 1;

	cout << res << endl;
}

int main() {
	int t;
	cin >>t;
	while (t-->0) {
		solve();
	}
	return 0;
}

