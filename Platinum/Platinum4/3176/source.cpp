// 316ms, 39700KB

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
int N, K, maxI;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> parents;
vector<vector<int>> minRoad;
vector<vector<int>> maxRoad;
vector<int> depth;

void dfs(int node, int d) {
	depth[node] = d;
	for (auto next : adj[node]) {
		if (depth[next.first] != 0) continue;
		dfs(next.first, d + 1);
		parents[next.first][0] = node;
		minRoad[next.first][0] = next.second;
		maxRoad[next.first][0] = next.second;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
	maxI = ceil(log2(N));
	adj = vector<vector<pair<int, int>>>(N + 1);
	parents = vector<vector<int>>(N + 1, vector<int>(maxI + 1, 0));
	minRoad = vector<vector<int>>(N + 1, vector<int>(maxI + 1, 0));
	maxRoad = vector<vector<int>>(N + 1, vector<int>(maxI + 1, 0));
	depth = vector<int>(N + 1, 0);
	for (int i = 1; i < N; ++i) {
		int u, v, c;
        cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dfs(1, 1);
	for (int i = 1; i <= maxI; ++i) {
		for (int u = 1; u <= N; ++ u) {
			parents[u][i] = parents[parents[u][i - 1]][i - 1];
			minRoad[u][i] = min(minRoad[u][i - 1], minRoad[parents[u][i - 1]][i - 1]);
			maxRoad[u][i] = max(maxRoad[u][i - 1], maxRoad[parents[u][i - 1]][i - 1]);
		}
	}
	for (cin >> K; ~--K; ) {
		int u, v;
		pair<int, int> output {1000001, 0};
		cin >> u >> v;
		if (depth[u] > depth[v]) {
			swap(u, v);
		}
		for (int i = maxI; i >= 0; --i) {
			if (depth[u] <= depth[parents[v][i]]) {
				output.first = min(output.first, minRoad[v][i]);
				output.second = max(output.second, maxRoad[v][i]);
				v = parents[v][i];	
			}
		}
		if (u != v) {
			for (int i = maxI; i >= 0; --i) {
				if (parents[u][i] != parents[v][i]) {
					output.first = min({output.first, minRoad[u][i], minRoad[v][i]});
					output.second = max({output.second, maxRoad[u][i], maxRoad[v][i]});
					u = parents[u][i];
					v = parents[v][i];
				}
			}
			output.first = min({output.first, minRoad[u][0], minRoad[v][0]});
			output.second = max({output.second, maxRoad[u][0], maxRoad[v][0]});
			u = parents[u][0];
		}
        cout << output.first << ' ' << output.second << '\n';
	}
}