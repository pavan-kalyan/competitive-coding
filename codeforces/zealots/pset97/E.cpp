// Delete Two Elements
// 1:48-2:20
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
    rep(i, n) cin >> a[i];

    ll sum = 0;
    rep(i, n) sum += a[i];
    // cout << sum <<endl;
    double avg = (double)sum / n;
    // cout << avg << endl;
    double newSum = avg*(n-2);
    // cout << newSum << endl;
    newSum = sum - newSum;
    // cout << newSum << endl;

    map<double, ll> m;
    rep(i, n) m[a[i]]++;
    ll ans = 0;
    rep(i, n) {
        if (m.find(newSum - a[i]) != m.end()) {
            ans += m[newSum - a[i]];
        }
        if (newSum - a[i] == a[i]) ans--;
    }
    cout << ans/2 << endl;

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