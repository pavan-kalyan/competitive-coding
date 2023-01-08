#include<bits/stdc++.h>
#include<iostream>
#define mod 1000000007
#define ll long long
using namespace std;

/*
 *
 * Delete duplicates from a sorted array. no specific requirements on the elements after the final array.
 *
 * returns length of the new array.
 */

int deleteDuplicates(vector<int> a) {

	int left =1; //start from second character

	//move left to first duplicate character. Everything to the left of left is pure (no duplicates)
	while (left < a.size() && a[left-1] != a[left]) {
		left++;
	}
	int right = left + 1;
	while (right < a.size()) {
		//skip duplicates
		while (right < a.size() && a[right] == a[left]) {
			right++;
		}
		a[left] = a[right];
		left++;
		right++;
	}

	return left;
}

int main() {
	return 0;
}


int deleteKey(vector<int> a, int key) {

	int write_index = 0;

	int i=0;
	for(int i=0; i<a.size();i++) {

		if (a[i] == key) {
			continue;
		}
		a[write_index] = a[i];
		write_index++;
	}
	return write_index;
}
