#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int b, ret = 0, mul;
	cin >> b;
	mul = 1;
	for (int idx = str.size(); ~--idx; ) {
		ret += mul * [](char c) {
			if (c >= 'A') return c - 'A' + 10;
			return c - '0';
		}(str[idx]);
		mul *= b;
	}
	cout << ret;
}