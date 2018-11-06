#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, E;
vector<vector<pair<int, int>>> adj;

int dijkstra(int start, int end) {
	priority_queue<pair<int, int>> pq; // -거리, 정점
	vector<int> dist(N + 1, 987654321);
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int dst = -pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (vertex == end)
			break;
		if (dist[vertex] < dst)
			continue;
		for (auto& iter : adj[vertex]) {
			int nextDst = iter.second + dst;
			int nextVertex = iter.first;
			if (dist[nextVertex] > nextDst) {
				dist[nextVertex] = nextDst;
				pq.push({ -nextDst, nextVertex });
			}
		}
	}
	return dist[end];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> E;
	adj.resize(N + 1);
	for (int i = 0; i != E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	int viaPointA, viaPointB;
	cin >> viaPointA >> viaPointB;
	long long retA = (long long)dijkstra(1, viaPointA) + dijkstra(viaPointA, viaPointB) + dijkstra(viaPointB, N);
	long long retB = (long long)dijkstra(1, viaPointB) + dijkstra(viaPointB, viaPointA) + dijkstra(viaPointA, N);
	if (retA > 987654321 && retB > 987654321)
		cout << -1;
	else
		cout << min(retA, retB);
}