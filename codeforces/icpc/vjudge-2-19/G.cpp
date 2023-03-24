#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void computefib(long long n, vector<long long>& fib) {
  for (int i = 2; i < n; i++) {
    fib[i] = ((fib[i-1]% 1000007)+(fib[i-2]% 1000007)) % 1000007;
  }
}

int main(){
  long long n;
  cin>>n;
  vector<long long> fib(n, 1);
  computefib(n, fib);
  cout<<(fib[n-1]% 1000007)<<"\n";


  return 0;
}