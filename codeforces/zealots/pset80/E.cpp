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
#define       forn(i,n)              for(int i=0;i<n;i++)
#define       revn(i,n)              for(int i=n-1;i>=0;i--)

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) {
    os << "[ ";
    for(auto& y : x) os << y << " ";
    return os << "]";
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
    char c;
    cin >> n;
    cin >> c;
    string s;
    cin >>s;
    int cnt = 0;
    forn(i, n) {
        if (s[i] == c) cnt++;
    }
    if (cnt == s.length()) {
        cout << 0 <<endl;
        return;
    }
    if (cnt == s.length()-1) {
        cout << 1 <<endl;
        int idx;
        forn(i, n) {
            if (s[i] != c) idx=i;
        }
        cout << idx + 2 <<endl;
        return;
    }

    for (int i=0;i<n;i++) {
        if (s[i] == c) {
            for (int j=0;j<n;j++) {

            }
        }
    }

    unordered_set<int> ids;
    forn(i, n) {
        if (s[i] !=c) ids.insert(i+1);
    }
    for (auto it = ids.begin();it !=ids.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
    int res = 1;
    if (ids.find(n) != ids.end()) {
        res++;
    }
    cout << res << endl;
    cout << n << " " << n-1<<endl;
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

