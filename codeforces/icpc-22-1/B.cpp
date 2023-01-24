#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#define mod 1000000007
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;


unordered_set<string> unique_perms;
unordered_set<int> unique_results;
vector<vector<int>> perms;
string op("+-*");

void generate_perms(int i, vi a) {

	if (i==a.size()-1) {
		string str;
		for (int j=0;j<a.size();j++) {
			str += (a[j] + '0');
		}
		unique_perms.insert(str);
		perms.push_back(a);
		return;
	}

	for (int j=i;j<a.size();j++) {

		int temp = a[j];
		a[j] = a[i];
		a[i] = temp;
		generate_perms(i+1, a);
	}
}

bool check(string s) {
	for (int i=0;i<s.length();i++){
		if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
			return true;
		}
	}
	return false;
}
int precedence(char c) {
	if (c=='*') {
		return 1;
	} else return 0;
}

int evaluate(string s) {

	stack<char> st;

	vector<string> postfix;

	for (int i=0;i<s.length();) {
		// cout << "considering " << s[i] << endl;
		if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
			if (!st.empty() && precedence(s[i]) > precedence(st.top())) {
				// cout << "inserting due to higher precedence" <<endl;
				st.push(s[i]);
			} else if (!st.empty()) {
				// cout << "detecting existing operator " << endl;
				while(!st.empty() && precedence(s[i]) <= precedence(st.top())) {
					string temp(1, st.top());
					postfix.push_back(temp);
					st.pop();
				}
				st.push(s[i]);
			} else {
				// string temp(1, s[i]);
				// cout << "inserting during empty" << temp <<endl;
				// cout << "inserting operator " << s[i] <<endl;
				st.push(s[i]);
			}
		} else {
				string temp;
				int j =i;
				while (j<s.length() && s[j] !='+' && s[j] !='-' && s[j] != '*') {
					temp.push_back(s[j]);
					j++;
				}
				postfix.push_back(temp);
				i+=temp.length();
				// cout << "inserting " << temp <<endl;
				// cout << "new i " << i <<endl;
				continue;
		}
		i++;
	}
	// pop and add remaining
	while(!st.empty()) {
		string temp(1, st.top());
		postfix.push_back(temp);
		st.pop();
	}


	// cout << "post" << endl;
	// for (int i =0;i<postfix.size();i++) {
	// 	cout << postfix[i] << " ";
	// }
	// cout << endl;
	stack<int> res;

	for(int i=0;i<postfix.size();i++) {
		if (postfix[i] == "+" || postfix[i] == "-" || postfix[i] == "*") {

			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			int result;
			if (postfix[i] == "+") {
				// cout << " adding " << a << " " << b << endl;
				result = a + b;
			} else if (postfix[i] == "-") {
				result = a-b;
			} else {
				result = a*b;
			}
			res.push(result);
		} else {
			res.push(stoi(postfix[i]));
		}
	}
	// cout << res.top() << endl;
	return res.top();
}

void generate_results(int i, string s) {

	if (i>=s.length()-1) {
		// convert string to numeric expression and evaluate;
		// take care of precedence
		if (check(s)) {

			int result = evaluate(s);
			if (result >=0) {
				// if (unique_results.find(result) == unique_results.end()) {
				// 	// cout << "result of " << s << " " << result <<  endl;
				// }
				unique_results.insert(result);
			}
			// cout << "result of " << s << " " << result <<  endl;
		}
		return;
	}

	// no op
	generate_results(i+1, s);

	for (int j=0;j<op.length();j++) {
		string temp = s;
		temp.insert(i+1, 1, op[j]);
		generate_results(i+2, temp);
	}
}

void solve() {

	vi a(4);
	cin >> a[0];
	cin >> a[1];
	cin >> a[2];
	cin >> a[3];
	// generate all permutations of 4 digits

	generate_perms(0, a);

	// cout << "printing all perms" <<endl;
	//
	// for (auto it = unique_perms.begin(); it != unique_perms.end();it++) {
	// 	cout << *it << endl;
	// }
	// for (int i=0;i<perms.size();i++) {
	// 	for (int j=0;j<perms[i].size();j++) {
	// 		cout << perms[i][j] <<" ";
	// 	}
	// 	cout << endl;
	// }

	// for each permutation, try to 
	//
	for (auto it = unique_perms.begin(); it != unique_perms.end();it++) {
		generate_results(0, *it);
	}
	cout << unique_results.size() << endl;
	// generate_results(0, "1121");
	// evaluate("1+1+1+2");
}

int main() {
	solve();
	return 0;
}

