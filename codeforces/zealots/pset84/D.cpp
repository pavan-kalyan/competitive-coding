// Paint the Array
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
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
    rep(i, n) {
        cin >> a[i];
    }

    ll gcd1 = a[0];
    ll gcd2 = a[1];
    for(int i=2;i<n;i++) {
        if (i % 2 ==0) {
            gcd1 = gcd<ll>(gcd1, a[i]);
        } else {
            gcd2 = gcd<ll>(gcd2, a[i]);
        }
    }

    // cout << "gcd1 " << gcd1 << endl;
    // cout << "gcd2 " << gcd2 << endl;

    bool first = true;
    bool second = true;
    rep(i, n) {
        if ( i % 2 !=0) {
            if (a[i] % gcd1 == 0) {
                first = false;
                break;
            }
        }
    }

    rep(i, n) {
        if ( i % 2 ==0) {
            if (a[i] % gcd2 == 0) {
                second = false;
                break;
            }
        }
    }

    if (first) {
        cout << gcd1 << endl;
    } else if (second) {
        cout << gcd2 << endl;
    } else {
        cout << 0 << endl;
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

