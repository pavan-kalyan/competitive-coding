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

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {

    string s;
    getline(cin, s);
    unordered_map<char, string> m;
    m['a'] = "01";
    m['b'] = "1000";
    m['c'] = "1010";
    m['d'] = "100";
    m['e'] = "0";
    m['f'] = "0010";
    m['g'] = "110";
    m['h'] = "0000";
    m['i'] = "00";
    m['j'] = "0111";
    m['k'] = "101";
    m['l'] = "0100";
    m['m'] = "11";
    m['n'] = "10";
    m['o'] = "111";
    m['p'] = "0110";
    m['q'] = "1101";
    m['r'] = "010";
    m['s'] = "000";
    m['t'] = "1";
    m['u'] = "001";
    m['v'] = "0001";
    m['w'] = "011";
    m['x'] = "1001";
    m['y'] = "1011";
    m['z'] = "1100";
    m['0'] = "11111";
    m['1'] = "01111";
    m['2'] = "00111";
    m['3'] = "00011";
    m['4'] = "00001";
    m['5'] = "00000";
    m['6'] = "10000";
    m['7'] = "11000";
    m['8'] = "11100";
    m['9'] = "11110";

    int n= s.length();
    if (n==0) {
        cout << "NO" <<endl;
        return;
    }

    string res;
    for (int i=0;i<n;i++) {
        if (isalnum(s[i])) {
            s[i] = tolower(s[i]);
            res = res + (m[s[i]]);
        }
    }

    if (res.length()==0) {
        cout << "NO" <<endl;
        return;
    }
    // cout << res << endl;

    for (int i=0;i<res.length()/2;i++) {
        if (res[i] != res[res.length()-i-1]) {
            cout << "NO" <<endl;
            return;
        }
    }
    cout<< "YES" <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

