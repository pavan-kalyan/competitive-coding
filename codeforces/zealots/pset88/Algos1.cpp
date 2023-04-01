#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pii;
#define       rep(i,n)              for(int i=0;i<n;i++)
#define       bck(i,n)              for(int i=n-1;i>=0;i--)
#define mp make_pair
#define pb push_back

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) { os << "[ "; for(auto& y : x) os << y << " "; return os << "]"; }

struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };

/* -------------------------- SOLUTION ---------------------*/

void solve() {
    
    string X = "abfcde";
    string Y = "abde";
    string Z = "agbec";
    int n=X.length(), m=Y.length(), p=Z.length();
    
    int dp[n+1][m+1][p+1];
    
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            for (int k=0;k<=p;k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            for (int k=1;k<=p;k++) {
                
                if (X[i-1] == Y[j-1] && Y[j-1] == Z[k-1]) {
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                } else {
                    dp[i][j][k] = max(
                        {dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1], dp[i - 1][j - 1][k], dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]});
                }
            }
        }
    }
    cout << dp[n][m][p] <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

