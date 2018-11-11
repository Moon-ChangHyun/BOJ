#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	for (cin >> t; ~--t; ) {
		string str1, str2, ret;
		cin >> str1 >> str2;
		int idx = str1.find('1');
		if (idx == string::npos) str1 = "0";
		else str1 = str1.substr(idx);
		idx = str2.find('1');
		if (idx == string::npos) str2 = "0";
		else str2 = str2.substr(idx);
		if (str1.size() < str2.size())
			swap(str1, str2);
		int l1 = str1.size();
		int l2 = str2.size();
		int i, carry = 0;
		for (i = 0; i != l2; ++i) {
			int n1 = str1[l1 - 1 - i] & 15;
			int n2 = str2[l2 - 1 - i] & 15;
			int sum = carry + n1 + n2;
			carry = (sum >> 1);
			ret += '0' + (sum % 2);
		}
		for (; i != l1; ++i) {
			int sum = carry + str1[l1 - 1 - i] & 15;
			carry = (sum >> 1);
			ret += '0' + (sum % 2);
		}
		if (carry)
			ret += '1';
		for (auto rIter = ret.rbegin(); rIter != ret.rend(); ++rIter)
			cout << *rIter;
		cout << '\n';
	}
}