// Elemental Decompress
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
    cin >> n;
    vector<pii> a(n);
    rep(i, n) { 
        cin >> a[i].first; 
        a[i].second = i;
    }

    set<int> s1, s2;
    rep(i, n) s1.insert(i+1);
    rep(i, n) s2.insert(i+1);

    vector<pii> p;
    vector<pii> q;
    
    sort(a.begin(), a.end(), [](pii a, pii b) {
        return a.first < b.first;
    });
    
    
    

    for (int i=0;i<n;i++) {
        if (s1.find(a[i].first) != s1.end()) {
            p.push_back(mp(a[i].first, a[i].second));
            s1.erase(a[i].first);
        } else {
            if (s1.empty()) {
                cout << "NO" << '\n';
                return;
            }
            p.pb(mp(*s1.begin(), a[i].second));
            s1.erase(*s1.begin());
        }
    }
    for (int i=0;i<n;i++) {
        if (p[i].first == a[i].first) {
            if (s2.empty()) {
                cout << "NO" << '\n';
                return;
            }
            q.pb(mp(*s2.begin(), a[i].second));
            s2.erase(*s2.begin());
        } else {
            if (s2.find(a[i].first) != s2.end()) {
                q.pb(mp(a[i].first, a[i].second));
                s2.erase(a[i].first);
            } else {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    
    cout << "YES" << '\n';
    sort(p.begin(), p.end(), [](pii a, pii b) {
        return a.second < b.second;
    });
    sort(q.begin(), q.end(), [](pii a, pii b) {
        return a.second < b.second;
    });
    rep(i, n) cout << p[i].first << " ";
    cout << endl;
    rep(i, n) cout << q[i].first << " ";
    cout << endl;
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

