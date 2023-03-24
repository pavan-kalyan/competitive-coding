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
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    int minV = 1;
    int maxV = n;
    int l=0;
    int r=n-1;
    while (l<=r) {
        // cout << "min " << minV << endl;
        // cout << "max " << maxV << endl;
        if ((a[l] == minV || a[l] == maxV) && (a[r] == minV || a[r] == maxV)) {
            minV = min(a[l],a[r]) + 1;
            maxV = max(a[l], a[r]) - 1;
            l++;
            r--;
        } else if (a[l] ==minV || a[l] == maxV) {
            if (a[l] == minV)
                minV = a[l] + 1;
            if (a[l] == maxV)
                maxV = a[l] - 1;
            l++;
        } else if (a[r] == minV || a[r] == maxV) {
            if (a[r] == minV)
                minV = a[r] + 1;
            if (a[r] == maxV)
                maxV = a[r] - 1;
            r--;
        } else {
            cout << l + 1 << " " << r + 1 <<endl;
            return;
        }
    }
    cout << -1 << endl;
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

