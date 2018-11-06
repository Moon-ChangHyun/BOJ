#include<cstdio>
#include<list>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

void dijkstra(int src, vector<list<pair<int, int>>>& adj, vector<int>& dist) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, src });
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
}

int main() {
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	vector<list<pair<int, int>>> adj1(n + 1), adj2(n + 1);
	vector<int> dist1(n + 1, 987654321), dist2(n + 1, 987654321);
	for (int i = 0; i != m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj1[v].push_back({ u, w });
		adj2[u].push_back({ v, w });
	}
	dist1[x] = dist2[x] = 0;
	dijkstra(x, adj1, dist1);
	dijkstra(x, adj2, dist2);
	int ret = 0;
	for (int i = 1; i <= n; ++i)
		ret = max(ret, dist1[i] + dist2[i]);
	printf("%d", ret);
}