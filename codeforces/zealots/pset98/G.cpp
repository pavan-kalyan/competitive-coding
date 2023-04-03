// Berpizza
// 4:00-4:20
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
    int q;
    cin >> q;

    int cnt =0;
    auto cmp = [](pii const &lhs, pii const &rhs) {
        if (lhs.first == rhs.first) return lhs.second > rhs.second;
        return lhs.first < rhs.first;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    unordered_set<int> s;
    vi a;
    int mc = 0; //points to next possible eligible customer
    while (q-- > 0) {
        int t;
        cin >> t;
        if (t == 1) {
            int m;
            cin >> m;
            a.pb(cnt);
            pq.push(mp(m, cnt++));
        } else if (t == 2) {
            while (s.find(mc) != s.end()) mc++;
            cout << mc + 1 << " ";
            s.insert(mc);
            mc++;
        } else if (t == 3) {
            while (!pq.empty() && s.find(pq.top().second) != s.end()) {
                pq.pop();
            }
            cout << pq.top().second + 1 << " ";
            s.insert(pq.top().second);
            pq.pop();
        }
    }
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();
    return 0;
}

