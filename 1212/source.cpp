#include<iostream>
#include<string>
using namespace std;
int main() {
	string num, ret;
	num.reserve(333334);
	ret.reserve(1000002);
	cin >> num;
	for (auto& iter : num) {
		switch (iter) {
		case '0':
			ret += "000";
			break;
		case '1':
			ret += "001";
			break;
		case '2':
			ret += "010";
			break;
		case '3':
			ret += "011";
			break;
		case '4':
			ret += "100";
			break;
		case '5':
			ret += "101";
			break;
		case '6':
			ret += "110";
			break;
		case '7':
			ret += "111";
		}
	}
	auto iter = ret.begin();
	while (iter != ret.end() && *iter == '0') ++iter;
	if (iter == ret.end())
		printf("0");
	else
		for (; iter != ret.end(); ++iter) printf("%c", *iter);
}