// Years
// 1:30-1:50
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
    int n;
    cin >> n;
    vector<pii> a;
    
    for (int i = 0; i < n; ++i) {
        int b,d;
        cin >> b >>d;
        a.push_back({b,0});
        a.push_back({d-1,1});
    }
    sort(a.begin(), a.end(), [](pii x, pii y) {
            if (x.first == y.first) {
                return x.second < y.second;
            }
            return x.first < y.first;
    });
    // rep(i,2*n) {
    //     cout << a[i].first << " " << a[i].second << endl;
    // }
    
    int maxPop = 0;
    int pop=0;
    int maxYear = 0;
    for (int i=0;i<2*n;i++) {
        if (a[i].second == 0) {
            pop++;
        } else {
            pop--;
        }
        if (pop > maxPop) {
            maxPop = pop;
            maxYear = a[i].first;
        }
    }
    cout << maxYear << " " << maxPop << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

