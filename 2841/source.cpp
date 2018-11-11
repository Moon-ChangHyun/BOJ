#include<stack>
#include<array>
#include<cstdio>
using namespace std;
int main() {
	int n, p, ret = 0;
	scanf("%d%d", &n, &p);
	array<stack<int>, 6> gt;
	for (int i = 0; i != n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		while (!gt[a - 1].empty() && gt[a - 1].top() > b) {
			gt[a - 1].pop();
			++ret;
		}
		if (gt[a - 1].empty() || gt[a - 1].top() != b) {
			gt[a - 1].push(b);
			++ret;
		}
	}
	printf("%d", ret);
}
