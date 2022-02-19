#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
#define ll long long
using namespace std;

bool containsNegative(vector<int> a);
int main() {
	string s;

	cin >>s;

	if (s.size() == 1) {
		if (s[0] == '8') cout << "Yes" <<endl;
		else cout << "No" << endl;
		return 0;
	} else if (s.size() ==2) {
		if (stoi(s) % 8 == 0) {
			cout << "Yes" <<endl;
			return 0;
		}
		swap(s[0], s[1]);
		if (stoi(s) % 8 == 0) cout << "Yes" <<endl;
		else cout <<"No" <<endl;
		return 0;
	} else {

		vector<int> freqArr(10, 0);

		// recording count of each digit
		for (char x: s) freqArr[x - '0']++;

		ll oSum = accumulate(freqArr.begin(), freqArr.end(), 0);
		for (int i= 112; i < 1000; i+=8) {
			vector<int> temp = freqArr;
			for (char x: to_string(i)) temp[x - '0']--;
			ll tempSum = accumulate(temp.begin(), temp.end(), 0);
			if (!containsNegative(temp)) {
				cout <<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout << "No"<<endl;
	return 0;
}

bool containsNegative(vector<int> a) {
	for(auto x: a) {
		if (x < 0) {
			return true;
		}
	}
	return false;
}
