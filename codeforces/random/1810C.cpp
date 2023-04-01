// Make It Permutation
// 11:52 - 12:53
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
    ll n,c,d;
    cin >> n >> c >> d;
    vl a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll minSum = LLONG_MAX;
    vl mins;
    ll cSum = 0;
    ll j = 1;
    for (ll i=0;i<n;i++) {
        // cout << "i: " << i << " j: " << j << " a[i]: " << a[i] << " cSum: " << cSum << " minSum: " << minSum << endl;
        if (a[i] < j) {
            // cost of making everything a permutation
            minSum = min(minSum, cSum + c + c*(n-i-1));
            // the cumulative sum of making 1 to j a permutation
            cSum += c;
        } else if (a[i] > j) {
            // case 1
            minSum = min(minSum, cSum + d + c*(n-i));
            // case 2
            cSum += (a[i]-j)*d;
            minSum = min(minSum, cSum + c*(n-i));
            j = a[i];
            if (a[i] == j) {
                minSum = min(minSum, cSum + c * (n - i - 1));
                j++;
            }
        } else {
            // cost of making everything a permutation
            minSum = min(minSum, cSum + c*(n-i-1));
            j++;
        }
    }
     cout << minSum <<endl;
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

