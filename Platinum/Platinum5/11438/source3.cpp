// 192ms, 21704KB

#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int N, M, maxI;
vector<vector<int>> adj;
vector<vector<int>> parents;
vector<int> depth;

//깊이가 0이하인 가상의 노드 0번

void dfs(int node, int d) {
	depth[node] = d;
	for (auto next : adj[node]) {
		if (depth[next] != 0) continue;
		dfs(next, d + 1);
		parents[next][0] = node;
	}
}

int main() {
	scanf("%d", &N);
	maxI = ceil(log2(N));
	adj = vector<vector<int>>(N + 1);
	parents = vector<vector<int>>(N + 1, vector<int>(maxI + 1, 0));
	depth = vector<int>(N + 1, 0);
	for (int i = 1; i < N; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 1);
	for (int i = 1; i <= maxI; ++i) {
		for (int u = 1; u <= N; ++ u) {
			parents[u][i] = parents[parents[u][i - 1]][i - 1];
		}
	}
	for (scanf("%d", &M); ~--M; ) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (depth[u] > depth[v]) {
			swap(u, v);
		}
		for (int i = maxI; i >= 0; --i) {
			if (depth[u] <= depth[parents[v][i]])
				v = parents[v][i];
		}
		if (u != v) {
			for (int i = maxI; i >= 0; --i) {
				if (parents[u][i] != parents[v][i]) {
					u = parents[u][i];
					v = parents[v][i];
				}
			}
			u = parents[u][0];
		}
		printf("%d\n", u);
	}
}
