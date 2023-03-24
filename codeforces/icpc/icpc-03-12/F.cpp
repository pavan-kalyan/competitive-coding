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
    cin >>n;
    string s;
    cin >> s;

    vi a(n);
    forn(i, n) cin >> a[i];

    vi b;
    string ss;
    for (int i=0;i<n;) {

        char c = s[i];
        int maxV = a[i];
        int j = i;
        while(j < n-1 && s[j] == s[j+1]) {
            maxV = max(a[j+1], maxV);
            j++;
        }
        i = j + 1;
        b.push_back(maxV);
        ss += c;
    }
    // cout << ss <<endl;
    // cout << b << endl;
    //
    if (b.size() <= 2) {
        cout << 0 << endl;
        return;
    } else if (b.size() == 3) {
        cout << b[1] << endl;
        return;
    }

    // vi dp(b.size());
    //
    // dp[0] = 0;
    // dp[1] = b[1];
    // dp[2] = b[2];
    //
    //
    // for (int i=3;i<b.size()-1;i++) {
    //     dp[i] = max(dp[i-2], dp[i-3]) + b[i];
    // }
    // // cout << dp << endl;
    //
    // int res = INT_MIN;
    // forn(i, b.size()) res = max(res, dp[i]);
    
    int res =0;

    b[0] = 0;
    b[b.size()-1] = 0;
    sort(b.begin(), b.end(), greater<int>());
    int cnt = 0;
    while (cnt < ceil((b.size()-2)/2)) {
        res += b[cnt];
        cnt++;
    }
    cout << res << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

