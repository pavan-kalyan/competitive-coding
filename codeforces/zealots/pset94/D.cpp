// Negatives and Positives
// 3:30-4:30, for DP
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
    vl a(n);
    rep(i, n) cin >> a[i];
    
    vector<vector<ll>> dp(2, vector<ll>(n+1));
    dp[0][0] = a[0];
    dp[0][1] = a[1] + a[0];
    
    dp[1][0] = -1*a[0];
    dp[1][1] = -1*a[0] + -1*a[1];
    for (int i=2;i<n;i++) {
        dp[0][i] = max({dp[0][i-1] + a[i], dp[1][i-1] + a[i]});
        dp[1][i] = max({dp[0][i-1] - 2*a[i-1] - a[i], dp[1][i-1] + 2*a[i-1] - a[i]});
    }
    // cout << a <<endl;
    // cout << dp[0] << endl;
    // cout << dp[1] << endl;
    cout << max(dp[0][n-1], dp[1][n-1]) << endl;

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

