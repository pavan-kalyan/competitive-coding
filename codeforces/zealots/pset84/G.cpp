// Add to Neighbour and Remove
// PENDING
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
int check(vi a, int target) {

    int sum = 0;
    int res = 0;
    int l =0;
    for (int i=0;i<a.size();i++) {
        if (a[i] + sum == target) {
            res += ((i-l) -1);
            sum = 0;
            l = i+1;
        }
    }
    if (sum != 0) {
        return -1;
    }
    return res;
}
void solve() {
    int n;
    cin >>n;
    vi a(n);
    int r = 0;
    rep(i, n) {
        cin >>a[i];
        r+=a[i];
    }

    vl p(n+1);
    rep(i, n) {
        p[i+1] = a[i] + p[i];
    }
    cout << p <<endl;
    int l = 0;

    int minOp = INT_MAX;
    while (l<=r) {
        int m = l + (r-l)/2;

        int counts = check();
        if (counts >0) {
            minOp = min();
        } else if ()
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

