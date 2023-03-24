// Make Them Equal
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
ostream & operator << (ostream & os, vector <T> const& x) { os << ""; for(auto& y : x) os << y << " "; return os << ""; }

struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };

/* -------------------------- SOLUTION ---------------------*/

void solve(int t) {
    ll n;
    cin >> n;
    char c;
    cin >>c;

    string s;
    cin >>s;
    ll cnt=0;
    rep(i, n) {
        if (s[i] == c) {
            cnt++;
        }
    } 
    if (cnt == s.length()) {
        cout << 0 <<endl;
        return;
    }


    //check if 1 op is possible
    for (ll i=1;i<=n;i++) {
        bool found = true;
        ll ans = i;
        // cout << "searching for x=" << i <<endl;
        for (int j=1;j<=n;j++) {
        // cout << "searching for j=" << j*i <<endl;
            if (j*i-1 < s.length() && s[j*i-1] != c) {
                // cout << "break?" <<endl;
                found = false;
                break;
            }
        }
        if (found) {
            cout << 1 << endl;
            cout << ans << endl;
            return;
        }
    }

    ll ans = 0;
    vl res;
    if (cnt >=1 && s[s.length()-1] == c) {
        // apply only once
        cout << 1 << endl;
        cout << s.length() << endl;
    } else if (cnt >=1 && s[s.length()-1] !=c) {
        cout << 2 << endl;
        cout << s.length() << " ";
        cout << s.length() - 1 << endl;
    } else {
        cout << 2 << endl;
        cout << s.length() << " ";
        cout << s.length() - 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >>t;
    rep(i,t) {
        solve(t);
    }
    return 0;
}

