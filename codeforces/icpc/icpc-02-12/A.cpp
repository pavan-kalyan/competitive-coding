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
    cin >> n;


    int offset = 100;
    vector<int> line(2*offset+2);
    for (int i=0;i<n;i++) {
        int tlx, tly, brx,bry;
        cin >> tlx >> tly >> brx >> bry;
        line[offset + bry]++;
        line[offset + tly + 1]--;
    }

    for (int i=1;i <=2*offset;i++) {
        line[i] = line[i] + line[i-1];
    }
    cout << line << endl;

    vi dp(2*offset+2);
    vi rdp(2*offset+2);
    for (int i=1;i <=2*offset;i++) {
        dp[i] = max(line[i], dp[i-1]);
    }
    for (int i=2*offset;i >=1;i--) {
        rdp[i] = max(line[i], rdp[i+1]);
    }
    int maxV = INT_MIN;
    for (int i=1;i <=2*offset;i++) {
        if (dp[i] + rdp[i+1] > maxV) {
            maxV = dp[i] + rdp[i+1];
        }
    }
    cout << maxV <<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

