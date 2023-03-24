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
    rep(i, n) cin >>a[i];
        bool sorted = true;
    rep(i,n-1) {
        if (a[i] >a[i+1]) {
            sorted = false;
        }
    }
    if (sorted) {
        cout <<"0" <<endl;
        return;
    }
    unordered_map<int, int> m;
    rep(i, n) m[a[i]]++;

    for (int i=n-1;i>=1;i--) {
        // this element is within order but repeated
        if (a[i] >a[i-1] && m[a[i]] > 1 || a[i] <a[i-1]) {
            //answer should be number of unique characters from here till 0
            m[a[i]]--;
        if (m[a[i]] == 0) m.erase(a[i]);
            cout << m.size() << endl;
            return;
        }
        m[a[i]]--;
        if (m[a[i]] == 0) m.erase(a[i]);
    }
    cout << 0 << endl;
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

