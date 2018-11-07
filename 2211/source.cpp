#include<queue>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> adj;
vector<int> dist, parent;
int main() {
	scanf("%d%d", &N, &M);
	adj.resize(N + 1);
	dist.resize(N + 1, 987654321);
	parent.resize(N + 1, 0);
	for (int i = 0; i != M; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curDist = -pq.top().first;
		pq.pop();
		if (dist[curNode] < curDist) continue;
		for (auto& it : adj[curNode]) {
			int nextNode = it.first;
			int nextDist = curDist + it.second;
			if (dist[nextNode] > nextDist) {
				pq.push({ -nextDist, nextNode });
				dist[nextNode] = nextDist;
				parent[nextNode] = curNode;
			}
		}
	}
	vector<vector<bool>> usingEdge(N + 1, vector<bool>(N + 1, false));
	for (int i = 2; i <= N; ++i) {
		for (int x = i; x != 1; x = parent[x]) {
			usingEdge[x][parent[x]] = true;
			usingEdge[parent[x]][x] = true;
		}
	}
	vector<pair<int, int>> ret;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j < i; ++j) {
			if (usingEdge[i][j])
				ret.push_back({ i, j });
		}
	}
	printf("%d\n", ret.size());
	for (auto& it : ret)
		printf("%d %d\n", it.first, it.second);
}