#include<iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	string str;
	for (getline(cin, str); ~--T; ) {
		string table;
		getline(cin, str);
		getline(cin, table);
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == ' ') {
				cout << ' ';
				continue;
			}
			cout << table[str[i] - 'A'];
		}
		cout << '\n';
	}
}