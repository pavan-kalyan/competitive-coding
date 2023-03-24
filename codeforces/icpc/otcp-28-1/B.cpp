#include <bits/stdc++.h>
#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include <vector>
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
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vi b(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = make_pair(t, i);
        b[i] = a[i].first;
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    unordered_map<int, int, custom_hash> map;
    for (int i = 0; i < n; i++) {
        map[b[i]]++;
        if (map[b[i]] > 2) {
            cout << "No" << endl;
            return;
        }
        if (b[i] < i) {
            cout << "No" << endl;
            return;
        }
    }

    map.clear();

    vi p(n);
    vi s(n + 1);

    for (int i = 1; i <= n; i++) {
        s[i] = 1;
        map[a[i].first]++;
    }

    for (int i = 0; i < n; i++) {
        int e = a[i].first;
        if (s[e] == 1) {
            p[a[i].second] = e;
            s[e] = 0;
        } else {
            for (int j = 1; j < e; j++) {
                if (s[j] == 1 && map.find(j) == map.end()) {
                    p[a[i].second] = j;
                    s[j] = 0;
                    break;
}
            }
        }
    }

    vi q(n);
    for (int i = 1; i <= n; i++) {
        s[i] = 1;
        map[a[i].first]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        int e = a[i].first;
        if (s[e] == 1) {
            q[a[i].second] = e;
            s[e] = 0;
        } else {
            for (int j = e - 1; j >= 1; j--) {
                if (s[j] == 1 && map.find(j) == map.end()) {
                    q[a[i].second] = j;
                    s[j] = 0;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (p[i] == 0 || q[i] == 0) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}
