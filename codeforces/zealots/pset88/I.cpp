// Flexible String
// I used the editorial to solve this problem
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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    
    unordered_set<char> unique_a;
    for (char c : a) {
        unique_a.insert(c);
    }

    int res = INT_MIN;
    // generate all subsets of unique_a of size k using bitmasks
    for (int i = 0; i < (1 << min((int)unique_a.size(), k)); i++) {
        string subset = "";
        int j = 0;
        for (char c : unique_a) {
            if (i & (1 << j)) {
                subset += c;
            }
            j++;
        }
        if (subset.size() == k) {
            cout << "subset generated " <<subset <<endl;
            // subsets.pb(subset);
            // iterate over b and check if we can make a from it using subset as a set
            bool possible = true;
            for (int i=0;i<n;i++) {
                // use sliding window technique to calculate the number of equal substrings between a and b
                int count = 0;
                for (int j=0;j<n;j++) {
                    if (a[j] == b[j] || subset.find(a[j]) != string::npos) {
                        count++;
                    }
                }
            }
            res = max(res, possible ? 1 : 0);
        }
    }
    cout << res <<endl;
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

