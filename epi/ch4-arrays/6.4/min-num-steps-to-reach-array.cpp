#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
#define ll long long
using namespace std;

/*
 * Write a program that takes an array of n integers, where A[i] denotes the maximum reach from i
 * and returns the minimum number of steps required to reach the end of the array.
 *
 * solution source: https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
 */

bool canReachEndOfArray(vector<int> a) {

	if (a == NULL || a.size() <=0) {
		return 0;
	}

	int max_reach_so_far = a[0]; // furthest index we can reach right now.
	int jump = 1; // jump indicates the current jump in process.

	int steps = a[0]; // indicates the number of steps required to reach max_reach_so_far
	for (int i=1; i<a.size();i++) {

		max_reach_so_far = Math.max(max_reach_so_far, a[i] + i);
		if (max_reach_so_far >= a.size() -1) {
			return ++jump;
		}

		steps--;
		if (steps == 0) {
			jump++;

			if (i>=max_reach_so_far) {
				// no path to end;
				return -1;
			}
			steps = max_reach_so_far - i;
		}
	}
	return jump;
}

int main() {
	vector<int> a;
	canReachEndOfArray(a);
	return 0;
}

