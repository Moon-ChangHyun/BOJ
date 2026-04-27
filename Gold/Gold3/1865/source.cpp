// 16ms, 1228KB

#include<cstdio>
#include<vector>
using namespace std;

constexpr int INF = 987654321;

int main() {
	int T;
	for (scanf("%d", &T); ~--T;) {
		int N, M, W;
		scanf("%d%d%d", &N, &M, &W);
		vector<vector<pair<int, int>>> adj(N + 1);
		for (int i = 0; i != M; ++i) {
			int src, dst, weight;
			scanf("%d%d%d", &src, &dst, &weight);
			adj[src].push_back({ dst, weight });
			adj[dst].push_back({ src, weight });
		}
		for (int i = 0; i != W; ++i) {
			int src, dst, weight;
			scanf("%d%d%d", &src, &dst, &weight);
			adj[src].push_back({ dst, -weight });
		}
		bool update;
		vector<int> dist(N + 1, INF);
		dist[1] = 0;
		for (int k = 0; k != N; ++k) {
			update = false;
			for (int u = 1; u <= N; ++u) {
				for (auto& v : adj[u]) {
					if (dist[v.first] > dist[u] + v.second) {
						update = true;
						dist[v.first] = dist[u] + v.second;
					}
				}
			}
			if (!update)
				break;
		}
		printf("%s\n", update ? "YES" : "NO");
	}
}