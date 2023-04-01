// Minimize Distance
// 3:40-4:30
// I used the editorial to solve this problem
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
ostream & operator << (ostream & os, vector <T> const& x) { os << "[ "; for(auto& y : x) os << y << " "; return os << "]"; }

struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };

/* -------------------------- SOLUTION ---------------------*/

void solve() {
    int n,k;
    cin >> n >> k;
    vi l;
    vi r;
    rep(i,n) {
        int t ;
        cin >> t;
        if (t < 0) {
            l.pb(-t);
        } else {
            r.pb(t);
        }
    }
    sort(r.begin(), r.end(), greater<int>());
    ll cnt = 0;
    ll dist = 0;
    for (int i=0;i<r.size();i++) {
        cnt++;
        if (cnt == k) {
            dist += 2*r[i-cnt+1];
            cnt = 0;
        }
    }
    if (cnt > 0 && !r.empty()) {
        dist += 2*r[r.size()-1 - cnt + 1];
    }
    cnt = 0;
    sort(l.begin(), l.end(), greater<int>());
    for (int i=0;i<l.size();i++) {
        cnt++;
        if (cnt == k) {
            dist += 2*l[i-cnt+1];
            cnt = 0;
        }
    }
    if (cnt > 0 && !l.empty()) {
        dist += 2*l[l.size()-1 - cnt + 1];
    }

    if (!l.empty() && !r.empty()) {
        cout << dist - max(r[0], l[0]) << endl;
    } else if (!r.empty()) {
        cout << dist - r[0] << endl;
    } else {
        cout << dist - l[0] << endl;
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

