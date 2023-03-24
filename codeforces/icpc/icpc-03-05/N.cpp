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
    int n,m;
    cin >> n >> m;

    vi a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int maxPos = -1;
    int maxV = INT_MIN;
    for (int i=0;i<n;i++) {
        if (a[i] > maxV) {
            maxPos = i;
            maxV = a[i];
        }
    }

    int cnt = 0;
    for (int i=0;i<n;i++) {
        if (a[i] == maxV) {
            cnt++;
        }
    }

    // cout << "maxPos " << maxPos << endl;

    vi res(n);
    ll sum = 0;
    // expand from peak to left
    int req = maxV;
    for (int i=maxPos;i>=0;i--) {
        res[i] = max(req - m, a[i]);
        req = res[i];
    }
    // expand left to peak
    for (int i=1;i<=maxPos;i++) {
        // range: [res[i-1] -m, res[i+1] + m]
        if (res[i] < res[i-1] - m) {
            res[i] = res[i-1] - m;
        }
    }
    // for (int i=maxPos;i<=maxPos + cnt -1;i++) {
    //     cout << "sjl ";
    //     res[i] = maxV;
    // }

    req = maxV;
    // expand peak to right
    // cout << "peak to right" <<endl;
    for (int i=maxPos; i<n;i++) {
        res[i] = max(req - m, a[i]);
        req  = res[i];
        // cout << res[i] << " ";
    }
    // cout << endl;

    // expand right to peak
    for (int i=n-2;i>=maxPos;i--) {
        // range: [res[i-1] -m, res[i+1] + m]
        if (res[i] < res[i+1] - m) {
            res[i] = res[i+1] - m;
        }
    }

    for (int i=0;i<n;i++){
        cout << res[i] << " ";
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

