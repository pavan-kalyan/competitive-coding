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
    vector<ll> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    ll gcda = a[0];
    ll gcdb = a[1];
    for (int i=2; i<n; i++) {
        if (i % 2 == 0) {
            gcda = gcd<ll>(gcda, a[i]);
        } else {
            gcdb = gcd<ll>(gcdb, a[i]);
        }
    }
    // cout << "gcd of odd -> " << gcda <<endl;
    // cout << "gcd of even -> " << gcdb <<endl;
    // check gcd of all odd numbers
    for (int i=0; i<n; i++) {
        if (i % 2==0 && a[i] % gcdb == 0) {
            gcdb = 1;
            break;
        }
    }
    for (int i=0; i<n; i++) {
        if (i % 2==1 && a[i] % gcda == 0) {
            gcda = 1;
            break;
        }
    }
    if ((gcda == 1 && gcdb==1)) {
        cout << 0 << endl;
    } else if (gcda == 1) {
        cout << gcdb << endl;
    } else {
        cout << gcda << endl;
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

