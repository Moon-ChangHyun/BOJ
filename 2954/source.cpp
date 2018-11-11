#include<string>
#include<iostream>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	int start = 0, idx;
	while (start < str.size()) {
		idx = str.find('p', start);
		if (idx == string::npos) break;
		if (idx != 0 && idx != str.size() - 1) {
			if (str[idx - 1] == str[idx + 1]) {
				switch (str[idx - 1]) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					str.erase(idx, 2);
				default:
					break;
				}
			}
		}
		start = idx + 1;
	}
	cout << str;
}