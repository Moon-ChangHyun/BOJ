#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	cin >> str;
	bool clear = true;
	int start = 0;
	while (true) {
		int idx = str.find('.', start);
		if (idx == string::npos) {
			if ((str.size() - start) & 1)
				clear = false;
			else {
				int a = (str.size() - start) / 4;
				a *= 4;
				for (int i = start; i < start + a; ++i)
					str[i] = 'A';
				for (int i = start + a; i < str.size(); ++i)
					str[i] = 'B';
			}
			break;
		}
		if ((idx - start) & 1) {
			clear = false;
			break;
		}
		int a = (idx - start) / 4;
		a *= 4;
		for (int i = start; i < start + a; ++i)
			str[i] = 'A';
		for (int i = start + a; i < idx; ++i)
			str[i] = 'B';
		start = idx;
		idx = str.find('X', start);
		if (idx == string::npos)
			break;
		start = idx;
	}
	if (clear)
		cout << str;
	else
		cout << "-1";
}