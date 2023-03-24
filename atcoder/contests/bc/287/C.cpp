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

vector<bool> visited;
bool dfs(vector<vector<int>> adj, int parent, int src) {

    visited[src] = true;
    cout << "parent, src " << parent << " " << src << endl;

    bool cycleDetected = false;
    for (int i=0;i<adj[src].size();i++) {

        cout << "considering " << adj[src][i] << endl;

        if (parent != 0 && adj[src][i] == parent) {
            cout << "detected back edge" << endl;
            return true;
        }

        if (visited[adj[src][i]] == false) {
            cycleDetected = cycleDetected || dfs(adj, src, adj[src][i]);
        } else {
            return true;
        }
    }
    return cycleDetected;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    // cout << "adj size" << adj.size() << endl;
    for (int i=0;i<m;i++) {
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }

    visited.assign(n+1, false);
    for (int i=1;i<=n;i++) {
        if (visited[i]) continue;
        cout <<"starting fresh " << i <<endl;
        bool cycleDetected = dfs(adj, 0, i);
        if(cycleDetected) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    solve();
    return 0;
}

