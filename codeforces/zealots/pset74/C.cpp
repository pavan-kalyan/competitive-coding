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
    int n;
    cin >>n;
    vi a(n);
    bool flag = false;
    for (int i=0;i<n;i++) {
        cin >>a[i];
        if (a[i] == 1) flag = true;
    }
    int gcdd=a[0];
    for (int i=1;i<n;i++) {
        gcdd = gcd(gcdd, a[i]);
    }
    if (flag || gcdd == 1) {
        cout << 0 << endl;;
        return;
    }
    int cost = INT_MAX;
    for (int i=n-1;i>=0;i--) {
        if (gcd(gcdd, gcd(i+1,a[i])) == 1) {
            cost = min(cost, n - (i+1) +1);
            // cout << cost << endl;
            // return;
        }
    }
    vi g(n);
    for (int i=0;i<n;i++) {
        g[i] = gcd(a[i], i+1);
    }
    reverse(g.begin(), g.end());
    // cout << g << endl;

    for (int i=0;i<n;i++) {

        for (int j=i+1;j<n;j++) {
            if (gcd(g[i], g[j]) == 1) {
                cost = min(cost, i+ j + 2);
            }
        }
    }
    cout << cost <<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    int t;
    cin >>t;
    while (t-->0) {
        solve();
    }
    return 0;
}

