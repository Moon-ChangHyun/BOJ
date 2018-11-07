#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
int main() {
	int n, m, x;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 0; i != n; ++i) {
		scanf("%d", &x);
		heap.push(x);
	}
	scanf("%d", &m);
	int p = 0;
	while (heap.size()) {
		if (m < heap.size() * (heap.top() - p))
			break;
		m -= heap.size() * (heap.top() - p);
		p = heap.top();
		heap.pop();
	}
	if (!heap.size())
		printf("%d", p);
	else
		printf("%d", p + m / heap.size());
}