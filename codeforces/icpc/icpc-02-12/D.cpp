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
    int n;
    cin >>n;
    unordered_map<string, string> m;
    m["a"] = "as";
    m["i"] = "ios";
    m["y"] = "ios";
    m["l"] = "les";
    m["n"] = "anes";
    m["ne"] = "anes";
    m["o"] = "os";
    m["r"] = "res";
    m["t"] = "tas";
    m["u"] = "us";
    m["v"] = "ves";
    m["w"] = "was";
    for (int i=0;i<n;i++) {
        
        string s;
        cin >>s;
        int r = s.length()-1;
            string temp;
        if (s.length()>=2) {
            temp = s[r-1];
            temp = temp + s[r];
            // cout << "temp " << temp <<endl;
            if (m.find(temp) != m.end()) {
                cout << s.substr(0, s.length()-2) + m[temp] << endl;
                continue;
            }        
        }
        temp = s[r];
        if (m.find(temp) != m.end()) {
            cout << s.substr(0, s.length()-1) + m[temp] << endl;
            continue;
        }
        cout << s + "us" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

