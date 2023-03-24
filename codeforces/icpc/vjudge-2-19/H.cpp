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

int convert(string s) {
    vi a(4);
    int res =0;
    int i=0;
    while (s[i] != '.') {
        a[0] = a[0]*10 + (s[i] - '0');
        i++;
    }
    // cout << "fq" <<  bitset<32>(a[0] << 24) << endl;
    res = res | (a[0] << 24);
    // cout << bitset<32>(res) <<endl;
    i++;
    while (s[i] != '.') {
        a[1] = a[1]*10 + (s[i] - '0');
        i++;
    }
    res = res | (a[1] << 16);
    i++;
    while (s[i] != '.') {
        a[2] = a[2]*10 + (s[i] - '0');
        i++;
    }
    res = res | (a[2] << 8);
    i++;
    while ( i< s.length() && s[i] != '.') {
        a[3] = a[3]*10+ (s[i] - '0');
        i++;
    }
    res = res | (a[3]);
    // cout << bitset<32>(res) <<endl;
    return res;
}

void solve() {

    int n;
    cin >>n;
    vi a(n);
    for (int i=0;i<n;i++) {
        int t = 0;
        string s;
        cin >> s;
        a[i] = convert(s);
        // cout << endl<< to_string(a[i]) << endl;
    }
    //
    string mask = bitset<32>(a[0]).to_string();
    int minCnt = 32;
    for (int i=1;i<n;i++) {
        string t = bitset<32>(a[i]).to_string();
        int j=0;
        int cnt = 0;
        while (j< 32 && t[j] == mask[j]) {
            cnt++;
            j++;
        }
        if (cnt < minCnt) {
            minCnt = cnt;
            mask = t;
        }
    }
    if (minCnt == 0) minCnt = 32;
    cout << minCnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

