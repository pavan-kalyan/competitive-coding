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

set<pii> back_edges;
set<pii> forward_edges;
vector<bool> visited;
void bfs(vector<vector<int>> a, int start) {

    queue<int> q;

    q.push(start);
    int n = a.size();
    bool discovered[n];
    for (int i=0;i<n;i++) discovered[i] = false;
    discovered[start] = true;

    while (!q.empty()) {
        int e = q.front();
        q.pop();
        // cout << "visiting " << e << endl;
        visited[e] = true;
        for (int i=0;i<n;i++) {
        // cout << "checking e -> i " << e << " -> " << i << endl;
            if (a[e][i] == 1) {
                // cout <<"found edge" <<endl;
                pii p = make_pair(min(e,i), max(e,i));
                //check if already visited
                 // cout << "visited? " << visited[i] << endl;
                if (e != i && (discovered[i])) {
                    // back edge?
                    if (forward_edges.find(p) == forward_edges.end()) {
                // cout <<"adding  back edge" << p.first << " " << p.second <<endl;
                        back_edges.insert(p);
                    }
                } else if ( e !=i) {
                // cout <<"adding " << i <<endl;
                    discovered[i] = true;
                    q.push(i);
                    forward_edges.insert(p);
                }
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i=0;i<m;i++) {
        int src, dst;
        cin >> src >> dst;
        src--;
        dst--;
        a[src][dst] = 1;
        a[dst][src] = 1;
    }
    visited.assign(n, false);
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            bfs(a, i);
        }
    }
    cout << back_edges.size() << endl;
    // cout << forward_edges.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

