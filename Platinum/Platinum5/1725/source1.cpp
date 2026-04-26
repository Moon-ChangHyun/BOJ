// 16ms, 1884KB

#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main() {
	int n, ret = 0;
	scanf("%d", &n);
	vector<int> h(n + 1);
	for (int i = 0; i != n; ++i)
		scanf("%d", &h[i]);
    h[n] = 0;
	stack<int> remaining;
	for (int i = 0; i <= n; ++i) {
		while (!remaining.empty() && h[remaining.top()] >= h[i]) {
			int j = remaining.top();
			remaining.pop();
            int width = remaining.empty() ? i : i - remaining.top() - 1;
			ret = max(ret, h[j] * width);
		}
		remaining.push(i);
	}
	printf("%d", ret);
}