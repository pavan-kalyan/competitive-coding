// Arrays Sum
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

/*-------------------------- SOLUTION -----------------------*/

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >>a[i];
    sort(a.begin(), a.end());
    
    vector<set<int>> sets;
    sets.pb(set<int>());
    int m = 1;
    for (int i=0;i<n;i++) {
        
        int level = 0;
        int req = a[i];
        // cout <<"dfsing for " << req << endl;
        while (req >=0 && level < sets.size() && sets[level].find(req) == sets[level].end()) {
        // cout <<"dfsing for " << req << " at level " << level << endl;
            if (sets[level].size() < k) {
                // cout << "adding " << req << " at level " << level << endl;
                sets[level].insert(req);
            } else {
                if (k == 1) {
                    cout << -1 << endl;
                    return;
                }
                int prevMax = *sets[level].rbegin();
                req = req - prevMax;
                if (level == sets.size()-1) {
                    level++;
                    sets.pb(set<int>());
                    sets[level].insert(0);
                } else {
                    level++;
                }
                m = max(m, level + 1);
            }
        }
    }
    cout << m << endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    int t;
    cin >>t;
    while (t-->0) {
        solve();
    }
    return 0;
}

