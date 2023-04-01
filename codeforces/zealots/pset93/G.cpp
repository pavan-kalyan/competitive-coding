// Absolute Sorting
// 1:50-2:35
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
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) {
        cin >> a[i];
    }
    
    ll start = LLONG_MIN;
    ll end = LLONG_MAX;
    for (int i=0;i<n-1;i++) {
        int x = a[i];
        int y = a[i+1];
        
        if (x == y) {
            start = max<ll>(start, LLONG_MIN);
            end = min<ll>(end, LLONG_MAX);
        } else if (x < y) {
            end = min<ll>(end, (x + y)/ 2);
        } else {
            if ((x+y)%2 != 0) {
                start = max<ll>(start, (x + y) / 2 + 1);
            } else {
                start = max<ll>(start, (x + y) / 2);
            }
        }
        
        if (start > end) {
            cout << -1 << endl;
            return;
        }
    }
    
    // cout << start << " " << end<< endl;
    if (start == LLONG_MIN) {
        cout << 0 << endl;
        return;
    }
    cout << max<ll>(start, INT_MIN) << endl;
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

