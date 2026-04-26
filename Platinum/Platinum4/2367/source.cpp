// 60ms, 1940KB

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int V, N, K, D;
int limitCook[100];
int flow[302][302], capacity[302][302];
int main() {
	scanf("%d%d%d", &N, &K, &D);
	V = N + D + 2;
	for (int i = 1; i <= N; ++i)
		capacity[0][i] = K;
	for (int i = 1; i <= D; ++i)
		scanf("%d", &capacity[N + i][V - 1]);
	for (int i = 1; i <= N; ++i) {
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; ++j) {
			int y;
			scanf("%d", &y);
			y += N;
			capacity[i][y] = 1;
		}
	}
	int totalFlow = 0;
	while (true) {
		vector<int> parent(V, -1);
		queue<int> q;
		parent[0] = 0;
		q.push(0);
		while (!q.empty() && parent[V - 1] == -1) {
			int here = q.front(); q.pop();
			for(int there = 0; there < V; ++there)
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
		}
		if (parent[V - 1] == -1) break;
		for (int p = V - 1; p != 0; p = parent[p]) {
			++flow[parent[p]][p];
			--flow[p][parent[p]];
		}
		++totalFlow;
	}
	printf("%d", totalFlow);
}