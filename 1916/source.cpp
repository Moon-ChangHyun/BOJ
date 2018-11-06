#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> adj(N + 1);
	vector<int> dist(N + 1, 987654321);
	for (int i = 0; i != M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
	int src, dst;
	cin >> src >> dst;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, src });
	dist[src] = 0;
	while (true) {
		int cur = pq.top().second, cost = -pq.top().first;
		pq.pop();
		if (cur == dst) break;
		if (dist[cur] > cost) continue;
		for (auto& next : adj[cur]) {
			int nextNode = next.first, nextCost = cost + next.second;
			if (nextCost < dist[nextNode]) {
				dist[nextNode] = nextCost;
				pq.push({ -nextCost, nextNode });
			}
		}
	}
	cout << dist[dst];
}