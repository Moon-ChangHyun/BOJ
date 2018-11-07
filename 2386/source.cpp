#include<iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	while (true) {
		int cnt = 0;
		char c;
		cin >> c;
		if (c == '#') break;
		getline(cin, str);
		for (auto iter : str) {
			if (iter >= 'A' && iter <= 'Z') iter += 32;
			if (iter == c) ++cnt;
		}
		cout << c << ' ' << cnt << '\n';
	}
}