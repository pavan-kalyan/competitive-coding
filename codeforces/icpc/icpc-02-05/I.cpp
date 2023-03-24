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
    vi c(n);
    for (int i=0;i<n;i++) cin >>c[i];
    sort(c.begin(),c.end());

    double maxV =1.0;
    for (int i=n;i>0;i--) {
        if (c[i-1] > i) {
            cout << "-1"<<endl;
            return;
        } else {
            double val = ((double)c[i-1])/((double)i);
            maxV = min(val, maxV);
        }
    }

    cout << maxV << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}
