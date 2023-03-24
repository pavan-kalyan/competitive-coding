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
    int n;
    cin >>n;
    vi a(n);
    forn(i, n) cin >> a[i];

    int req = 0;
    int p = 0;

    int res = 0;
    for (int i=0; i<n; i++) {
        // cout << "p, req = " << p << " "<< req << endl;
        if (a[i] == 1) {
            p++;
            req++;
        } else if (p!= 0) {
            
            int x;
            int y;
            if (p % 2 !=0) {
                x = p /2;
                y = p/2 + 1;
                // cout <<"odd detected " << x << " "<< y <<endl;
            } else {
                x = p/2;
                if (x % 2 == 0) {
                    y = x + 1;
                    x = x - 1;
                } else {
                    y = x;
                }
            }
            req = (x+2-1)/2 + (y+2-1)/2;
        }
        // cout << req << " " << endl;
        res = max(res, req);
    }
    cout << res << endl;
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

