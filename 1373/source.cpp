#include<iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int i = s.size() % 3;
	if (i == 1) cout << (s[0] - '0');
	else if (i == 2) cout << ((s[0] - '0') << 1) + (s[1] - '0');
	while (s.size() > i) {
		cout << (((s[i] - '0') << 2) + ((s[i + 1] - '0') << 1) + (s[i + 2] - '0'));
		i += 3;
	}
}