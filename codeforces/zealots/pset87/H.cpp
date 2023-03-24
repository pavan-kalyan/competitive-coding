// Restoring the permutation
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pii;
#define       rep(i,n)              for(int i=0;i<n;i++)
#define       bck(i,n)              for(int i=n-1;i>=0;i--)
#define mp make_pair
#define pb push_back

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) { os << ""; for(auto& y : x) os << y << " "; return os << ""; }

struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };

/* -------------------------- SOLUTION ---------------------*/

void solve() {
    int n;
    cin >>n;
    vi q(n);
    rep(i, n) cin >> q[i];
    
    vi p;
    p.assign(n, -1);
    vi r;
    r.assign(n, -1);
    set<int> s;
    rep(i, n) s.insert(i+1);
    set<int> ss;
    rep(i, n) ss.insert(i+1);

    for (int i=0;i<n;i++) {
        if (i==0 || q[i-1] !=q[i]) {
            p[i] = q[i];
            r[i] = q[i];
            s.erase(q[i]);
            ss.erase(q[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == -1) {
            p[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    cout << p <<endl;
    // cout << r <<endl;
    int maxV = INT_MIN;
    for (int i = 0; i <n; i++) {
        maxV = max(maxV, r[i]);
        if (r[i] == -1) {
        // cout << " searching for " << maxV<< endl;
            r[i] = *--ss.lower_bound(maxV);
            ss.erase(r[i]);
        }
    }
    cout << r <<endl;
    
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

