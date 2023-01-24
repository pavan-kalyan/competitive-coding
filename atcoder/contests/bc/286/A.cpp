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
	int n,p,q,r,s;
	cin >> n >> p >> q >> r >> s;
	vi a(n);
	for (int i=0;i<n;i++) cin >> a[i];

	p--;
	q--;
	s--;
	r--;
	while (p <=q) {
		int t = a[p];
		a[p] = a[r];
		a[r] = t;
		p++;
		r++;
	}
	
	for (int i=0;i<n;i++) {
		cout << a[i] << " ";
	}
	cout <<endl;

}

int main() {
	solve();
	return 0;
}

