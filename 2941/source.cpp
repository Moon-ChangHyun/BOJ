#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ret = s.size();
	for (int i = 0; i != s.size(); ++i) {
		switch (s[i]) {
		case '=':
			if (i > 1 && s[i - 1] == 'z' && s[i - 2] == 'd')
				--ret;
			--ret;
			break;
		case '-':
			--ret;
			break;
		case 'j':
			if (i && (s[i - 1] == 'l' || s[i - 1] == 'n'))
				--ret;
			break;
		default:
			break;
		}
	}
	cout << ret;
}