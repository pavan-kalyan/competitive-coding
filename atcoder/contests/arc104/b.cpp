#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
	int n;
	cin >>n;
	string s;
	cin >>s;
	int res =0;
	int na = 0, ng = 0, nc = 0, nt = 0;
	for (int i=0; i< n; i++ ) {
		for (int j=i;j < n;j++) {
			//cout << "val= " << s[j] << " i= " << i << " j= " << j <<endl;
			if (s[j] == 'A') na++;
			if (s[j] == 'G') ng++;
			if (s[j] == 'C') nc++;
			if (s[j] == 'T') nt++;
			//cout << "na, ng, nc, nt " << na << " "<< ng << " "<< nc << " "<<nt <<endl;
			if (na == nt && ng == nc) {
				res++;
			}
		}
		ng =0;
		na = 0;
		nc = 0;
		nt = 0;
	}

	cout <<res <<endl;

	return 0;
}

