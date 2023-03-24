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
    string a;
    cin >>a;
    int bCnt = 0;
    int aCnt = 0;
    int lastPos = 0;
    for (int i=0;i<n;i++) {
        if (a[i] == '1') {
            aCnt++;
        } else {
            bCnt++;
            lastPos = i;
        }
    }

    vector<vector<char>> p(n, vector<char>(n, '='));

    if (bCnt <=2 && bCnt >=1) {
        cout << "NO" <<endl;
        return;
    } else {
        cout << "YES" <<endl;
        for (int i=0;i<n;i++) {
            bool flag = false;
            for (int j=0;j<n;j++) {
                if (i==j) {
                    p[i][j] = 'X';
                } else if (a[i]=='1' || a[j] == '1') {
                    p[i][j] = '=';
                } else  if (flag == false) {
                    if ((i < j || (i==lastPos)) && a[j] != '1') {
                        p[i][j] = '+';
                        p[j][i] = '-';
                        flag = true;
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << p[i][j];
        }
        cout << endl;
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

