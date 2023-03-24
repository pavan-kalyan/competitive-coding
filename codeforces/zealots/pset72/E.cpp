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
    string s;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0;i <n;i++) {
        cin >> s;
        for (int j=0;j<m;j++) {
            a[i][j] = s[j] - '0';
        }
    }

    int minV = INT_MAX;
    for (int i=0;i <=n-2;i++) {
        for (int j=0;j<=m-2;j++) {

            int cnt = 0;
            for (int k=0;k<2;k++) {
                for (int l=0;l<2;l++) {
                    if (a[i+k][j+l] == 1) cnt++;
                }
            }
            if (cnt == 0) {
                minV = 0;
                break;
            }
            if (cnt == 4) minV = min(minV, 3);
            if (cnt == 3) minV = min(minV, 2);
            if (cnt <=2) minV = min(minV, 1);
        }
        if (minV == 0) break;
    }
    // cout << "minV " << minV << endl;
    int oCnt =0;
    for (int i=0;i <n;i++) {
        for (int j=0;j<m;j++) {
            if (a[i][j] == 1) oCnt++;
        }
    }

    if (oCnt ==0) {
        cout << 0 << endl;
    } else if (minV ==0) {
        cout << oCnt << endl;
    } else {
        cout << oCnt - minV + 1 << endl;
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

