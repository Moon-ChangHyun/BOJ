#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	int tmp, sum = 0;
	string s;
	cin >> s;
	stack<int> st;
	for (auto iter : s) {
		switch (iter) {
		case '(':
			st.push(-1);
			break;
		case ')':
			sum = 0;
			while (true) {
				if (st.empty())
					return !printf("0");
				tmp = st.top(); st.pop();
				if (tmp == -3)
					return !printf("0");
				if (tmp == -1) {
					st.push(sum == 0 ? 2 : (sum << 1));
					break;
				}
				sum += tmp;
			}
			break;
		case '[':
			st.push(-3);
			break;
		case ']':
			sum = 0;
			while (true) {
				if (st.empty())
					return !printf("0");
				tmp = st.top(); st.pop();
				if (tmp == -1)
					return !printf("0");
				if (tmp == -3) {
					st.push(sum == 0 ? 3 : sum * 3);
					break;
				}
				sum += tmp;
			}
			break;
		}
	}
	int ret = 0;
	while (!st.empty()) {
		int x = st.top(); st.pop();
		if (x < 0)
			return !printf("0");
		ret += x;
	}
	printf("%d", ret);
}