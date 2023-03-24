#include<bits/stdc++.h>
#include <climits>
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

void solve() {
    int n,m, d;
    cin >>n >> m >>d;
    vi p(n);
    vi pos(n+1);
    vi a(m);
    for (int i=0;i<n;i++) {
        cin >> p[i];
        pos[p[i]] = i+1;
    }
    for (int i=0;i<m;i++) cin >> a[i];

    int minSteps = INT_MAX;
    for (int i=0;i<m-1;i++) {
        if (pos[a[i]] < pos[a[i+1]] && pos[a[i+1]] <= (pos[a[i]] + d)) {
            // first case: move right element to the left of left element
            minSteps = min(minSteps, pos[a[i+1]] - pos[a[i]]);


            // second case: move left as left as possible and right element as right as possible
            if (pos[a[i]] + d - pos[a[i+1]] + 1 <= (n-pos[a[i+1]] + pos[a[i]]-1)) {
                minSteps = min(minSteps, pos[a[i]] + d - pos[a[i+1]] + 1);
            }

        } else {
            minSteps = 0;
            break;
        }
    }
    cout << minSteps <<endl;
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

