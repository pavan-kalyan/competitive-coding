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
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}

void solve() {

    string s;
    cin >>s;
    //reverse
    // for (int i=0;i<s.length()/2;i++) {
    //     char c = s[i];
    //     s[i] = s[s.length()-i-1];
    //     s[s.length()-i-1] = c;
    // }
    ll denom=1;
    ll sum = s[0]-'0';
    for (int i=1;i<s.length();i++) {
        sum = sum*3;
        denom = denom*2;
        ll temp = gcd<ll>(sum, denom);
        denom = denom/ temp;
        sum = sum/ temp;
        sum += (s[i] -'0')*(denom);
    }

    if (denom == 1) {
        cout << sum << endl;
        return;
    }
    cout << sum/denom << " " << sum % denom <<"/"<< denom<< endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    solve();
    return 0;
}

