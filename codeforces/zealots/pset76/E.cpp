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

struct e {
    int f;
    int s;
    int o;
};

bool checkSorted(vector<e> a) {

    forn(i, a.size()-1) {
        if (a[i].f > a[i+1].f) {
            return false;
        }
    }
    forn(i, a.size()-1) {
        if (a[i].s> a[i+1].s) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<e> a(n);

    forn(i, n) {
        int ai;
        cin >> ai;
        a[i].f = ai;
        a[i].o = i;
    }
    forn(i, n) {
        int bi;
        cin >> bi;
        a[i].s=bi;
    }
    vector<e> b(n);
    forn(i, n) {
        b[i] = a[i];
    }


    sort(b.begin(), b.end(), [] (const auto& lhs, const auto& rhs) {
             if (lhs.f < rhs.f) return true;
             else if (rhs.f < lhs.f) return false;
             else {
                 return lhs.s < rhs.s;
             }
         });

    vector<pii> res;
    if (!checkSorted(b)) {
        cout << -1 << endl;
        return;
    } else {
        bool swapped = false;
        for (int i=0;i<n-1;i++) {
            for (int j=0;j<n-i-1;j++) {
                if (a[j].f > a[j+1].f || a[j].s > a[j+1].s) {
                    swap(a[j], a[j+1]);
                    res.push_back(make_pair(j, j+1));
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }

    cout << res.size() <<endl;
    forn(i, res.size()) cout << res[i].first + 1 << " "<< res[i].second + 1 << endl;

    // forn(i, n) cout << a[i].f << " ";
    // cout << endl;
    // forn(i, n) cout << a[i].s << " ";
    // cout << endl;
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

