#include<cstdio>
#include<queue>
#include<map>
using namespace std;

long long goal = 2271560481LL;

int main() {
	long long start = 0;
	for (int idx = 0; idx != 9; ++idx) {
		long long x;
		scanf("%lld", &x);
		start |= (x << (idx << 2));
	}
	if (start == goal) {
		printf("0");
		return 0;
	}
	map<long long, int> dist;
	queue<long long> q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		long long cur = q.front(); q.pop();
		vector<long long> adj;
		adj.reserve(4);
		for (int idx = 0; idx != 9; ++idx) {
			int i = idx / 3;
			int j = idx % 3;
			long long next, toSwap;
			if (!(cur & (0xFLL << (idx << 2)))) {
				if (i) {
					next = cur;
					toSwap = 0xFLL & (cur >> ((idx - 3) << 2));
					next &= ~(0xFLL << ((idx - 3) << 2));
					next |= (toSwap << (idx << 2));
					adj.push_back(next);
				}
				if (j) {
					next = cur;
					toSwap = 0xFLL & (cur >> ((idx - 1) << 2));
					next &= ~(0xFLL << ((idx - 1) << 2));
					next |= (toSwap << (idx << 2));
					adj.push_back(next);
				}
				if (i < 2) {
					next = cur;
					toSwap = 0xFLL & (cur >> ((idx + 3) << 2));
					next &= ~(0xFLL << ((idx + 3) << 2));
					next |= (toSwap << (idx << 2));
					adj.push_back(next);
				}
				if (j < 2) {
					next = cur;
					toSwap = 0xFLL & (cur >> ((idx + 1) << 2));
					next &= ~(0xFLL << ((idx + 1) << 2));
					next |= (toSwap << (idx << 2));
					adj.push_back(next);
				}
				break;
			}
		}
		for (auto& next : adj) {
			if (dist.count(next) == 0) {
				q.push(next);
				dist[next] = dist[cur] + 1;
				if (next == goal) {
					printf("%d", dist[goal]);
					return 0;
				}
			}
		}
	}
	printf("-1");
}