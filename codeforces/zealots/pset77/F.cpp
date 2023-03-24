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

vector<vector<int>> visited;
vector<string> g;
void dfs(int x, int y, int px, int py) {

    if (visited[x][y] == 1 || g[x][y] == 'W') {
        return;
    }
    // cout << "visiting " << x << " "<< y << endl;
    visited[x][y] = 1;

    // first row
    if (x == 0) {
        if (g[x+1][y] == 'B' && x+1 !=px && y !=py) {
            // check bottom
            dfs(x+1, y, x, y);
            return;
        } else if (g[x][y+1] == 'B' && y <g[0].size()-1) {
            // check right
            dfs(x, y+1, x, y);
            return;
        }
    } else {
        if (g[x-1][y] == 'B'&& x-1 !=px && y !=py) {
            // check top
            dfs(x-1, y, x, y);
            return;
        } else if (g[x][y+1] == 'B' && y <g[0].size()-1 ) {
            // check right
            dfs(x, y+1, x, y);
            return;
        }
    }
}

void solve() {
    int m;
    cin >> m;
    visited.assign(2, vector<int>(m, 0));
    g.assign(2,"");

    for (int i=0;i<2;i++) {
        string s;
        cin >> g[i];
    }

    dfs(0, 0, -1,-1);
    bool dfs1 = true;

    for (int i=0;i<2;i++) {
        for (int j=0;j<m;j++) {
            if (g[i][j] == 'B' && visited[i][j] == 0) {
                dfs1 = false;
                break;
            }
        }
    }

    visited.assign(2, vector<int>(m, 0));
    dfs(1, 0,-1, -1);
    bool dfs2 = true;

    for (int i=0;i<2;i++) {
        for (int j=0;j<m;j++) {
            if (g[i][j] == 'B' && visited[i][j] == 0) {
                dfs2 = false;
                break;
            }
        }
    }

    if (dfs1 == false && dfs2 == false) {
        cout << "NO" <<endl;
        return;
    }

    cout << "YES" <<endl;
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

