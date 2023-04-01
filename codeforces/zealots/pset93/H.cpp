// Price Maximization
// 2:40-4:05, WA
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
    int n,k;
    cin >> n >> k;
    vi a(n);
    rep(i,n) {
        cin >> a[i];
    }
    map<int, priority_queue<int>> m;
    rep(i,n) {
        m[a[i] % k].push(a[i]);
    }
    
    // print key and every element in the priority queue
    // for (auto it = m.begin(); it != m.end(); it++) {
    //     cout << it->first << " ";
    //     priority_queue<int> left = it->second;
    //     while (!left.empty()) {
    //         cout << left.top() << " ";
    //         left.pop();
    //     }
    //     cout << endl;
    // }
    
    vi leftOvers;
    ll ans = 0;
    int end = k/2;
    if (k%2 !=0){
        end+=1;
    }
    for (int i=1;i<end;i++) {
        if (m.find(i) == m.end() || m.find(k-i) == m.end()) {
            continue;
        }

        priority_queue<int> left = m[i];
        priority_queue<int> right = m[k-i];
        while (!left.empty() && !right.empty()) {
            // cout << left.top() << " " << right.top() << endl;
            ans += (left.top() + right.top())/k;
            left.pop();
            right.pop();
        }
        m[i] = left;
        m[k-i] = right;
    }
    
    if (k%2 == 0) {
        if (m.find(k/2) != m.end()) {
            priority_queue<int> left = m[k/2];
            while (!left.empty()) {
                int top = left.top();
                left.pop();
                if (!left.empty()) {
                    // cout << "adding same " << top << " " << left.top() << endl;
                    ans += (top + left.top())/k;
                    left.pop();
                } else {
                    leftOvers.push_back(top);
                }
            }
        }
    }

    for (int i=0;i<k;i++) {
        if (m.find(i) == m.end() || (i== k/2 && k%2 == 0)) {
            continue;
        }
        priority_queue<int> left = m[i];
        while (!left.empty()) {
            leftOvers.push_back(left.top());
            left.pop();
        }
    }
    
    sort(leftOvers.begin(), leftOvers.end(), greater<int>());

    vi visited(leftOvers.size(), 0);
    for (int i=0;i<leftOvers.size();i++) {
        if (visited[i] == 1) {
            continue;
        }
        int secondElem = INT_MAX;
        int secondIdx;
        int max = -1;
        for (int j=i+1;j<leftOvers.size();j++) {
            if (visited[j] == 1) {
                continue;
            }
            // cout << "considering " << leftOvers[i] << " " << leftOvers[j] << endl;
            if ((leftOvers[i] + leftOvers[j]) / k > max) {
                secondElem = leftOvers[j];
                secondIdx = j;
                max = (leftOvers[i] + leftOvers[j]) / k;
            } else if ((leftOvers[i] + leftOvers[j]) / k == max) {
                if (leftOvers[j] < secondElem) {
                    secondElem = leftOvers[j];
                    secondIdx = j;
                }
            }
        }
        visited[i] = 1;
        visited[secondIdx] = 1;
        // cout << "adding " << leftOvers[i] << " " << secondElem << endl;
        ans += (leftOvers[i] + secondElem)/k;
    }
    cout << ans <<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    int t;
    cin >>t;
    while (t-->0) {
        solve();
    }
    return 0;
}

