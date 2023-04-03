// Reverse Sort
// 1:51-2:18
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
    vi a(n);
    int oCnt = 0;
    rep(i,n) {
        char c;
        cin >> c;
        if (c == '1') {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
        if (a[i] == 1) {
            oCnt++;
        }
    }
    // check if a is sorted
    bool sorted = true;
    for (int i=0;i<n-1;i++) {
        // cout << a[i] << " "<< a[i+1] << endl;
        if (a[i] > a[i+1]) {
            // cout <<"breaking sort " << i <<endl;
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << 0 << endl;
        return;
    }
    
    
    int i = 0;
    int j = n-oCnt;
    // cout << "starting with " << i << " " << j << endl;
    
    vi res;
    int ans=0;
    unordered_set<int> s;
    while (i < (n-oCnt) && j < n) {
        while (i < (n-oCnt) && i<j && a[i] ==0) {
            i++;
        }
        if (i == n-oCnt) break;
        // i now points to a one before j
        while (j < n && a[j] == 1) {
            j++;
        }
        // cout << i << " " << j << endl;
        // j now points to a zero that is to be swapped
        if (s.find(i + 1) == s.end()) res.pb(i + 1);
        s.insert(i+1);
        if (s.find(j + 1) == s.end()) res.pb(j + 1);
        s.insert(j+1);
        i++;
        j++;
    }
    sort(res.begin(), res.end());
    cout << 1 << endl;
    cout << res.size() << " " << res << endl;
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

