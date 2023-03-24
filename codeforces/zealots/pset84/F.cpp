// Cake Assembly Line
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
#define       rep(i,n)              for(int i=0;i<n;i++)
#define       bck(i,n)              for(int i=n-1;i>=0;i--)
#define mp make_pair
#define pb push_back

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) { os << "[ "; for(auto& y : x) os << y << " "; return os << "]"; }

struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };

/* -------------------------- SOLUTION ---------------------*/

void solve() {
    int n, w, h;
    cin >> n >> w >> h;

    vi c(n);
    vi d(n);
    vector<pii> cr(n);
    vector<pii> dr(n);
    rep(i, n) {
        cin >> c[i];
        cr[i] = mp(c[i] - w, c[i] + w);
    }
    rep(i, n) {
        cin >> d[i];
        dr[i] = mp(d[i] - h, d[i] + h);
    }


    int minV = INT_MIN;
    int maxV = INT_MAX;
    for (int i=0;i<n;i++) {
        pii crange = cr[i];
        pii drange = dr[i];

        // leftmost possible center
        minV = max(minV, drange.second - crange.second);
        // rightmost possible center
        maxV = min(maxV, drange.first - crange.first);
        if (minV > maxV) {
            cout << "NO" <<endl;
            return;
        }
    }
    cout << "YES" <<endl;
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

