#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
#define ll long long
using namespace std;

/*
 * Write a program that takes an array of n integers, where A[i] denotes the maximum reach from i
 * and determines if it's possible reach the last index from the beginning of the array.
 */

bool canReachEndOfArray(vector<int> a) {

	if (a == Null || a.size() <=0) {
		return true;
	}

	int max_reach = 0;

	for (int i=0; i<a.size();i++) {

		max_reach = max(max_reach, a[i] + i);
		if (max_reach >= a.size() -1) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<int> a;
	canReachEndOfArray(a);
	return 0;
}

