#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll t;
  cin>>t;
  for (ll i = 0; i < t; i++) {
    //cout << "--------------\n";
    ll n;
    cin>>n;
    vector<ll> a(n, 0);
    for (ll j = 0; j < n; j++)
      cin >> a[j];

    sort(a.begin(), a.end());

    ll low = LLONG_MIN, high = LLONG_MAX;
    ll count = 0;
    for (ll j = 0; j < n; j++) {
      //cout << "looking at " << a[j] << "\n";
      if (a[j] > low && a[j] < high) {
        low = max(low, a[j]/2);
        high = min(high, a[j]*2);
      } else { // a[j] >= high
        ll quotient = a[j] / (high - 1);
        ll remainder = a[j] % (high - 1);
        ll part_largest, part_smallest;
        if (remainder == 0) {
          //cout << "else 1\n";
          count += quotient - 1;
          part_largest = high - 1;
          part_smallest = high - 1;
        }
        else {
          //cout << "else 3\n";
          count += quotient;
          ll part1 = (remainder + high - 1)/2;
          ll part2 = (remainder + high - 1) - part1;
          if (quotient == 1) {
            part_largest = part2;
          } else {
            part_largest = high - 1;
          }
          part_smallest = part1;
        }

        //cout << "part_largest is "<<part_largest<<"\n";
        //cout << "part_smallest is "<<part_smallest<<"\n";
        low = max(low, part_largest/2);
        high = min(high, part_smallest*2);


      }


      //cout << "count is " << count << "\n";
      //cout << "low is "<< low << "\n";
      //cout << "high is "<< high << "\n";
    }

    cout << count << "\n";
    
  }
  return 0;
}
