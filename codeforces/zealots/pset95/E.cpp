// Permutation Transformation
// 10:30-11:00
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
ostream & operator << (ostream & os, vector <T> const& x) { os << ""; for(auto& y : x) os << y << " "; return os << ""; }

struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };

/* -------------------------- SOLUTION ---------------------*/

struct node {
    int val;
    int index;
    node* left;
    node* right;
    node(int x, int idx) {
        val = x;
        index = idx;
        left = NULL;
        right = NULL;
    }
};

vector<int> depths;
node* build_tree(node* parent, pii p, int depth) {
    if (parent == NULL) {
        parent = new node(p.first, p.second);
        depths[p.second] = depth;
        return parent;
    }
    if (p.second < parent->index) {
        parent->left = build_tree(parent->left, p, depth+1);
    } else {
        parent->right = build_tree(parent->right, p, depth+1);
    }
    return parent;
}

void solve() {
    int n;
    cin >> n;
    depths.assign(n, 0);
    vector<int> a(n);
    priority_queue<pair<int, int>> pq;
    rep(i, n) {
        cin >> a[i];
        pq.push({a[i], i});
    }

    node * root = NULL;
    while (!pq.empty()) {
        pii p = pq.top();
        root = build_tree(root, p, 0);
        pq.pop();
    }
    
    cout << depths <<endl;
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

