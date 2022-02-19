#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
#define ll long long
using namespace std;

int main() {
	ll n;
	cin >>n;
	ll sum = 0;
	while (n-- > 0) {
		ll a,b;
		cin >>a >>b;
		ll totalSum = b*(b+1)/2;
		ll preSum = (a-1)*(a)/2;
		sum += (totalSum - preSum);
	}
	cout << sum <<endl;
	return 0;
}

