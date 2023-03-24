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

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
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
    int n,q;
    cin >>n >> q;
    vi a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());

    vi pre;
    pre.push_back(a[0]);
    for (int i=1;i<n;i++) {
        pre.push_back(a[i] + pre[i-1]);
    }
    // cout << pre <<endl;
    for (int i=0;i<q;i++) {
        int k;
        cin >>k;
        if (k > pre[pre.size()-1]) {
            cout << -1 << endl;
        } else {
             int pos= lower_bound(pre.begin(), pre.end(), k) - pre.begin();
            cout << pos + 1 << endl;
        }
    }
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

