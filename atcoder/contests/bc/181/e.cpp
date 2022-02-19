#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
#define ll long long
using namespace std;

void display(vector<int> a);
int binSearch(vector<int> a, int k);
int main() {

	int n, m;
	cin >>n >>m;

	vector<int> h(n), w(m);
	for(int i = 0; i<n;i++) cin >>h[i];
	for(int i = 0; i<m;i++) cin >>w[i];

	sort(h.begin(), h.end());

	vector<int> prefix((n+1)/2), suffix((n+1)/2);

	//prefix sum
	for(int i = 0; i<n-1;i+=2) {
		int diff = h[i+1] - h[i];

		prefix[i/2] = diff + prefix[i/2 -1];
	}

	//suffix sum
	for(int i = n-1; i>1;i-=2) {
		int diff = h[i] - h[i-1];

		suffix[i/2] = diff + suffix[i/2 +1];
	}

	//display(prefix);
	//display(suffix);

	int minRes = INT_MAX;
	for (auto x: w) {
		int pos = binSearch(h, x);
		//cout << " pos " << pos << " "<<endl;
		int pairPos = pos/2;

		int prefixSum = pairPos > 0? prefix[pairPos-1]: 0;
		int suffixSum = pairPos < (n+1)/2 -1? suffix[pairPos+1]: 0;

		int sum = prefixSum + abs(h[2*pairPos] - x)  + suffixSum;
		//cout << sum <<endl;

		minRes = min(sum, minRes);
	}
	cout <<minRes<<endl;

	return 0;
}

void display(vector<int> a) {

	for(int i=0;i< a.size();i++) {
		cout << a[i] << " ";
	}
	cout <<endl;
}

//returns earliest position where key exists or should exist
int binSearch(vector<int> a, int k) {

	int l = 0;
	int r = a.size()-1;

	int m = l + (r-l)/2;
	while (l <= r) {

		m = l + (r-l)/2;

		if (a[m] == k) {
			return m;
		} else if (a[m] < k) {
			l = m +1;
		} else {
			r = m -1;
		}
	}
	return l;
}
