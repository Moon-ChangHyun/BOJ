#include<iostream>
#include<regex>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	regex r("^(100+1+|01)+$");
	int T;
	for (cin >> T; ~--T; ) {
		string s;
		cin >> s;
		cout << (regex_match(s, r) ? "YES" : "NO") << '\n';
	}
}