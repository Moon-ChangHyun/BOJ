// 96ms, 8440KB

#include<cstdio>
#include<functional>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> enegy(n + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &enegy[i]);
	vector<vector<pair<int, int>>> adj(n + 1);
	for (int i = 1; i != n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	vector<pair<int, int>> parent(n + 1);
	vector<bool> visited(n + 1, false);
	parent[1] = { 1, 0 };
	function<void(int)> dfs = [&](int node) {
		visited[node] = true;
		for (auto& iter : adj[node]) {
			if (!visited[iter.first]) {
				parent[iter.first] = { node, iter.second };
				dfs(iter.first);
			}
		}
	};
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		int pos = i;
		while (pos != 1 && enegy[i] >= parent[pos].second) {
			enegy[i] -= parent[pos].second;
			pos = parent[pos].first;
		}
		printf("%d\n", pos);
	}
}