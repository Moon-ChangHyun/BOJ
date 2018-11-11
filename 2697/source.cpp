#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	for (cin >> t; ~--t; ) {
		string s;
		cin >> s;
		if (!next_permutation(s.begin(), s.end()))
			cout << "BIGGEST\n";
		else
			cout << s << '\n';
	}
}