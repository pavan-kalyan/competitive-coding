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
    cin >>s;
    unordered_set<char> set;
    for (int i=0;i<5;i++) {
        set.insert(s[i]);
    }
    for (int i=0;i<7;i++) {
        string t;
        cin >> t;
        string out;
        if (t == s) {
            cout <<"WINNER"<<endl;
            return;
        }
        for (int j=0;j<5;j++) {
            if (t[j] == s[j]) {
                out.push_back('G');
            } else if (set.find(t[j]) != set.end()) {
                out.push_back('Y');
            } else {
                out.push_back('X');
            }
        }
        if (i<6)
            cout << out << endl;
    }
    cout << "LOSER" <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();
    return 0;
}
