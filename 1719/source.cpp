#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<pair<int, int>>> adj(n + 1);
	for (int i = 0; i != m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	for (int src = 1; src <= n; ++src) {
		vector<int> dist(n + 1, 987654321);
		vector<int> parent(n + 1, 0);
		vector<int> nextHop(n + 1, 0);
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, src });
		dist[src] = 0;
		while (!pq.empty()) {
			int d = -pq.top().first, here = pq.top().second;
			pq.pop();
			if (dist[here] < d)
				continue;
			for (auto& iter : adj[here]) {
				int there = iter.first, newDist = d + iter.second;
				if (dist[there] > newDist) {
					dist[there] = newDist;
					parent[there] = here;
					pq.push({ -newDist, there });
				}
			}
		}
		for (int dst = 1; dst <= n; ++dst) {
			for (int t = dst; t != src; t = parent[t])
				nextHop[dst] = t;
			if (nextHop[dst])
				printf("%d ", nextHop[dst]);
			else
				printf("- ");
		}
		printf("\n");
	}
}