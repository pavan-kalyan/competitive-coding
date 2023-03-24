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

bool satisfied(vi a, double k, int len) {
    double maxCover = a[0] + k;
    if (a[0] - k > 0) {
        // left not covered
        return false;
    }

    for (int i=1;i<a.size();i++) {
        if (a[i] - k > maxCover) {
            return false;
        }
        maxCover = a[i] + k;
        // cout << "maxCover for a[i]=" << a[i] <<" " << maxCover << endl;
    }

    if (a[a.size()-1] + k < len) {
        return false;
    }

    return true;
}

double eps = 1e-9;

void solve() {
    ll n,len;
    cin >> n >> len;
    vector<ll> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double maxD = 0;
    maxD = max<double>(maxD, a[0] - 0);
    for (int i=0;i<n-1;i++) {
        maxD = max<double>(maxD, (double)(a[i+1] - a[i])/(double) 2);
    }
    maxD = max<double>(maxD, len - a[a.size()-1]);
    printf("%0.10f\n", maxD/1.);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

