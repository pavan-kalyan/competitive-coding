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
    int n,q;
    cin >> n >> q;
    vi a(n);
    ll sum = 0;
    vi pre(n);
    forn(i, n) {
        cin >>a[i];
        sum +=a[i];
        if (i==0) {
            pre[i] = a[i];
        } else {
            pre[i] = pre[i-1] + a[i];
        }
    }
    // cout << a <<endl;
    // cout << pre <<endl;

    while(q-->0) {
        ll l,r,k;
        cin >> l >> r >> k;
        r--;
        l--;
        ll nSum = (r-l+1)*k;
        ll cSum = 0;

        if (l ==0) {
            cSum = pre[r];
        } else {
            cSum = pre[r] - pre[l-1];
        }
        // cout << sum - cSum + nSum <<endl;
        if ((sum - cSum + nSum) % 2 ==1) {
            cout << "YES"<<endl;
        } else {
            cout <<"NO" <<endl;
        }
    }
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

