// Showstopper
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
#define rep(i, n) for (int i = 0; i < n; i++)
#define bck(i, n) for (int i = n - 1; i >= 0; i--)
#define mp make_pair
#define pb push_back

template <class T>
ostream& operator<<(ostream& os, vector<T> const& x) {
    os << "[ ";
    for (auto& y : x) os << y << " ";
    return os << "]";
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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

/* -------------------------- SOLUTION ---------------------*/

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(n);
    rep(i, n) cin >> b[i];

    int an = a[n - 1];
    int bn = b[n - 1];

    int amax = INT_MIN;
    int bmax = INT_MIN;
    if (an < bn) {
        rep(i, n) {
            if (a[i] < b[i]) {
                amax = max(amax, a[i]);
                bmax = max(bmax, b[i]);
            } else {
                amax = max(amax, b[i]);
                bmax = max(bmax, a[i]);
            }
        }
    } else {
        
        rep(i, n) {
            if (b[i] < a[i]) {
                amax = max(amax, a[i]);
                bmax = max(bmax, b[i]);
            } else {
                amax = max(amax, b[i]);
                bmax = max(bmax, a[i]);
            }
        }
    }

    if ((amax == an && bmax == bn) || (amax == bn && bmax == an)) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}
