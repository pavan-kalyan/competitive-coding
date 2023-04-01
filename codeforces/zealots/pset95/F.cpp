// White-Black Balanced Subtrees
// 11:05
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

struct node {
    int val;
    char color;
    node* left;
    node* right;
    node(int x, char color) {
        val = x;
        color = color;
        left = NULL;
        right = NULL;
    }
};

int res = 0;
void solve() {
    int n;
    cin >> n;
    vi parents(n-1);
    rep(i, n-1) cin >> parents[i];
    string colors;
    cin >> colors;

    // construct tree from parents array
    vector<node*> nodes(n);
    rep(i, n) {
        nodes[i] = new node(i, colors[i]);
    }
    rep(i, n-1) {
        if (parents[i] < i) {
            nodes[parents[i]]->left = nodes[i];
        } else {
            nodes[parents[i]]->right = nodes[i];
        }
    }
    
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

