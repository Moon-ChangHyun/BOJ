#include<stack>
#include<vector>
#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	stack<char> ls, rs;
	char c;
	cin.unsetf(ios::skipws);
	while (true) {
		cin >> c;
		if (c == '\n') break;
		ls.push(c);
	}
	cin.setf(ios::skipws);
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i) {
		cin >> c;
		switch (c) {
		case 'L':
			if (!ls.empty()) {
				rs.push(ls.top());
				ls.pop();
			}
			break;
		case 'D':
			if (!rs.empty()) {
				ls.push(rs.top());
				rs.pop();
			}
			break;
		case 'B':
			if (!ls.empty())
				ls.pop();
			break;
		case 'P':
			cin >> c;
			ls.push(c);
		}
	}
	vector<char> lv(ls.size());
	int i = -1;
	while (!ls.empty()) {
		lv[++i] = ls.top();
		ls.pop();
	}
	for (auto rIter = lv.rbegin(); rIter != lv.rend(); ++rIter)
		cout << *rIter;
	while (!rs.empty()) {
		cout << rs.top();
		rs.pop();
	}
}