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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    ll n, k;
    cin >> n >> k;

    ll sum =0;
    vi a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        // sum +=a[i];
    }
    // intuition. Give easiest chests, the Golden key, because it can cover more chests/sec that way.
    sort(a.begin(), a.end());

    // all silver keys are handled in one swoop.
    sum += a[n-1];

    // for a[n-1], golden key can cover how many chests?
    ll temp = 0;
    ll count =0;
    for (int i=n-k-1;i>=0;i--) {
        temp += a[i];
        count++;
        if (temp > a[n-1]) {
            sum += (temp - a[n-1]);
            break;
        }
    }

    for (int i=0;i<n-k-count;i++) {
        sum += a[i];
    }

    cout << sum << endl;

}

int main() {
	int t;
	cin >>t;
	while (t-->0) {
		solve();
	}
	return 0;
}

