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
    vi a(n+2);
    for (int i=0;i<n;i++) {
        cin >> a[i+1];
    }
    int i=0;
    int cnt =0;
    while (i <n+1) {

        bool rise = false;
        bool descent = false;
        // rise phase
        while (i< n+1 && a[i] <a[i+1]) {
            // cout << "rise with i=" << i << endl;
            rise = true;
            i++;
        }

        // platueu/valley phase
        while (i <n+1 && a[i] == a[i+1]) {
            // cout << "plat with i=" << i << endl;
            i++;
        }

        // descent phase
        while (i <n+1 && a[i] > a[i+1]) {
            // cout << "descent with i=" << i << endl;
            descent = true;
            i++;
        }

        if (rise && descent) {
            // cout <<"inc"<<endl;
            cnt++;
        // } else if (rise && i==n-1) {
        //     cnt++;
        // } else if (descent && i==1) {
        //     cnt++;
        }
    }

    if (cnt > 1) {
        cout << "NO" <<endl;
    } else {
        cout <<"YES" <<endl;
    }
    // cout << cnt << endl;
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

