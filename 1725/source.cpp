#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> h(n);
	for (int i = 0; i != n; ++i)
		scanf("%d", &h[i]);
	stack<int> remaining;
	h.push_back(0);
	int ret = 0;
	for (int i = 0; i <= n; ++i) {
		while (!remaining.empty() && h[remaining.top()] >= h[i]) {
			int j = remaining.top();
			remaining.pop();
			int width;
			if (remaining.empty())
				width = i;
			else
				width = (i - remaining.top() - 1);
			ret = max(ret, h[j] * width);
		}
		remaining.push(i);
	}
	printf("%d", ret);
}