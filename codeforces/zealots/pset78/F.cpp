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

void printStack(stack<char> st) {
    while (!st.empty()) {
        char e = st.top();
        cout << e << " ";
        st.pop();
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<char> st;

    unordered_map<int, int> m;

    for (int i=0;i<2*n;i++) {
        if (s[i] == '(') {
            st.push('(');
        } else {
            // printStack(st);
            // cout << "current stack size " << st.size() << endl;
            m[st.size()]++;
            st.pop();
        }
    }

    int res = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        // cout << it -> first << " " << it -> second <<endl;
        if (it->first==1) {
            res += 1;
        } else {
            res += it->second;
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(true);
    // cin.tie(NULL);


    int t;
    cin >>t;
    while (t-->0) {
        solve();
    }
    return 0;
}
