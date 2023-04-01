// Minimum Ties
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

void swap (int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}
void permute(int index, vi& arr, int n) {
   if (index == n-1) {
       for (int k = 0; k < n; ++k) {
            printf ("%d ", arr[k]);
       }
       printf ("\n");
       return;
   }
   for (int i = index; i < n; i++) {
       swap (arr[index], arr[i]);
       permute (index+1, arr, n);
       swap (arr[i], arr[index]);
   }
   return;
}

void solve() {
    int n;
    cin >>n;
    int a[n][n];
    
    if (n==2) {
        cout << 0 << endl;
        return;
    }
    
    if (n % 2 ==0) {
        vi s(n-1);
        for (int i=0;i<n-1;i++) {
            if (i<(n-1)/2) s[i] = 1;
            else if (i==(n-1)/2) s[i] = 0;
            else s[i] = -1;
        }
        
        for (int i=0;i<n;i++) {
            int k = (n-1 - i) % (n-1);
            for (int j=0;j<n;j++) {
                if (i==j) continue;
                a[i][j] = s[k];
                k = (k + 1) % (n-1);
            }
        }

    } else {
        vi s(n-1);
        for (int i=0;i<n-1;i++) {
            if (i<(n-1)/2) s[i] = 1;
            else s[i] = -1;
        }

        for (int i=0;i<n;i++) {
            int k = (n-1 - i) % (n-1);
            for (int j=0;j<n;j++) {
                if (i==j) continue;
                a[i][j] = s[k];
                k = (k + 1) % (n-1);
            }
        }
    }
    
    rep(i,n) {
        for (int j=i+1;j<n;j++) {
            // if (i==j) cout << "0" << " ";
            cout << a[i][j] << " ";
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

