#include<string>
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	switch (str.size() % 3) {
	case 1:
		str = '0' + str;
	case 2:
		str = '0' + str;
	}
	for (int i = 0; str[i]; i += 3) {
		int num = 0;
		if (str[i] == '1') num += 4;
		if (str[i + 1] == '1') num += 2;
		if (str[i + 2] == '1') num += 1;
		cout << num;
	}
}