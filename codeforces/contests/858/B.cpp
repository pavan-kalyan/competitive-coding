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
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    map<int,int> m;
    forn(i, n) m[a[i]]++;

    for (int i=0;i< a[n-1];i++) {

        int acnt = m[i];
        if (acnt == 0) {
            cout << i << endl;
            return;
        }
        int bcnt = n-acnt;

        if (i==0) {
            if (bcnt >= acnt-1) {
                // 0 can be completely eliminated
                cout << 0 << endl;
                return;
            } 
        } else {
            if (bcnt != 0) {
                // i can be completely eliminated
                cout << i << endl;
                return;
            }        
        }
    }
    cout << a[n-1]+1 << endl;
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

