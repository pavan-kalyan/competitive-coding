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

int getSum(int l, int r, vi a) {
    
    cout << "? " << r-l+1 << " ";
    cout.flush();
    for (int i=l;i<=r;i++) {
        cout << i+1;
        if (i!=r) {
            cout << " ";
        }
    }
    cout << endl;
    cout.flush();
    int sum = 0;
    cin >> sum;
    return sum;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi pre(n+1);
    forn(i, n) {
        cin >> a[i];
        if (i==0) pre[i+1] = a[i];
        else pre[i+1] = pre[i] + a[i];
    }
    // cout << pre <<endl;

    int l = 0;
    int r = n-1;

    while (l <=r) {
        if (l==r) {
            cout <<"! " << l+1 << endl;
            cout.flush();
            return;
        }
        int m = l + (r-l)/2;

        // cout << "l, m, r " << l << " " << m << " " <<r <<endl;
        if(getSum(l, m, a) > pre[m+1] - pre[l]) {
            // cout << "going left" <<endl;
            r = m;
        // } else if (getSum(m+1, r, a) > pre[r+1] - pre[m+1]) {
        } else {
            l = m+1;
            // cout << "going right" <<endl;
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    int t;
    cin >>t;
    while (t-->0) {
        cout.flush();
        solve();
    }
    return 0;
}