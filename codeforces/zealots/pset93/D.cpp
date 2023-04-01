// Palindromic Numbers
// 12:55- 1:30
// Took help from editorial
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

// method to subtract 2 numbers represented as strings
string subtract(string a, string b) {
    string ans = "";
    int n = a.size();
    int m = b.size();
    int i = n-1;
    int j = m-1;
    int carry = 0;
    while (i >= 0 && j >= 0) {
        int x = a[i] - '0';
        int y = b[j] - '0';
        int z = x - y - carry;
        if (z < 0) {
            z += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        ans = to_string(z) + ans;
        i--;
        j--;
    }
    while (i >= 0) {
        int x = a[i] - '0';
        int z = x - carry;
        if (z < 0) {
            z += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        ans = to_string(z) + ans;
        i--;
    }
    // remove leading zeroes
    while (ans[0] == '0') {
        ans = ans.substr(1);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string b;
    if (s[0] == '9') {
        rep(i, s.size()+1) {
            b += '1';
        }
    } else {
        rep(i, s.size()) {
            b += '9';
        }
    }
    cout << subtract(b, s) << endl;
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

