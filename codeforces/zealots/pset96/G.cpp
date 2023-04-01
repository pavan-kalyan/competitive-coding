// awoo's Favorite Problem
// 4:40 - 6
// I peeked at the editorial, but I did not use it for my approach/solution
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
    string s,t;
    cin >> s >> t;
    //count number of a,b, and c in s and t
    int a = 0;
    int b = 0;
    int c = 0;
    int a1 = 0;
    int b1 = 0;
    int c1 = 0;
    for (int i=0;i<n;i++) {
        if (s[i] == 'a') {
            a++;
        } else if (s[i] == 'b') {
            b++;
        } else {
            c++;
        }
        if (t[i] == 'a') {
            a1++;
        } else if (t[i] == 'b') {
            b1++;
        } else {
            c1++;
        }
    }
    if (a != a1 || b != b1 || c != c1) {
        cout << "NO" << endl;
        return;
    }

    
    int i=0;
    int j=0;
    for (i=0;i<n;i++) {
        // cout << "i: " << i << " j: " << j << endl;
        // cout << "s: " << s[i] << " t: " << t[i] << endl;
        if (s[i] != t[i]) {
            if (t[i] == 'b') {
                while (j < n && s[j] == 'a') {
                    j++;
                }
                if (s[j] != 'b') {
                    cout << "NO" << endl;
                    return;
                } else {
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            } else if (t[i] == 'c') {
                while (j < n && s[j] == 'b') {
                    j++;
                }
                if (s[j] != 'c') {
                    cout << "NO" << endl;
                    return;
                } else {
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            } else {
                cout << "NO" << endl;
                return;
            }
        } else {
            j = max(i+1,j);
        }
    }
    cout << "YES" << endl;
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

