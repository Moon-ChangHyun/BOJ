#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<int> dist;
vector<vector<bool>> map;
int n, m, last;
int main() {
	char c;
	scanf("%d%d", &n, &m);
	last = n * m - 1;
	adj.resize(last + 1);
	map.resize(n, vector<bool>(m, false));
	dist.resize(last + 1, 987654321);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != m; ++j) {
			scanf(" %c", &c);
			if (c - '0') map[i][j] = true;
		}
	}
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != m; ++j) {
			if (!map[i][j])
				continue;
			int node = i * m + j;
			if (i && map[i - 1][j])
				adj[node].push_back(node - m);
			if (j && map[i][j - 1])
				adj[node].push_back(node - 1);
			if (i != n - 1 && map[i + 1][j])
				adj[node].push_back(node + m);
			if (j != m - 1 && map[i][j + 1])
				adj[node].push_back(node + 1);
		}
	}
	queue<int> q;
	q.push(0);
	dist[0] = 1;
	while (dist[last] == 987654321) {
		int cur = q.front();
		q.pop();
		for (auto& iter : adj[cur]) {
			if (dist[iter] != 987654321)
				continue;
			q.push(iter);
			dist[iter] = dist[cur] + 1;
		}
	}
	printf("%d", dist[last]);
}