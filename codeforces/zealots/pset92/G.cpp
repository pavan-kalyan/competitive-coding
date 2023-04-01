// Column Swapping
// This solution was co-authored by chatGPT (only as auto complete)
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
    int n, m;
    cin >> n >> m;
    int a[n][m];
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    // check if every row in matrix a is sorted
    bool sorted = true;
    int row = -1;
    rep(i, n) {
        rep(j, m - 1) {
            if (a[i][j] > a[i][j + 1]) {
                sorted = false;
                row = i;
                break;
            }
        }
    }
    if (sorted) {
        cout << "1 1" << endl;
        return;
    }
    
    // copy row i from matrix into another vector
    vector<int> v;
    rep(i, m) {
        v.push_back(a[row][i]);
    }
    sort(v.begin(), v.end());
    
    int cnt =0;
    vi pos;
    rep(i, m) {
        if (a[row][i] != v[i]) {
            pos.pb(i);
            cnt++;
        }
    }
    
    if (cnt >=3) {
        cout << "-1" << endl;
        return;
    }
    
    // swap columns pos[0] and pos[1]
    rep(i, n) {
        swap(a[i][pos[0]], a[i][pos[1]]);
    }
    // once again check if a is sorted now
    sorted = true;
    rep(i, n) {
        rep(j, m - 1) {
            if (a[i][j] > a[i][j + 1]) {
                sorted = false;
                break;
            }
        }
    }
    if (!sorted) {
        cout << "-1" << endl;
        return;
    }
    cout << pos[0] + 1 << " " << pos[1] + 1 << endl;
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

