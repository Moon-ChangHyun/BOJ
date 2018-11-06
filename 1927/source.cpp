#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
int main() {
	int n, x;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		scanf("%d", &x);
		if (!x) {
			if (minHeap.empty()) printf("0\n");
			else {
				printf("%d\n", minHeap.top());
				minHeap.pop();
			}
		}
		else
			minHeap.push(x);
	}
}