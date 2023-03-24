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
    cin >>n;
    vi a(n);
    forn(i, n) cin >> a[i];
    vi max(n);
    vi min;
    sort(a.begin(), a.end(), greater<int>());
    for(int i=0;i<n;i++) {
        if (a[i] > 0) {
            if (i==0) max[i] = 1;
            else max[i] = max[i-1] + 1;
        } else {
            if (i==0) max[i] = -1;
            else max[i] = max[i-1] - 1;
        }
    }

    unordered_map<int, int> m;
    unordered_set<int> s;
    for(int i=0;i<n;i++) {
        if (m.find(abs(a[i])) != m.end()) {
            s.insert(abs(a[i]));
        }
        m[abs(a[i])]++;
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        min.push_back(1);
        min.push_back(0);
    }
    for (int i=0;i< m.size() - s.size();i++) {
        min.push_back(i+1);
    }

    forn(i, n) cout << max[i] << " ";
    cout << endl;
    forn(i, n) cout << min[i] << " ";
    cout << endl;

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

