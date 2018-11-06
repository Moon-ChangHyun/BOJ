#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	vector<char> str;
	for (int i = 0; i != n; ++i)
		scanf("%d", &v[i]);
	stack<int> s;
	int next = 1;
	for (auto& iter : v) {
		if (iter < next) {
			if (s.top() != iter)
				break;
			s.pop();
			str.push_back('-');
		}
		else {
			while (next < iter) {
				s.push(next++);
				str.push_back('+');
			}
			++next;
			str.push_back('+');
			str.push_back('-');
		}
	}
	if (s.empty()) {
		for (auto& op : str)
			printf("%c\n", op);
	}
	else {
		printf("NO");
	}
}