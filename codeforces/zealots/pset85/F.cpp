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

vl visited;
vl g;
vl leaves;

void dfs(ll start, vl& res) {
    if (visited[start] == 1) {
        // cout << "already visited " << start + 1 << endl;
        return;
    }

    // cout << "visiting " << start + 1 <<endl;
    visited[start] = 1;
    ll node = start + 1;
    res.pb(node);
    // cout << "temp res " << res << endl;
    if (g[start] == start + 1) {
        // cout <<"reached root, returning" <<endl;
        return;
    }
    dfs(g[start]-1, res);
}

void solve() {
    int n;
    cin >> n;
    g.assign(n,0);
    leaves.assign(n, 1);
    rep(i, n) {
        cin >> g[i];
        leaves[g[i]-1] = 0;
    }
    vector<vl> res;
    visited.assign(n,0);
    rep(i, n) {
        if (leaves[i] == 1) {
            vl t;
            dfs(i, t);
            if (t.size() >0) {
                res.pb(t);
            }
        }
    }

    if (res.size() == 0) {
        cout << 1 << endl;
        cout << 1 << endl;
        cout << 1 << endl;
    } else {
        cout << res.size() <<endl;
        rep(i, res.size()) {
            cout << res[i].size() << endl;;
            reverse(res[i].begin(), res[i].end());
            cout << res[i];
            cout << endl;
        }
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

