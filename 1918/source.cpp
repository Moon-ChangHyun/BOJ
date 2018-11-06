#include <iostream>
#include <stack>
#include <string>
#include <functional>
using namespace std;
std::string midToPost(const std::string& inStr) {
	function<int(char)> prec = [](char op) {
		switch (op) {
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		case '(':
		case ')':
			return 0;
		}
	};
	std::string ret;
	std::stack<char> s;
	char topOp;
	for (auto i : inStr) {
		switch (i) {
		case '*':
		case '/':
		case '+':
		case '-':
			while (!s.empty() && prec(i) <= prec(s.top())) {
				ret += s.top();
				s.pop();
			}
			s.push(i);
			break;
		case '(':
			s.push(i);
			break;
		case ')':
			while (true) {
				topOp = s.top();
				s.pop();
				if (topOp == '(')
					break;
				ret += topOp;
			}
			break;
		default:
			ret += i;
		}
	}
	while (!s.empty()) {
		ret += s.top();
		s.pop();
	}
	return ret;
}
int main() {
	string str;
	cin >> str;
	cout << midToPost(str) << endl;
}