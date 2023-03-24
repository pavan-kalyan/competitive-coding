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
    int n, m;
    cin >> n >>m;
    vector<vector<int>> b(n, vector<int>(m));
    vector<vector<int>> c(n, vector<int>(m));
    // number -> parent row pair
    vector<pair<int, int>> t;
    vector<int> counter;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> b[i][j];
            t.push_back(make_pair(b[i][j], i));
        }
    }
    sort(t.begin(), t.end());
    int k =0;
    int start = m-1;
    for (int i=0;i<n;i++) {
        sort(b[i].begin(), b[i].end());
        int cnt =0;
        for (int j=0;j<m;j++) {
        }
    }
    for (int i=0;i<n;i++) {
        // sort(b[i].begin(), b[i].end());
        // cout << b[i] << endl;
        int j =(start+1)%m;
        int cnt = 0;
        while (cnt < m) {
            // cout << b[i][j] << " ";
            c[i][cnt] = b[i][j];
            j = (j+1)%m;
            cnt++;
        }
        // cout << "reached here" << endl;
        cout << endl;
        start = (start - 1)%m;
    }

    for (int i=0;i<m;i++) {
        int minV = c[0][i];
        for (int j=0;j<n;j++) {
            minV = min(minV, c[j][i]);
        }
        cout << minV << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);


    int t;
    cin >>t;
    while (t-->0) {
        solve();
    }
    return 0;
}

