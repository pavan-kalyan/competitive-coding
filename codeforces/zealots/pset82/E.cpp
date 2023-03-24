#include <algorithm>
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
#define       forn(i,n)              for(int i=0;i<n;i++)
#define       revn(i,n)              for(int i=n-1;i>=0;i--)

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) {
    os << "[ ";
    for(auto& y : x) os << y << " ";
    return os << "]";
}

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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    a[0] = 0;
    forn(i, n) {
        cin >> a[i+1];
    }
    vector<ll> pre(n+1);
    pre[0] = a[0];
    for (int i=1;i<n+1;i++) {
        pre[i] = pre[i-1] + a[i];
    }

    vector<ll> minH(n+1);
    minH[0] = a[0];
    for (int i=1;i<n+1;i++) {
        minH[i] = max(minH[i-1], a[i]);
    }
    // cout << "sum" <<endl;
    // cout << pre << endl;
    // cout << "min" <<endl;
    // cout << minH << endl;

    while (q-->0) {
        int k;
        cin >> k;

        // bin search array for upper bound of k
        auto it = upper_bound(minH.begin(), minH.end(), k);
        int idx = it - minH.begin() - 1;
        // cout << "found at " << it - minH.begin() << endl;
        cout << pre[idx] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >>t;
    while (t-->0) {
        solve();
    }
    return 0;
}

