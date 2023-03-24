#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
  int A, B, C, D;
  cin>>A>>B>>C>>D;
  int gcdd = __gcd(A, B);

  if (D % gcdd) {
    cout << "No solution.\n";
  } else {
    int CD = C+D;
    int kA = 0;
    int k = 0;
    while (true) {
      if (kA >= CD && (kA-D) % B == 0)
        break;
      else {
        kA += A;
        k++;
      }
    }
    string tr = "truck";
    string bt = "boat";

    int bs = (kA-D) / B;

    if (k != 1)
      tr += 's';

    if (bs != 1)
      bt += 's';

    cout << "We need "<< k << " " << tr << " and " << bs << " "<< bt <<".\n";
  }
  return 0;
}