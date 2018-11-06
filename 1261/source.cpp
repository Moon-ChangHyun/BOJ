#include<cstdio>
#include<list>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	vector<list<pair<int, int>>> adj(n * m);
	vector<int> dist(n * m, 987654321);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != m; ++j) {
			int x, node = i * m + j;
			scanf("%1d", &x);
			if (i > 0)
				adj[node - m].push_back({ node, x });
			if (j > 0)
				adj[node - 1].push_back({ node, x });
			if (i < n - 1)
				adj[node + m].push_back({ node, x });
			if (j < m - 1)
				adj[node + 1].push_back({ node, x });
		}
	}
	dist[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)
			continue;
		for (auto& iter : adj[here]) {
			int there = iter.first;
			int nextDist = cost + iter.second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ nextDist, there });
			}
		}
	}
	printf("%d", dist[m*n - 1]);
}