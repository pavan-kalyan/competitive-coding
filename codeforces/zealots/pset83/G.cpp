// This was solved with help from editorial
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

    string s;
    cin >>s;

    /*
     * dp[i][j] represents the number of beautiful substrings that end at index i such that the last element in these substrings is the value of j (0 or 1)
    */
    ll dp[s.length()+1][2];

    dp[0][1] = 0;
    dp[0][0] = 0;
    ll res = 0;
    for (int i=1;i<=s.length();i++) {
        if (s[i-1] == '?') {
            // depending on the current element, we can build on top of the alternative element substrings.
            dp[i][1] = dp[i-1][0] + 1LL;
            dp[i][0] = dp[i-1][1] + 1LL;

        } else if (s[i-1] == '0') {
            // if the current value is 1, the previous value must have been 0.
            dp[i][1] = dp[i-1][0] + 1LL;
            // If the current value is 0, then we have a substring breaker. Needs to start fresh.
            dp[i][0] = 0;
        } else if (s[i-1] == '1') {
            // if the current value is 0, the previous value must have been 1.
            dp[i][0] = dp[i-1][1] + 1LL;
            // If the current value is 1, then we have a substring breaker. Needs to start fresh.
            dp[i][1] = 0;
        }

        // the reason we keep adding is because a character added to a substring of size n results in n+1 new substrings that include this new character, so n+1 is the new number of substrings that we need to add.
        res += max(dp[i][0], dp[i][1]);
    }
    cout << res << endl;
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
