#include<cstdio>
#include<list>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int main() {
	int v, e, k;
	scanf("%d%d%d", &v, &e, &k);
	vector<list<pair<int, int>>> adj(v + 1);//{정점, 가중치}
	for (int i = 0; i != e; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ v, w });
	}
	vector<int> dist(v + 1, 987654321);
	dist[k] = 0;
	priority_queue<pair<int, int >, vector<pair<int, int>>, greater<>> pq;//{가중치, 정점}
	pq.push({ 0, k });
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
	for (auto iter = dist.begin() + 1; iter != dist.end(); ++iter) {
		if (*iter >= 987654321)
			printf("INF\n");
		else
			printf("%d\n", *iter);
	}
}