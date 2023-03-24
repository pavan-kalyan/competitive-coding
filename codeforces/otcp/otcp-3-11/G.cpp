#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n,t;
    cin>>n>>t;
 
    vector<ll> a(n, 0);
 
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0)
            a[i] += a[i-1];
    }
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
 
    ll maxi = 0;
    for (ll i = 0; i < n; i++) {
        ll tofind = t + (i == 0 ? 0 : a[i-1]);
        ll low = i, high = n-1,mid=i;
        ll best = -1;
        cout <<"new bsearch"<<endl;
        while (low <= high) {
            cout << low << " " << high << " " << a[mid] << " " << tofind<<"\n";
            mid = low + (high-low)/2;
            if (a[mid] <= tofind) {
                best = mid;
                low = mid + 1;  
            } else if (a[mid] > tofind) {
                high = mid - 1;
            }
        }
        cout << "best" << best <<endl;
        if (best == -1) continue;
        maxi = max(maxi, best-i + 1);
 
    }
 
    cout << maxi << "\n";
 
 
 
    
 
  return 0;
}
