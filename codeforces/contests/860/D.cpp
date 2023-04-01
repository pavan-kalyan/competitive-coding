// Shocking Arrangement
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
    vi a(n);
    rep(i,n) cin >>a[i];
    vi pos;
    vi neg;
    bool allZeros = true;
    rep(i,n) {
        if (a[i] != 0) allZeros = false;
        if (a[i] > 0) {
            pos.pb(a[i]);
        } else {
            neg.pb(a[i]);
        }
    }
    if (allZeros) {
        cout <<"No" <<endl;
        return;
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    

    vi res;
    int i=0;
    int j=0;
    int sum =0;
    if (pos.size() > neg.size()) {
        int sum = 0;
        while (i< pos.size() && j < neg.size()) {
            if (j >= neg.size()) {
                break;
            }
            while (i < pos.size() && sum <abs(neg[j])) {
                sum +=pos[i];
                res.pb(pos[i]);
                i++;
            }
            res.pb(neg[j]);
            sum += neg[j];
            j++;
        }
        // append remaining leftovers in either of the array
        while (i < pos.size()) {
            res.pb(pos[i]);
            i++;
        }
        while (j < neg.size()) {
            res.pb(neg[j]);
            j++;
        }
    } else {
        int sum = 0;
        while (i< pos.size() && j < neg.size()) {
            if (i >= pos.size()) {
                break;
            }
            res.pb(pos[i]);
            while (j < neg.size() && sum < pos[i]) {
                sum +=abs(neg[j]);
                res.pb(neg[j]);
                j++;
            }
            sum -= pos[i];
            i++;
        }
        // append remaining leftovers in either of the array
        while (i < pos.size()) {
            res.pb(pos[i]);
            i++;
        }
        while (j < neg.size()) {
            res.pb(neg[j]);
            j++;
        }
    }
    cout << "Yes" <<endl;
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

