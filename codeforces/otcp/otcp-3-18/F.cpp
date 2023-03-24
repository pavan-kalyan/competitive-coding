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
    os << "";
    for(auto& y : x) os << y << "";
    return os << "";
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

struct rook{
    int pos;
    int type;
    int og;
    rook(int pos, int type, int og) {
        this->pos = pos;
        this->type = type;
        this->og = og;
    };
};

bool compare_custom(const rook& lhs, const rook&rhs) {
    return lhs.pos < rhs.pos;
}

void solve() {
    int n1, n2;
    cin >> n1 >> n2;
    map<int, vector<rook>> xm;
    map<int, vector<rook>> ym;

    vector<int> r1(n1);
    vector<int> r2(n2);
    for (int i=0;i<n1;i++) {
        int x, y;
        cin >> x >> y;
        xm[x].push_back(rook(y, 0, i));
        ym[y].push_back(rook(x, 0, i));
    }

    for (int i=0;i<n2;i++) {
        int x, y;
        cin >> x >> y;
        xm[x].push_back(rook(y, 1, i));
        ym[y].push_back(rook(x, 1, i));
    }

    for (auto& pair : xm) {
        sort(pair.second.begin(), pair.second.end(), compare_custom);
    }
    for (auto& pair : ym) {
        sort(pair.second.begin(), pair.second.end(), compare_custom);
    }

    // for (auto it = xm.begin();it !=xm.end();it++) {
    //     cout << "printing for " << it->first << endl;
    //     forn(i, it->second.size()) {
    //         int t = it->second[i].pos;
    //         cout << t << " ";
    //     }
    //     cout << endl;
    // }
    for (auto it = xm.begin();it !=xm.end();it++) {
        vector<rook> t = it->second;
        // cout << "starting search for x=" << it->first <<endl;
        for (int i=0;i<t.size();) {
            int start = i;
            while (i < t.size() && t[i].type == t[start].type) {
                i++;
            }
            // cout << "finished first pair find at i=" << i << endl;
            if (i < t.size() && t[i].type != t[start].type) {
                // cout << "found for " << i-1 << endl;
                if (t[i].type == 1) {
                    r2[t[i].og] = 1;
                    r1[t[i-1].og] = 1;
                } else {
                    r1[t[i].og] = 1;
                    r2[t[i-1].og] = 1;
                }
            }
            // i++;
        }
    }
    for (auto it = ym.begin();it !=ym.end();it++) {
        vector<rook> t = it->second;
        // cout << "starting search for x=" << it->first <<endl;
        for (int i=0;i<t.size();) {
            int start = i;
            while (i < t.size() && t[i].type == t[start].type) {
                i++;
            }
            // cout << "finished first pair find at i=" << i << endl;
            if (i < t.size() && t[i].type != t[start].type) {
                // cout << "found for " << i-1 << endl;
                if (t[i].type == 1) {
                    r2[t[i].og] = 1;
                    r1[t[i-1].og] = 1;
                } else {
                    r1[t[i].og] = 1;
                    r2[t[i-1].og] = 1;
                }
            }
            // i++;
        }
    }
    cout << r1 << endl;
    cout << r2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

