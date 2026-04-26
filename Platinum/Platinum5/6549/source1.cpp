// 56ms, 1628KB

#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	while (true) {
		int n;
		scanf("%d", &n);
		if (!n)
			break;
		vector<int> h(n+1);
		for (int i = 0; i != n; ++i)
			scanf("%d", &h[i]);
		h[n] = 0;
		stack<int> remaining;
		long long ret = 0;
		for (int i = 0; i <= n; ++i) {
			while (!remaining.empty() && h[remaining.top()] >= h[i]) {
				int j = remaining.top();
				remaining.pop();
				int width;
				if (remaining.empty())
					width = i;
				else
					width = (i - remaining.top() - 1);
				ret = max(ret, (long long)h[j] * (long long)width);
			}
			remaining.push(i);
		}
		printf("%lld\n", ret);
	}
}