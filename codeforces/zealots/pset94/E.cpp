// Reverse Binary Strings
// 4:30 - 5:07
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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int l = 0, r = 1;
    // find any alternating substring
    while (r < n && s[r] == s[r - 1]) {
        r++;
    }
    l=r-1;
    cout << "found first alt at " << l << " and " << r <<endl;
    
    ll ans = 0;
    while (l>=0 && r <n-1) {
        // expand the substring as long as it's alternating
        while (l >0 && s[l] != s[l - 1]) {
            l--;
        }

        while (r < n-1 && s[r] != s[r + 1]) {
            r++;
        }
        if (r >= n-1 && l <= 0) break;
        cout << "found alt at " << l << " and " << r <<endl;
        ans++;
        // reverse(s.begin() + l, s.begin() + r+1);
        s[l] = s[l] == '0' ? '1' : '0';
        s[r] = s[r] == '0' ? '1' : '0';
        // cout << s <<endl;
    }
    
    cout << ans <<endl;

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

