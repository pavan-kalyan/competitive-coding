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

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
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

void solve() {

    int n,m;
    cin >> n >>m;
    unordered_map<int, int, custom_hash> map;
    for (int i=0;i<m;i++) {
        int t;
        cin >> t;
        map[t] = 1;
    }
    vector<stack<int>> res;

    for (int i=1;i<=n;i++) {
        stack<int> st;

        // cout << "new stack/c" <<endl;
        // cout << "pushing" << i << endl;
        st.push(i);
        int j=i+1;
        while (j<=n && map.find(j-1) != map.end()) {
            // cout << "pushing " << j <<endl;
            st.push(j);
            j++;
        }
        i = j-1;
        res.push_back(st);
    }

    for (int i=0;i<res.size();i++) {

        while (!res[i].empty()) {
            cout << res[i].top() << " ";
            res[i].pop();
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

