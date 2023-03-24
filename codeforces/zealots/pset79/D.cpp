#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll t;
  cin>>t;
  for (ll i = 0; i < t; i++) {
    //cout << "--------------\n";
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n, 0);
    vector<ll> b(q, 0);
    for (ll j = 0; j < n; j++)
      cin >> a[j];
    for (ll j = 0; j < q; j++)
      cin >> b[j];

    sort(a.begin(), a.end(), greater<ll>());

    for (ll j = 1; j < n; j++)
        a[j] += a[j-1];



    for (ll k = 0; k < q; k++) {
        //cout << "---- " << k << " -----\n";
        if (b[k] > a[n-1])
            cout << "-1\n";
        else {
            ll low = 0, high = n-1;
            while (low <= high) {
                ll mid = low + ((high-low)/2);
                if (a[mid] == b[k] || low == high) {
                    cout << (mid+1)<<"\n";
                    break;
                } else if (a[mid] < b[k]) {
                    low = mid+1;
                } else {
                    high = mid;
                }
            }
        }
        
    }  
  }
  return 0;
}
