// 120ms, 7352KB

#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int n;
	long long ret = 0;
	scanf("%d", &n);
	vector<int> h(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &h[i]);
	stack <pair<int, int>> st1;
	for (int i = 0; i != n; ++i) {
		while (!st1.empty() && h[st1.top().first] < h[i]) {
			int cnt = st1.top().second;
			st1.pop();
			ret += (long long)cnt * (cnt + 1) / 2;
		}
		if (!st1.empty() && h[st1.top().first] == h[i])
		{
			++st1.top().second;
		}
		else
			st1.push({ i, 1 });
	}
	while (!st1.empty()) {
		auto p = st1.top(); st1.pop();
		if (p.second > 1)
			ret += (long long)p.second * (p.second - 1) / 2;
	}
	stack<int> st2;
	for (int i = n; ~--i;) {
		while (!st2.empty() && h[st2.top()] < h[i]) {
			++ret;
			st2.pop();
		}
		st2.push(i);
	}
	printf("%lld", ret);
}