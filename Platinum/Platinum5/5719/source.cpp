// 56ms, 2160KB

#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main() {
	while (true) {
		int N, M, S, D;
		scanf("%d%d", &N, &M);
		if (N + M == 0)
			break;
		vector<int> edgeLength(M);
		vector<vector<pair<int, int>>> adj(N); // node, edgeNum
		scanf("%d%d", &S, &D);
		for (int i = 0; i < M; ++i) {
			int U, V, P;
			scanf("%d%d%d", &U, &V, &P);
			adj[U].push_back({ V, i });
			edgeLength[i] = P;
		}
		vector<vector<pair<int, int>>> parents(N); // S->D로 가는 최단경로상의 부모들
		vector<int> dist(N, 987654321);
		dist[S] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, S });
		while (!pq.empty()) {
			int pathLen = -pq.top().first;
			int node = pq.top().second;
			pq.pop();
			if (dist[node] < pathLen)
				continue;
			for (auto& next : adj[node]) {
				int nextLen = pathLen + edgeLength[next.second];
				if (dist[next.first] < nextLen)
					continue;
				if (dist[next.first] > nextLen) {
					pq.push({ -nextLen, next.first });
					dist[next.first] = nextLen;
					parents[next.first].clear();
				}
				parents[next.first].push_back({ node, next.second }); //node, edgeNum
			}
		}

		//disable edges
		queue<int> q;
		q.push(D);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto& p : parents[cur]) {
				if (edgeLength[p.second] == -1) continue;
				edgeLength[p.second] = -1;
				q.push(p.first);
			}
		}

		for (auto& d : dist)
			d = 987654321;
		dist[S] = 0;
		pq.push({ 0, S });
		while (!pq.empty()) {
			int pathLen = -pq.top().first;
			int node = pq.top().second;
			pq.pop();
			if (dist[node] < pathLen)
				continue;
			for (auto& next : adj[node]) {
				if (edgeLength[next.second] == -1) continue;
				int nextLen = pathLen + edgeLength[next.second];
				if (dist[next.first] <= nextLen)
					continue;
				dist[next.first] = nextLen;
				pq.push({ -nextLen, next.first });
			}
		}

		printf("%d\n", dist[D] >= 987654321 ? -1 : dist[D]);
	}
}