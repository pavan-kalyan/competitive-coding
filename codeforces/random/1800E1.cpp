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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a;
    cin >> b;

    unordered_map<char, int> ma;
    unordered_map<char, int> mb;

    forn(i,n) ma[a[i]]++;
    forn(i,n) mb[b[i]]++;
    for (auto it = ma.begin(); it != ma.end();it++) {
        mb[it->first] -= it->second;
        ma[it->first] = 0;
    }

    for (auto it = ma.begin(); it != ma.end();it++) {
        if (it->second > 0) {
            cout << "NO" << endl;
            return;
        }
    }
    for (auto it = mb.begin(); it != mb.end();it++) {
        if (it->second > 0) {
            // cout << " exiting here " <<endl;
            cout << "NO" << endl;
            return;
        }
    }
    // at this point both strings have same characters

    ma.clear();


    for (int i=0;i<n;i++) {
        if (i - k < 0 && i + k >=n) {
            if (a[i] != b[i]) {
                cout << "NO" <<endl;
                return;
            }
        }
    }
    //
    // for (int i=0;i<n;i++) {
    //     if (i -k <0 && i+k >=n) {
    //         // do nothing
    //     } else {
    //         ma[a[i]]++;
    //     }
    // }
    //
    // // cout << "printing ma map" << endl;
    // // for (auto it = ma.begin(); it != ma.end();it++) {
    // //     cout << it->first << ":" << it->second << ", ";
    // // }
    // // cout << endl;
    //
    // for (int i=0;i<n;i++) {
    //     if (a[i] != b[i]) {
    //         if (ma.find(b[i]) == ma.end() || ma[b[i]] <= 0) {
    //             cout << "NO" <<endl;
    //             return;
    //         }
    //     }
    //     if (ma.find(b[i]) != ma.end()) {
    //         // that specific character is fixed now, so remove from pool.
    //         ma[b[i]]--;
    //     }
    // }
    cout << "YES" <<endl;


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

