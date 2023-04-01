// Minimize the Thickness
// 1:20-1:46
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
    vl pre(n);
    pre[0] = a[0];
    for(int i=1;i<n;i++) pre[i] = pre[i-1] + a[i];
    // cout << pre <<endl;

    int res = INT_MAX;
    rep(i, n) {
        bool valid = true;
        ll sum = pre[i];
        ll offset = sum;
        int len = i + 1;
        int start = i+1;
        // cout << "searching for " << sum << " from " << i << " to " << n << endl;
        int j = i+1;
        for (j=i+1;j<n;j++) {
            if (pre[j] - offset > sum) {
                valid = false;
                break;
            } else if (pre[j] - offset == sum) {
                offset += sum;
                len = max(len, j - start + 1);
                start = j + 1;
            }
        }
        // cout << "offset " << offset <<  endl;
        if (j == n && pre[j-1] - (offset - sum) != sum) valid = false;
        
        if (valid) {
            // cout << "valid for " << sum << " with len " << len << endl;
            res = min(res, len);
        }
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

