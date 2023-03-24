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
    string s;
    cin >> s;
    
    // count freq of each char
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    // if all chars have 1 freq then return n;
    bool all_one = true;
    for (auto p : freq) {
        if (p.second != 1) {
            all_one = false;
            break;
        }
    }

    if (all_one) {
        cout << s.length() <<endl;
        return;
    }
    
    // if all chars are the same, print -1
    bool all_same = true;
    char first = s[0];
    for (char c : s) {
        if (c != first) {
            all_same = false;
            break;
        }
    }
    if (all_same) {
        cout << -1 <<endl;
        return;
    }

    // get max from freq map directly
    int max_freq = 0;
    for (auto p : freq) {
        max_freq = max(max_freq, p.second);
    }
    
    int res = max_freq;
    int gaps = max_freq - 1;
    int rem = s.length() - max_freq;
    if (rem >= gaps) {
        res += rem;
    } else {
        res += gaps + 1;
    }
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

