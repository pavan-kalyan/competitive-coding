#include <algorithm>
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
    vector<unordered_set<int>> a(5);
    for (int i=0;i<n;i++) {

        for (int j=0;j<5;j++) {
            int t;
            cin >> t;
            if (t==1) {
                a[j].insert(i);
            }
        }
    }

    for (int i=0;i<5;i++) {
        for (int j=i+1;j<5;j++) {

            vi inter;
            inter.reserve(n+1);
            auto inter_it = set_intersection(a[i].begin(), a[i].end(), a[j].begin(), a[j].end(), inter.begin());
            inter.resize(inter_it-inter.begin());


            vi uni;
            uni.reserve(n+1);
            auto union_it = set_union(a[i].begin(), a[i].end(), a[j].begin(), a[j].end(), uni.begin());
            uni.resize(union_it-uni.begin());

            if (uni.size() == n && inter.size() ==0 && a[i].size() > 0 && a[j].size() > 0) {
                cout << "YES" <<endl;
                return;
            }
        }
    }

    cout << "NO" <<endl;

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

