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

template <class T>
ostream & operator << (ostream & os, vector <T> const& x) {
    os << "[ ";
    for(auto& y : x) os << y << " ";
    return os << "]";
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '%' || c == '/';
}

void solve() {

    string inp;
    getline(cin, inp);
    stack<char> st;
    inp = '(' + inp + ')';

    bool improper = false;
    bool error = false;
    int parPair = 0;
    int overallOperandCount = 0;
    int overallOperatorCount = 0;
    for (int i=0;i<inp.length();i++) {
        if (inp[i] == ' ') continue;
        if (inp[i] == ')') {
            parPair++;
            int operandCount = 0;
            int operatorCount = 0;
            while(!st.empty() && st.top() != '(') {
                // cout << "popping " << st.top() << endl;
                if (isOperator(st.top())) {
                    operatorCount++;
                } else if (st.top() != '(') {
                    operandCount++;
                }
                st.pop();
            }
            // cout << "opand Count " << operandCount << endl;
            // cout << "oper Count " << operatorCount << endl;
            if (st.empty() || operandCount != operatorCount+1) {
                // cout << "error? " << st.top() << endl;
                error = true;
                break;
            }
            if (operatorCount ==0 || operandCount ==0) {
                improper = true;
            }
            // popping (
            st.pop();
            st.push('t');
        } else {
            // cout << "adding " << inp[i] << endl;
            if (!isOperator(inp[i])) overallOperandCount++;
            else overallOperatorCount++;
            st.push(inp[i]);
        }
    }
    while (!st.empty()) {
        // cout << "rem " << st.top() << endl;
        // cout << "pop " << st.top() << endl;
        if (st.top() == '(' || st.top() == ')') error = true;
        st.pop();
    }
    // cout << "op count " << overallOperatorCount << endl;
    if (!st.empty() || error) {
        cout << "error" << endl;
    } else if (parPair != overallOperatorCount || improper) {
        cout << "improper" << endl;
    } else {
        cout << "proper" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

