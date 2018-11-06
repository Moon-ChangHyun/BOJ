#include<cstdio>
#include<queue>
using namespace std;
int main() {
	int T;
	for (scanf("%d", &T); ~--T;) {
		int n, m;
		scanf("%d%d", &n, &m);
		queue<pair<int, int>> q; // 문서번호, 중요도
		priority_queue<int> pq;
		for (int i = 0; i != n; ++i) {
			int x;
			scanf("%d", &x);
			q.push({ i, x });
			pq.push(x);
		}
		int ret = 1;
		while (true) {
			auto item = q.front();
			q.pop();
			if (item.second == pq.top()) {
				pq.pop();
				if (item.first == m) {
					printf("%d\n", ret);
					break;
				}
				++ret;
			}
			else {
				q.push(move(item));
			}
		}
	}
}